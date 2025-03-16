package semantictokens

import "github.com/Winnetoe24/DMF/lsp/protokoll"

// SemanticTokensFullDeltaParams represents the parameters for a
// textDocument/semanticTokens/full/delta request
type SemanticTokensFullDeltaParams struct {
	// TextDocument identifies the document to provide semantic tokens for
	TextDocument protokoll.TextDocumentIdentifier `json:"textDocument"`

	// PreviousResultId is the ID of the previous result to compute a delta from
	PreviousResultId string `json:"previousResultId"`

	// WorkDoneToken is an optional token that can be used to report work progress
	WorkDoneToken *string `json:"workDoneToken,omitempty"`

	// PartialResultToken is an optional token that can be used to report partial results
	PartialResultToken *string `json:"partialResultToken,omitempty"`
}

// SemanticTokensDelta represents the result of a textDocument/semanticTokens/full/delta request
type SemanticTokensDelta struct {
	// ResultID is a unique identifier for this result
	// The client will send this ID back when making a delta request
	ResultId string `json:"resultId,omitempty"`

	// Edits contains the deltas that should be applied to the previous result
	// If omitted, the previous result should be completely discarded and replaced with tokens
	Edits []SemanticTokensEdit `json:"edits,omitempty"`

	// Data contains the tokens if no edits are provided
	// This is used to replace the entire previous result when edits are omitted
	Data []uint32 `json:"data,omitempty"`
}

// SemanticTokensEdit represents an edit to apply to a previous semantic tokens result
type SemanticTokensEdit struct {
	// Start is the offset into the previous token array where the deletion/replacement begins
	Start uint32 `json:"start"`

	// DeleteCount is the number of tokens to delete from the original array
	DeleteCount uint32 `json:"deleteCount"`

	// Data contains the tokens to insert at the position
	// The length of this array can be different from the delete count
	Data []uint32 `json:"data,omitempty"`
}
