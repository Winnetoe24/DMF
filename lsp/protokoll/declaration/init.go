package declaration

import "github.com/Winnetoe24/DMF/lsp/protokoll"

// DeclarationClientCapabilities represents the declaration-related capabilities
// the client supports and communicates to the server during initialization
type DeclarationClientCapabilities struct {
	// DynamicRegistration indicates whether the client supports dynamic registration
	// of declaration support
	DynamicRegistration bool `json:"dynamicRegistration,omitempty"`

	// LinkSupport indicates whether the client supports additional metadata in the form of declaration links
	LinkSupport bool `json:"linkSupport,omitempty"`
}

// DeclarationOptions represents the options that can be set for declaration support
type DeclarationOptions struct {
	// WorkDoneProgress indicates whether the server supports work done progress
	WorkDoneProgress bool `json:"workDoneProgress,omitempty"`
}

// DeclarationRegistrationOptions represents the registration options for declaration support
type DeclarationRegistrationOptions struct {
	DeclarationOptions

	// DocumentSelector is a document selector to identify the scope of the registration
	DocumentSelector []protokoll.DocumentFilter `json:"documentSelector"`
}
