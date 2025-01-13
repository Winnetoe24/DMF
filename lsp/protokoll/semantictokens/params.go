package semantictokens

import "github.com/Winnetoe24/DMF/lsp/protokoll"

// SemanticTokensParams represents the parameters for a semantic tokens request
type SemanticTokensParams struct {
	// TextDocument is the document to provide semantic tokens for
	TextDocument protokoll.TextDocumentIdentifier `json:"textDocument"`
	// WorkDoneToken is an optional token that can be used to report work progress
	WorkDoneToken *string `json:"workDoneToken,omitempty"`
}

// SemanticTokens represents the response to a semantic tokens request
type SemanticTokens struct {
	// ResultID is an optional result id that can be used to compute delta updates
	ResultID string `json:"resultId,omitempty"`
	// Data contains the actual tokens in the specified format
	Data []uint32 `json:"data"`
}
