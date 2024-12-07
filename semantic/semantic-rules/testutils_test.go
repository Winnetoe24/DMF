package semantic_rules

import (
	tree_sitter_dmf "github.com/Winnetoe24/DMF/grammar/dmf_language"
	sematic_model "github.com/Winnetoe24/DMF/semantic/semantic-parse"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	err_element "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"os"
	"testing"
)

func checkErrorCount(t *testing.T, ctx *err_element.ErrorContext, errorElements []err_element.ErrorElement, expectedErrorCount int) {
	if expectedErrorCount == 0 {
		if errorElements != nil && len(errorElements) > 0 {
			for _, element := range errorElements {
				t.Error(element.ToErrorMsg(ctx))
			}
		}
	} else {
		if errorElements == nil {
			t.Errorf("Error rule did not produce expected error")
		} else {
			length := len(errorElements)
			if length > expectedErrorCount {
				for _, errorElement := range errorElements {
					t.Errorf("To many Errors: %s\n", errorElement.ToErrorMsg(ctx))
				}
			} else if length < expectedErrorCount {
				for _, errorElement := range errorElements {
					t.Errorf("correct Error: %s\n", errorElement.ToErrorMsg(ctx))
				}
				t.Errorf("To less Errors! Expected %v more Errors.\n", expectedErrorCount)
			}
		}
	}
}

func testSetup(t testing.TB, filename string) (model smodel.Model, ctx *err_element.ErrorContext) {
	language := tree_sitter.NewLanguage(tree_sitter_dmf.Language())
	if language == nil {
		t.Errorf("Error loading Dmf grammar")
	}

	parser := tree_sitter.NewParser()
	err := parser.SetLanguage(language)
	if err != nil {
		t.Errorf("Error setting Language: %e", err)
	}
	file, err := os.ReadFile(filename)
	if err != nil {
		t.Errorf("Error reading file: %e", err)
	}
	tree := parser.Parse(file, nil)

	model, elements, err := sematic_model.Parse(file, tree)
	if err != nil {
		t.Errorf("Error parsing file: %e", err)
	}
	if elements != nil && len(elements) > 0 {
		for _, element := range elements {
			t.Error(element.ToErrorMsg(&err_element.ErrorContext{
				Dateiname:   filename,
				Dateiinhalt: file,
			}))
		}
	}
	return model, &err_element.ErrorContext{
		Dateiname:   filename,
		Dateiinhalt: file,
	}
}
