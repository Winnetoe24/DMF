package folding

// FoldingRangeClientCapabilities represents the folding range capabilities
// the client supports
type FoldingRangeClientCapabilities struct {
	// DynamicRegistration indicates whether the client supports dynamic registration
	// for folding range providers
	DynamicRegistration bool `json:"dynamicRegistration,omitempty"`

	// RangeLimit is the maximum number of folding ranges that the client prefers to receive
	RangeLimit *uint32 `json:"rangeLimit,omitempty"`

	// LineFoldingOnly indicates whether the client only supports folding complete lines
	LineFoldingOnly bool `json:"lineFoldingOnly,omitempty"`

	// FoldingRangeKind indicates specific folding range kinds the client supports
	FoldingRangeKind *struct {
		// ValueSet is the folding range kinds the client supports
		ValueSet []FoldingRangeKind `json:"valueSet,omitempty"`
	} `json:"foldingRangeKind,omitempty"`

	// FoldingRange indicates specific properties the client supports
	FoldingRange *struct {
		// CollapsedText indicates whether the client supports the collapsedText property
		CollapsedText bool `json:"collapsedText,omitempty"`
	} `json:"foldingRange,omitempty"`
}

// FoldingRangeOptions represents server-side options for folding ranges
type FoldingRangeOptions struct {
	// WorkDoneProgress indicates whether the server supports work done progress
	WorkDoneProgress bool `json:"workDoneProgress,omitempty"`
}
