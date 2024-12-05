package main_test

import (
	"github.com/Winnetoe24/DMF/grammar/dmf_language"
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(dmf_language.Language())
	if language == nil {
		t.Errorf("Error loading Dmf grammar")
	}

	parser := tree_sitter.NewParser()
	err := parser.SetLanguage(language)
	if err != nil {
		t.Errorf("Error setting Language")
	}
	parse := parser.Parse([]byte("help"), nil)
	t.Logf("%+v, %+v", parse, parse.RootNode().Kind())
}
