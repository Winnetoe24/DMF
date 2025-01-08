package reference

import (
	"github.com/Winnetoe24/DMF/lsp/protokoll"
)

// ReferenceParams represents the parameters sent in a reference request
type ReferenceParams struct {
	// TextDocument identifies the document to find references in
	TextDocument protokoll.TextDocumentIdentifier `json:"textDocument"`

	// Position specifies the position in the text document for which
	// to find all references
	Position protokoll.Position `json:"position"`

	// Context provides additional information about the reference request
	Context ReferenceContext `json:"context"`

	// WorkDoneToken is an optional token that can be used to report work progress
	WorkDoneToken *string `json:"workDoneToken,omitempty"`
}

// ReferenceContext provides additional information about the reference request
type ReferenceContext struct {
	// IncludeDeclaration controls whether the declaration of the requested symbol
	// should be included in the response
	IncludeDeclaration bool `json:"includeDeclaration"`
}

// ReferenceResult represents the result of a reference request
// It's an array of Locations where the symbol is referenced
type ReferenceResult []protokoll.Location
