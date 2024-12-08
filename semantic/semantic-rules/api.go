package semantic_rules

import (
	"errors"
	tree_sitter_dmf "github.com/Winnetoe24/DMF/grammar/dmf_language"
	sematic_model "github.com/Winnetoe24/DMF/semantic/semantic-parse"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	err_element "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

const (
	ERROR_AFTER_TREE_SITTER_PARSER = 1
	ERROR_AFTER_SEMANTIC_PARSE     = 2
)

func ParseNewFile(fileContent string, afterParse chan<- *tree_sitter.Tree, afterSematicModel chan<- *smodel.Model) ([]err_element.ErrorElement, int, error, smodel.TypeLookUp) {

	tree, err := callTreeSitterParser(fileContent)
	if err != nil {
		return nil, ERROR_AFTER_TREE_SITTER_PARSER, err, nil
	}
	go func() {
		afterParse <- tree
	}()

	parsedModel, errorElementsModel, err := sematic_model.Parse([]byte(fileContent), tree)
	if err != nil {
		return nil, ERROR_AFTER_SEMANTIC_PARSE, err, nil
	}
	go func() {
		afterSematicModel <- &parsedModel
	}()

	var errorElements []err_element.ErrorElement

	var lookup smodel.TypeLookUp
	errorElements, lookup = runRulesSync(&parsedModel)

	errorElements = append(errorElements, errorElementsModel...)
	return errorElements, 0, nil, lookup
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

var _ ITypeLookUp = (smodel.TypeLookUp)(nil)

type ITypeLookUp interface {
	GetTypeLookUp() smodel.TypeLookUp
}

func runRulesSync(model *smodel.Model) ([]err_element.ErrorElement, smodel.TypeLookUp) {

	fillTypeLookUp := newFillTypeLookUp()
	lookUp, err := fillTypeLookUp.Fill(model)

	err = append(err, newComputeSuperTypes(&lookUp).walk()...)
	err = append(err, newComputeElements(&lookUp).walk()...)

	// Only Read LookUp
	err = append(err, newCheckEntityIdentifier(&lookUp).walk()...)
	err = append(err, newCheckEnumConstants(&lookUp).walk()...)
	err = append(err, newCheckReferenzen(&lookUp).walk()...)
	//mutex := sync.Mutex{}
	//group := sync.WaitGroup{}
	//group.Add(2)
	//go func() {
	//	walk := newCheckEntityIdentifier(&lookUp).walk()
	//	mutex.Lock()
	//	err = append(err, walk...)
	//	mutex.Unlock()
	//	group.Done()
	//}()
	//go func() {
	//	walk := newCheckEnumConstants(&lookUp).walk()
	//	mutex.Lock()
	//	err = append(err, walk...)
	//	mutex.Unlock()
	//	group.Done()
	//}()
	//
	//group.Wait()
	return err, lookUp
}
