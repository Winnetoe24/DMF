package semantic_rules

import (
	"errors"
	tree_sitter_dmf "github.com/Winnetoe24/DMF/grammar/dmf_language"
	sematic_model "github.com/Winnetoe24/DMF/semantic/semantic-parse"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	err_element "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"sync"
)

const (
	ERROR_AFTER_TREE_SITTER_PARSER = 1
	ERROR_AFTER_SEMANTIC_PARSE     = 2
)

func ParseNewFile(fileContent string, afterParse chan<- *tree_sitter.Tree, afterSematicModel chan<- *smodel.Model, sync bool) ([]err_element.ErrorElement, int, error) {

	tree, err := callTreeSitterParser(fileContent)
	if err != nil {
		return nil, ERROR_AFTER_TREE_SITTER_PARSER, err
	}
	go func() {
		afterParse <- tree
	}()

	parsedModel, errorElementsModel, err := sematic_model.Parse([]byte(fileContent), tree)
	if err != nil {
		return nil, ERROR_AFTER_SEMANTIC_PARSE, err
	}
	go func() {
		afterSematicModel <- &parsedModel
	}()

	var errorElements []err_element.ErrorElement

	if sync {
		errorElements = runRulesSync([]byte(fileContent), &parsedModel)
	} else {
		errorElements = runRules([]byte(fileContent), &parsedModel)
	}
	errorElements = append(errorElements, errorElementsModel...)
	return errorElements, 0, nil
}

func callTreeSitterParser(fileContent string) (*tree_sitter.Tree, error) {
	language := tree_sitter.NewLanguage(tree_sitter_dmf.Language())
	if language == nil {
		return nil, errors.New("language is nil")
	}

	parser := tree_sitter.NewParser()
	err := parser.SetLanguage(language)
	if err != nil {
		return nil, err
	}
	parse := parser.Parse([]byte(fileContent), nil)
	return parse, nil
}

type semanticRule[E any, R any] interface {
	SemanticRule(fileContent []byte, model *smodel.Model, extra E) ([]err_element.ErrorElement, R)
}

type TypeLookUp map[string]packages.PackageElement

type TypeNodeLookup map[string]base.TypeNode

var _ ITypeLookUp = (TypeLookUp)(nil)

func (t TypeLookUp) getTypeLookUp() TypeLookUp {
	return t
}

type ITypeLookUp interface {
	getTypeLookUp() TypeLookUp
}

func runRules(fileContent []byte, model *smodel.Model) []err_element.ErrorElement {
	var err []err_element.ErrorElement
	ret := make(chan []err_element.ErrorElement, 2)
	group := sync.WaitGroup{}
	groupRet := sync.WaitGroup{}
	groupRet.Add(1)
	go func() {
		for {
			neu, more := <-ret
			if more {
				err = append(err, neu...)
			} else {
				break
			}
			//log.Printf("Read\n")
		}
		groupRet.Done()

	}()
	//typeLookUpChan := make(chan TypeLookUp)
	startRule(fileContent, &group, model, &duplicatePathRule{}, nil, ret, nil)
	//typeLookUp := <-typeLookUpChan
	//_ = <-typeLookUpChan
	//close(typeLookUpChan)
	group.Wait()
	close(ret)

	groupRet.Wait()
	return err
}
func startRule[E *any, T any](fileContent []byte, group *sync.WaitGroup, model *smodel.Model, rule semanticRule[E, T], extra *chan E, ret chan<- []err_element.ErrorElement, result *chan T) {
	group.Add(1)
	go func() {
		var e E = nil
		if extra != nil {
			e = <-*extra
		}
		elements, t := rule.SemanticRule(fileContent, model, e)
		ret <- elements
		if result != nil {
			*result <- t
		}
		group.Done()
	}()
}
func runRulesSync(fileContent []byte, model *smodel.Model) []err_element.ErrorElement {
	var err []err_element.ErrorElement
	duplicatePathRule := &duplicatePathRule{}
	newErr, lookUp := duplicatePathRule.SemanticRule(fileContent, model, nil)
	err = append(err, newErr...)

	newErr, _ = (&modelWithTypesWalker{
		handler: []walkModelWithTypes{
			&checkSuperTypes{
				nodeLookup: make(TypeNodeLookup),
			},
			&checkEnumConstants{},
			&checkEntityIdentifier{},
		},
	}).SemanticRule(fileContent, model, lookUp)
	err = append(err, newErr...)
	return err
}
