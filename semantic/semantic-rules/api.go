package semantic_rules

import (
	"errors"
	tree_sitter_dmf "github.com/Winnetoe24/DMF/grammar/dmf_language"
	sematic_model "github.com/Winnetoe24/DMF/semantic/semantic-parse"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	err_element "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

const (
	ERROR_AFTER_TREE_SITTER_PARSER = 1
	ERROR_AFTER_SEMANTIC_PARSE     = 2
)

func ParseNewFile(fileContent string, afterParse chan<- *tree_sitter.Tree, afterSematicModel chan<- *smodel.Model) ([]err_element.ErrorElement, int, error, TypeLookUp) {

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

	var lookup TypeLookUp
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

type semanticRule[E any, R any] interface {
	SemanticRule(fileContent []byte, model *smodel.Model, lookup *TypeLookUp) []err_element.ErrorElement
}

type TypeLookUp map[string]packages.PackageElement

var _ ITypeLookUp = (TypeLookUp)(nil)

func (t TypeLookUp) getTypeLookUp() TypeLookUp {
	return t
}

type ITypeLookUp interface {
	getTypeLookUp() TypeLookUp
}

func runRulesSync(model *smodel.Model) ([]err_element.ErrorElement, TypeLookUp) {

	fillTypeLookUp := newFillTypeLookUp()
	lookUp, err := fillTypeLookUp.Fill(model)

	err = append(err, newComputeSuperTypes(&lookUp).walk()...)
	err = append(err, newComputeElements(&lookUp).walk()...)

	// Only Read LookUp
	err = append(err, newCheckEntityIdentifier(&lookUp).walk()...)
	err = append(err, newCheckEnumConstants(&lookUp).walk()...)

	return err, lookUp
}
