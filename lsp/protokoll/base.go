package protokoll

// Position represents a position in a text document
type Position struct {
	Line      uint32 `json:"line"`      // Line position in a document (zero-based)
	Character uint32 `json:"character"` // Character offset on a line (zero-based)
}

// Range represents a range in a text document
type Range struct {
	Start Position `json:"start"`
	End   Position `json:"end"`
}

// Location represents a location inside a resource
type Location struct {
	URI   DocumentURI `json:"uri"`
	Range Range       `json:"range"`
}

// TextDocumentItem represents an open text document
type TextDocumentItem struct {
	URI        DocumentURI `json:"uri"`
	LanguageID string      `json:"languageId"`
	Version    int32       `json:"version"`
	Text       string      `json:"text"`
}

// TextDocumentIdentifier identifies a text document
type TextDocumentIdentifier struct {
	URI DocumentURI `json:"uri"`
}

// VersionedTextDocumentIdentifier identifies a specific version of a text document
type VersionedTextDocumentIdentifier struct {
	TextDocumentIdentifier
	Version int32 `json:"version"`
}

// TextDocumentPositionParams represents a text document and a position inside that document
type TextDocumentPositionParams struct {
	TextDocument TextDocumentIdentifier `json:"textDocument"`
	Position     Position               `json:"position"`
}

// DiagnosticSeverity represents the severity of diagnostics
type DiagnosticSeverity int

const (
	DiagnosticSeverityError       DiagnosticSeverity = 1
	DiagnosticSeverityWarning     DiagnosticSeverity = 2
	DiagnosticSeverityInformation DiagnosticSeverity = 3
	DiagnosticSeverityHint        DiagnosticSeverity = 4
)

// Diagnostic represents a diagnostic, such as a compiler error or warning
type Diagnostic struct {
	Range    Range              `json:"range"`
	Severity DiagnosticSeverity `json:"severity,omitempty"`
	Code     interface{}        `json:"code,omitempty"`
	Source   string             `json:"source,omitempty"`
	Message  string             `json:"message"`
}

// CompletionItemKind indicates the type of a completion item
type CompletionItemKind int

const (
	CompletionItemKindText        CompletionItemKind = 1
	CompletionItemKindMethod      CompletionItemKind = 2
	CompletionItemKindFunction    CompletionItemKind = 3
	CompletionItemKindConstructor CompletionItemKind = 4
	CompletionItemKindField       CompletionItemKind = 5
	CompletionItemKindVariable    CompletionItemKind = 6
	CompletionItemKindClass       CompletionItemKind = 7
	CompletionItemKindInterface   CompletionItemKind = 8
	CompletionItemKindModule      CompletionItemKind = 9
	CompletionItemKindProperty    CompletionItemKind = 10
	CompletionItemKindUnit        CompletionItemKind = 11
	CompletionItemKindValue       CompletionItemKind = 12
	CompletionItemKindEnum        CompletionItemKind = 13
	CompletionItemKindKeyword     CompletionItemKind = 14
	CompletionItemKindSnippet     CompletionItemKind = 15
)

// CompletionItem represents a completion item
type CompletionItem struct {
	Label               string             `json:"label"`
	Kind                CompletionItemKind `json:"kind,omitempty"`
	Detail              string             `json:"detail,omitempty"`
	Documentation       string             `json:"documentation,omitempty"`
	SortText            string             `json:"sortText,omitempty"`
	FilterText          string             `json:"filterText,omitempty"`
	InsertText          string             `json:"insertText,omitempty"`
	TextEdit            *TextEdit          `json:"textEdit,omitempty"`
	AdditionalTextEdits []TextEdit         `json:"additionalTextEdits,omitempty"`
}

// TextEdit represents a change to a text document
type TextEdit struct {
	Range   Range  `json:"range"`
	NewText string `json:"newText"`
}

// WorkspaceEdit represents changes to many documents
type WorkspaceEdit struct {
	Changes map[DocumentURI][]TextEdit `json:"changes,omitempty"`
}
