package semantic_parse

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	err_element "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

type SemanticContext struct {
	ErrorElements []err_element.ErrorElement
	Model         smodel.Model
	Text          []byte
	Cursor        *tree_sitter.TreeCursor
	ParseFile     func(statement smodel.ImportStatement) (smodel.TypeLookUp, *err_element.ErrorElement)
	// Contains all Files in Import Order.
	UsedFiles []string
}
