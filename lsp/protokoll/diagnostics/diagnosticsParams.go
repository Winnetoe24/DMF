package diagnostics

import "github.com/Winnetoe24/DMF/lsp/protokoll"

// PublishDiagnosticsParams represents the parameters sent in a textDocument/publishDiagnostics notification
type PublishDiagnosticsParams struct {
	// URI is the URI for which diagnostic information is reported
	URI string `json:"uri"`
	// Version is the version number of the document the diagnostics are published for
	Version *int32 `json:"version,omitempty"`
	// Diagnostics is an array of diagnostic information items
	Diagnostics []protokoll.Diagnostic `json:"diagnostics"`
}
