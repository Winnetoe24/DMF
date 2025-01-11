package protokoll

// DocumentFilter is used to describe a filter for documents the server is interested in.
// A document must match all provided properties to match the filter.
type DocumentFilter struct {
	// Language is a language id, like 'typescript'
	Language string `json:"language,omitempty"`

	// Scheme is a URI scheme, like 'file', 'untitled', etc.
	Scheme string `json:"scheme,omitempty"`

	// Pattern is a glob pattern to match against the file path
	Pattern string `json:"pattern,omitempty"`
}

// DocumentSelector is an array of document filters
type DocumentSelector []DocumentFilter
