package completion

import "github.com/Winnetoe24/DMF/lsp/protokoll"

// TextDocumentPositionParams contains the location where completion was requested
type TextDocumentPositionParams struct {
	// TextDocument identifies the document to get completions for
	TextDocument protokoll.TextDocumentIdentifier `json:"textDocument"`
	// Position inside the text document where completion was requested
	Position protokoll.Position `json:"position"`
}

// CompletionParams extends TextDocumentPositionParams with additional completion context
type CompletionParams struct {
	TextDocumentPositionParams
	// Context contains additional information about the completion context
	Context *CompletionContext `json:"context,omitempty"`
}

// CompletionContext contains additional information about the trigger of the completion request
type CompletionContext struct {
	// TriggerKind defines how the completion was triggered
	TriggerKind CompletionTriggerKind `json:"triggerKind"`
	// TriggerCharacter contains the trigger character if the completion was explicitly triggered
	TriggerCharacter string `json:"triggerCharacter,omitempty"`
}

// CompletionTriggerKind defines how a completion was triggered
type CompletionTriggerKind int

const (
	// Invoked indicates completion was triggered by manual invocation (e.g Ctrl+Space)
	CompletionTriggerInvoked CompletionTriggerKind = 1
	// TriggerCharacter indicates completion was triggered by a trigger character
	CompletionTriggerTriggerCharacter CompletionTriggerKind = 2
	// TriggerForIncompleteCompletions indicates completion was re-triggered as the current completion list is incomplete
	CompletionTriggerTriggerForIncompleteCompletions CompletionTriggerKind = 3
)
