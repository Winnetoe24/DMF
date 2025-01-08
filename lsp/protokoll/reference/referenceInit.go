package reference

// ReferenceClientCapabilities represents the reference-related capabilities
// the client supports and communicates to the server during initialization
type ReferenceClientCapabilities struct {
	// DynamicRegistration indicates whether the client supports dynamic registration
	// of reference support
	DynamicRegistration bool `json:"dynamicRegistration,omitempty"`
}

// ReferenceOptions represents server-side options for reference support
type ReferenceOptions struct {
	// WorkDoneProgress indicates whether the server supports work done progress
	WorkDoneProgress bool `json:"workDoneProgress,omitempty"`
}
