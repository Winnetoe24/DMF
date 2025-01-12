package folding

import "github.com/Winnetoe24/DMF/lsp/protokoll"

// FoldingRangeParams represents the parameters sent in a folding range request
type FoldingRangeParams struct {
	// TextDocument is the document to get folding ranges for
	TextDocument protokoll.TextDocumentIdentifier `json:"textDocument"`
	// WorkDoneToken is an optional token that can be used to report work progress
	WorkDoneToken *string `json:"workDoneToken,omitempty"`
}

// FoldingRange represents a folding range in a document
type FoldingRange struct {
	// StartLine is the zero-based start line of the folding range
	StartLine uint32 `json:"startLine"`
	// StartCharacter is the zero-based start character of the folding range
	StartCharacter *uint32 `json:"startCharacter,omitempty"`
	// EndLine is the zero-based end line of the folding range
	EndLine uint32 `json:"endLine"`
	// EndCharacter is the zero-based end character of the folding range
	EndCharacter *uint32 `json:"endCharacter,omitempty"`
	// Kind is the type of the folding range
	Kind *FoldingRangeKind `json:"kind,omitempty"`
	// CollapsedText is the text that should be displayed when the range is collapsed
	CollapsedText *string `json:"collapsedText,omitempty"`
}

// FoldingRangeKind represents the kind of a folding range
type FoldingRangeKind string

const (
	// Comment indicates a comment folding range
	Comment FoldingRangeKind = "comment"
	// Imports indicates an import folding range
	Imports FoldingRangeKind = "imports"
	// Region indicates a region folding range
	Region FoldingRangeKind = "region"
)
