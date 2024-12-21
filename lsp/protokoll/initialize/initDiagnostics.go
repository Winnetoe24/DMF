package initialize

import "github.com/Winnetoe24/DMF/lsp/protokoll"

// PublishDiagnosticsClientCapabilities represents the specific client capabilities
// for the textDocument/publishDiagnostics notification
type PublishDiagnosticsClientCapabilities struct {
	// RelatedInformation indicates whether the client accepts diagnostics with related information
	RelatedInformation bool `json:"relatedInformation,omitempty"`

	// TagSupport indicates whether the client supports diagnostic tags
	TagSupport *struct {
		// ValueSet is the set of supported diagnostic tags
		ValueSet []protokoll.DiagnosticTag `json:"valueSet"`
	} `json:"tagSupport,omitempty"`

	// VersionSupport indicates whether the client accepts diagnostics with version information
	VersionSupport bool `json:"versionSupport,omitempty"`

	// CodeDescriptionSupport indicates whether the client supports diagnostic code descriptions
	CodeDescriptionSupport bool `json:"codeDescriptionSupport,omitempty"`

	// DataSupport indicates whether the client accepts diagnostic data
	DataSupport bool `json:"dataSupport,omitempty"`
}

// DiagnosticServerCapabilities represents the server's diagnostic capabilities
type DiagnosticServerCapabilities struct {
	// RelatedDocumentSupport indicates whether the server supports diagnostic pulls for related documents
	RelatedDocumentSupport bool `json:"relatedDocumentSupport,omitempty"`

	// InterFileDependencies indicates whether the server provides diagnostics from cross-file dependencies
	InterFileDependencies bool `json:"interFileDependencies,omitempty"`

	// WorkspaceDiagnostics indicates whether the server supports workspace-wide diagnostics
	WorkspaceDiagnostics bool `json:"workspaceDiagnostics,omitempty"`
}

// DiagnosticOptions represents the options that a server supports for diagnostic pulls
type DiagnosticOptions struct {
	// Identifier is an optional identifier under which diagnostic pull requests can be registered
	Identifier string `json:"identifier,omitempty"`

	// InterFileDependencies indicates whether the server provides diagnostics from cross-file dependencies
	InterFileDependencies bool `json:"interFileDependencies"`

	// WorkspaceDiagnostics indicates whether the server supports workspace-wide diagnostics
	WorkspaceDiagnostics bool `json:"workspaceDiagnostics"`
}
