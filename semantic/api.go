package semantic

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	err_element "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	semantic_rules "github.com/Winnetoe24/DMF/semantic/semantic-rules"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

func ParseNewFile(fileContent string, loadFile func(absPath string, usedFiles []string) (smodel.TypeLookUp, error), usedFiles []string) ([]err_element.ErrorElement, int, error, *tree_sitter.Tree, *smodel.Model, smodel.TypeLookUp) {
	return semantic_rules.ParseNewFile(fileContent, loadFile, usedFiles)
}
func ParseEdit(fileContent string, edits []*tree_sitter.InputEdit, tree *tree_sitter.Tree, model *smodel.Model, lookup *smodel.TypeLookUp, loadFile func(absPath string, usedFiles []string) (smodel.TypeLookUp, error), usedFiles []string) (*tree_sitter.Tree, smodel.Model, smodel.TypeLookUp, []err_element.ErrorElement) {
	return semantic_rules.ParseEdit(fileContent, edits, tree, model, lookup, loadFile, usedFiles)
}
