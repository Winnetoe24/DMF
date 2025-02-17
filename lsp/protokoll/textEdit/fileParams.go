package textEdit

import (
	"github.com/Winnetoe24/DMF/lsp/protokoll"
)

// DidOpenTextDocumentParams represents parameters sent when a document is opened
type DidOpenTextDocumentParams struct {
	TextDocument protokoll.TextDocumentItem `json:"textDocument"`
}

// DidChangeTextDocumentParams represents parameters sent when a document is changed
type DidChangeTextDocumentParams struct {
	TextDocument   protokoll.VersionedTextDocumentIdentifier `json:"textDocument"`
	ContentChanges []TextDocumentContentChangeEvent          `json:"contentChanges"`
}

// DidCloseTextDocumentParams represents the parameters sent when a text document
// is closed in the LSP specification.
type DidCloseTextDocumentParams struct {
	// TextDocument is the document that was closed
	TextDocument protokoll.TextDocumentIdentifier `json:"textDocument"`
}

// TextDocumentContentChangeEvent represents a change to a text document
type TextDocumentContentChangeEvent struct {
	Range       *protokoll.Range `json:"range,omitempty"`
	RangeLength uint32           `json:"rangeLength,omitempty"`
	Text        string           `json:"text"`
}
