package selectionRange

// SelectionRangeClientCapabilities represents the selection range capabilities
// that the client supports.
type SelectionRangeClientCapabilities struct {
	// DynamicRegistration indicates whether the client supports dynamic registration
	// for selection range providers.
	DynamicRegistration bool `json:"dynamicRegistration,omitempty"`
}

// SelectionRangeOptions represents server-side options for selection range support.
type SelectionRangeOptions struct {
	// WorkDoneProgress indicates whether the server supports work done progress.
	WorkDoneProgress bool `json:"workDoneProgress,omitempty"`
}
