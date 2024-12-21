package fileService

import (
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

type FileChangeListener interface {
	// HandleFileChange gets called when the FileService finishes parsing the File. It may be called in its own routine. Changes to the Parameters are ignored.
	HandleFileChange(file protokoll.DocumentURI, fileContent string, ast tree_sitter.Tree, model smodel.Model, lookup smodel.TypeLookUp, errorElements []errElement.ErrorElement, version int32)
}
