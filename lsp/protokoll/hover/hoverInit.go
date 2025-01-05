package hover

// HoverClientCapabilities represents the hover-related capabilities
// the client supports and communicates to the server during initialization
type HoverClientCapabilities struct {
	// DynamicRegistration indicates whether the client supports dynamic registration
	// of hover support
	DynamicRegistration bool `json:"dynamicRegistration,omitempty"`

	// ContentFormat is an array of markup kinds that the client supports
	// The order describes the preferred format of the client
	ContentFormat []MarkupKind `json:"contentFormat,omitempty"`
}

// HoverOptions represents the options that can be set for hover support
type HoverOptions struct {
	// WorkDoneProgress indicates whether the server supports work done progress
	WorkDoneProgress bool `json:"workDoneProgress,omitempty"`
}
