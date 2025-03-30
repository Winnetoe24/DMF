package hover

import (
	"encoding/json"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
)

// HoverParams represents the parameters sent in a hover request.
// This is sent from the client to request hover information at a specific position
// in a document.
type HoverParams struct {
	// TextDocument identifies the document the hover is requested for
	TextDocument protokoll.TextDocumentIdentifier `json:"textDocument"`
	// Position defines the position in the text document where hover is requested
	Position protokoll.Position `json:"position"`
}

// HoverResult represents the result of a hover request.
// This is the server's response containing the information to display in a hover.
type HoverResult struct {
	// Contents holds the hover content
	// Can be either a MarkedString, MarkedString[] or MarkupContent
	Contents json.RawMessage `json:"contents"`
	// Range is an optional range to highlight
	Range *protokoll.Range `json:"range,omitempty"`
}

// MarkupContent represents a hover response with explicit markup type.
type MarkupContent struct {
	// Kind describes the markup kind, e.g., "plaintext" or "markdown"
	Kind MarkupKind `json:"kind"`
	// Value contains the actual content
	Value string `json:"value"`
}

// MarkupKind defines the supported markup kinds.
type MarkupKind string

const (
	// PlainText represents plain text markup
	PlainText MarkupKind = "plaintext"
	// Markdown represents markdown markup
	Markdown MarkupKind = "markdown"
)

// MarkedString represents legacy markdown string format.
// Deprecated: Use MarkupContent instead.
type MarkedString struct {
	// Language defines the language of the markdown string
	Language string `json:"language,omitempty"`
	// Value contains the content
	Value string `json:"value"`
}
