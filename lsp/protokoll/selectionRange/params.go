package selectionRange

import "github.com/Winnetoe24/DMF/lsp/protokoll"

// SelectionRangeParams represents the parameters sent in a selection range request.
type SelectionRangeParams struct {
	// TextDocument identifies the document to compute selection ranges for.
	TextDocument protokoll.TextDocumentIdentifier `json:"textDocument"`

	// Positions is an array of positions in the text document for which to compute
	// selection ranges.
	Positions []protokoll.Position `json:"positions"`

	// WorkDoneToken is an optional token that can be used to report progress.
	WorkDoneToken *string `json:"workDoneToken,omitempty"`

	// PartialResultToken is an optional token that can be used to report partial results.
	PartialResultToken *string `json:"partialResultToken,omitempty"`
}

// SelectionRange represents a selection range with its parent selection ranges.
type SelectionRange struct {
	// Range is the actual range of this selection range.
	Range protokoll.Range `json:"range"`

	// Parent is the parent selection range containing this range. Therefore,
	// multiple selection ranges can be encoded into a tree structure.
	Parent *SelectionRange `json:"parent,omitempty"`
}

// SelectionRangeResult represents the result of a selection range request.
// It's an array of SelectionRange objects, one for each position in the request.
type SelectionRangeResult []SelectionRange
