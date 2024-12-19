package textEdit

// TextDocumentSyncKind defines how the language server receives document changes
type TextDocumentSyncKind int

const (
	// TextDocumentSyncKindNone means documents should not be synced
	TextDocumentSyncKindNone TextDocumentSyncKind = 0

	// TextDocumentSyncKindFull means documents are synced by sending the full content
	TextDocumentSyncKindFull TextDocumentSyncKind = 1

	// TextDocumentSyncKindIncremental means documents are synced by sending incremental changes
	TextDocumentSyncKindIncremental TextDocumentSyncKind = 2
)

// TextDocumentSyncOptions represents the server's document sync capabilities
type TextDocumentSyncOptions struct {
	// Whether to open text documents
	OpenClose bool `json:"openClose,omitempty"`

	// How to sync document changes (none, full, incremental)
	Change TextDocumentSyncKind `json:"change,omitempty"`
}

// TextDocumentSyncClientCapabilities describes the text document sync capabilities
// that the client supports.
type TextDocumentSyncClientCapabilities struct {
	// DynamicRegistration indicates whether text document synchronization supports
	// dynamic registration.
	DynamicRegistration *bool `json:"dynamicRegistration,omitempty"`

	// WillSave indicates whether the client supports sending willSave notifications.
	WillSave *bool `json:"willSave,omitempty"`

	// WillSaveWaitUntil indicates whether the client supports sending a will save
	// request and waiting for edits before the file is saved.
	WillSaveWaitUntil *bool `json:"willSaveWaitUntil,omitempty"`

	// DidSave indicates whether the client supports did save notifications.
	DidSave *bool `json:"didSave,omitempty"`
}

// String returns the string representation of TextDocumentSyncKind
func (k TextDocumentSyncKind) String() string {
	switch k {
	case TextDocumentSyncKindNone:
		return "None"
	case TextDocumentSyncKindFull:
		return "Full"
	case TextDocumentSyncKindIncremental:
		return "Incremental"
	default:
		return "Unknown"
	}
}

// IsValid checks if the TextDocumentSyncKind is valid
func (k TextDocumentSyncKind) IsValid() bool {
	return k >= TextDocumentSyncKindNone && k <= TextDocumentSyncKindIncremental
}
