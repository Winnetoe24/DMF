package parse_old

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	err_element "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

// ParseContext enthält den globalen Kontext des Parse Vorgangs
type ParseContext struct {
	ErrorElements []err_element.ErrorElement
	Text          []byte
	Cursor        *tree_sitter.TreeCursor
	ParseFile     func(statement smodel.ImportStatement) (smodel.TypeLookUp, *err_element.ErrorElement)
	// TODO erst nur extraktion von imports informationen
	// In zweitem Schritt kombinieren
	ImportLookUp smodel.TypeLookUp
	// Contains all Files in Import Order.
	UsedFiles []string
}
