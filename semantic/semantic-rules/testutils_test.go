package semantic_rules

import (
	tree_sitter_dmf "github.com/Winnetoe24/DMF/grammar/dmf_language"
	sematic_model "github.com/Winnetoe24/DMF/semantic/semantic-parse"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"os"
	"testing"
)

func testSemanticRule[E any, R any](t *testing.T, rule semanticRule[E, R], filename string, expectedErrorCount int, extra E) R {
	file, model := testSetup(t, filename)

	errorElements, r := rule.SemanticRule(file, &model, extra)
	if expectedErrorCount == 0 {
		if errorElements != nil && len(errorElements) > 0 {
			for _, element := range errorElements {
				t.Error(element.ToErrorMsg())
			}
		}
	} else {
		if errorElements == nil {
			t.Errorf("Error rule did not produce expected error")
		} else {
			length := len(errorElements)
			if length > expectedErrorCount {
				for _, errorElement := range errorElements {
					t.Errorf("To many Errors: %s\n", errorElement.ToErrorMsgFile(filename))
				}
			} else if length < expectedErrorCount {
				for _, errorElement := range errorElements {
					t.Errorf("correct Error: %s\n", errorElement.ToErrorMsgFile(filename))
				}
				t.Errorf("To less Errors! Expected %v more Errors.\n", expectedErrorCount)
			}
		}
	}
	return r
}

func testSetup(t testing.TB, filename string) (file []byte, parsedModel smodel.Model) {
	language := tree_sitter.NewLanguage(tree_sitter_dmf.Language())
	if language == nil {
		t.Errorf("Error loading Dmf grammar")
	}

	parser := tree_sitter.NewParser()
	err := parser.SetLanguage(language)
	if err != nil {
		t.Errorf("Error setting Language: %e", err)
	}
	file, err = os.ReadFile(filename)
	if err != nil {
		t.Errorf("Error reading file: %e", err)
	}
	tree := parser.Parse(file, nil)

	parsedModel, elements, err := sematic_model.Parse(file, tree)
	if err != nil {
		t.Errorf("Error parsing file: %e", err)
	}
	if elements != nil && len(elements) > 0 {
		for _, element := range elements {
			t.Error(element.ToErrorMsgFile(filename))
		}
	}
	return file, parsedModel
}
