package protokoll

// Diagnostic represents a diagnostic, such as a compiler error or warning
type Diagnostic struct {
	// Range is the range at which the message applies
	Range Range `json:"range"`
	// Severity is the diagnostic's severity. Can be omitted. If omitted it is up to the
	// client to interpret diagnostics as error, warning, info or hint
	Severity *DiagnosticSeverity `json:"severity,omitempty"`
	// Code is the diagnostic's code, which usually appear in the user interface
	Code interface{} `json:"code,omitempty"`
	// CodeDescription is an optional property to describe the error code
	CodeDescription *CodeDescription `json:"codeDescription,omitempty"`
	// Source is a human-readable string describing the source of this diagnostic
	Source string `json:"source,omitempty"`
	// Message is the diagnostic's message. It usually appears in the user interface
	Message string `json:"message"`
	// Tags provides additional metadata about the diagnostic
	Tags []DiagnosticTag `json:"tags,omitempty"`
	// RelatedInformation provides related diagnostic information
	RelatedInformation []DiagnosticRelatedInformation `json:"relatedInformation,omitempty"`
	// Data is a data field that can be used to associate arbitrary data with the diagnostic
	Data interface{} `json:"data,omitempty"`
}

// DiagnosticSeverity represents how severe a diagnostic is
type DiagnosticSeverity int

const (
	// SeverityError reports an error
	SeverityError DiagnosticSeverity = 1
	// SeverityWarning reports a warning
	SeverityWarning DiagnosticSeverity = 2
	// SeverityInformation reports an information
	SeverityInformation DiagnosticSeverity = 3
	// SeverityHint reports a hint
	SeverityHint DiagnosticSeverity = 4
)

// DiagnosticTag provides additional metadata about the diagnostic
type DiagnosticTag int

const (
	// Unnecessary indicates that the code is unnecessary
	TagUnnecessary DiagnosticTag = 1
	// Deprecated indicates that the code is deprecated
	TagDeprecated DiagnosticTag = 2
)

// CodeDescription contains additional information about the diagnostic's code
type CodeDescription struct {
	// Href is an URI to open with more information about the diagnostic
	Href string `json:"href"`
}

// DiagnosticRelatedInformation represents related diagnostic information, such as related diagnostics
type DiagnosticRelatedInformation struct {
	// Location of this related diagnostic information
	Location Location `json:"location"`
	// Message is a message about this related diagnostic information
	Message string `json:"message"`
}
