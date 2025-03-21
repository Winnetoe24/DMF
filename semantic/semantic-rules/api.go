package semantic_rules

import (
	"errors"
	"fmt"
	tree_sitter_dmf "github.com/Winnetoe24/DMF/grammar/dmf_language"
	sematic_model "github.com/Winnetoe24/DMF/semantic/semantic-parse"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	err_element "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"path/filepath"
	"slices"
	"strings"
)

const (
	ERROR_AFTER_TREE_SITTER_PARSER = 1
	ERROR_AFTER_SEMANTIC_PARSE     = 2
)

func parseImportedFile(statement smodel.ImportStatement, usedFiles []string, loadFile func(absPath string, usedFiles []string) (smodel.TypeLookUp, error)) (smodel.TypeLookUp, *err_element.ErrorElement) {
	if statement.Node == nil {
		fmt.Printf("ImportStatement in ImportFunction: %+v\n", statement)
	}
	if len(usedFiles) == 0 {
		return nil, err_element.CreateErrorElementRef(statement.FileName.Node, errors.New("Pfad der aktuellen Datei nicht vorhanden."))
	}

	// Determine File Path
	parentFilePath := usedFiles[len(usedFiles)-1]
	dir, _ := filepath.Split(parentFilePath)
	newRelativeFilePath := filepath.Join(dir, strings.Trim(statement.FileName.Value, " "))
	abs, err := filepath.Abs(newRelativeFilePath)
	if err != nil {
		return nil, err_element.CreateErrorElementRef(statement.FileName.Node, err)
	}

	if slices.Contains(usedFiles, abs) {
		return nil, err_element.CreateErrorElementRef(statement.FileName.Node, errors.New("Rekursiver Import"))
	}

	lookUp, err := loadFile(abs, usedFiles)
	if err != nil {
		return nil, err_element.CreateErrorElementRef(statement.FileName.Node, err)
	}
	return lookUp, nil
}

func ParseNewFile(fileContent string, loadFile func(absPath string, usedFiles []string) (smodel.TypeLookUp, error), usedFiles []string) ([]err_element.ErrorElement, int, error, *tree_sitter.Tree, *smodel.Model, smodel.TypeLookUp) {

	tree, err := callTreeSitterParser(fileContent)
	if err != nil {
		return nil, ERROR_AFTER_TREE_SITTER_PARSER, err, nil, nil, nil
	}

	parsedModel, errorElementsModel, err := sematic_model.Parse([]byte(fileContent), tree, func(statement smodel.ImportStatement) (smodel.TypeLookUp, *err_element.ErrorElement) {
		return parseImportedFile(statement, usedFiles, loadFile)
	})
	if err != nil {
		return nil, ERROR_AFTER_SEMANTIC_PARSE, err, nil, nil, nil
	}

	var errorElements []err_element.ErrorElement

	var lookup smodel.TypeLookUp
	errorElements, lookup = runRulesSync(&parsedModel)

	errorElements = append(errorElements, errorElementsModel...)
	return errorElements, 0, nil, tree, &parsedModel, lookup
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
	//if parse != nil {
	//	runtime.SetFinalizer(parse, func(tree *tree_sitter.Tree) {
	//		tree.Close()
	//	})
	//}
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

func ParseEdit(fileContent string, edits []*tree_sitter.InputEdit, tree *tree_sitter.Tree, model *smodel.Model, lookup *smodel.TypeLookUp, loadFile func(absPath string, usedFiles []string) (smodel.TypeLookUp, error), usedFiles []string) (*tree_sitter.Tree, smodel.Model, smodel.TypeLookUp, []err_element.ErrorElement) {
	errorElements := make([]err_element.ErrorElement, 0)
	for _, edit := range edits {
		tree.Edit(edit)
	}
	parser := tree_sitter.NewParser()
	language := tree_sitter.NewLanguage(tree_sitter_dmf.Language())
	err := parser.SetLanguage(language)
	if err != nil {
		errorElements = append(errorElements, err_element.CreateErrorElement(nil, err))
		return nil, smodel.Model{}, nil, errorElements
	}
	tree_new := parser.Parse([]byte(fileContent), tree)

	parsedModel, errorElementsModel, err := sematic_model.Parse([]byte(fileContent), tree_new, func(statement smodel.ImportStatement) (smodel.TypeLookUp, *err_element.ErrorElement) {
		return parseImportedFile(statement, usedFiles, loadFile)
	})
	if err != nil {
		errorElements = append(errorElements, err_element.CreateErrorElement(nil, err))
		return tree_new, parsedModel, nil, errorElementsModel
	}

	errorElements, newLookup := runRulesSync(&parsedModel)

	errorElementsModel = append(errorElements, errorElementsModel...)
	return tree_new, parsedModel, newLookup, errorElementsModel
}
