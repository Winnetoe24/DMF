package semantic

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	err_element "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	semantic_rules "github.com/Winnetoe24/DMF/semantic/semantic-rules"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

func ParseNewFile(fileContent string, afterParse chan<- *tree_sitter.Tree, afterSematicModel chan<- *smodel.Model) ([]err_element.ErrorElement, int, error, smodel.TypeLookUp) {
	return semantic_rules.ParseNewFile(fileContent, afterParse, afterSematicModel)
}
