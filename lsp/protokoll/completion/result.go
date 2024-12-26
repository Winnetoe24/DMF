package completion

import "github.com/Winnetoe24/DMF/lsp/protokoll"

// CompletionResponse represents a completion response
type CompletionResponse struct {
	// IsIncomplete indicates whether the list is incomplete and further typing should trigger another completion request
	IsIncomplete bool `json:"isIncomplete"`
	// Items contains the completion items
	Items []CompletionItem `json:"items"`
}

// CompletionItem represents a completion item
type CompletionItem struct {
	// Label is the label of this completion item
	Label string `json:"label"`
	// Kind indicates the type of this completion item
	Kind CompletionItemKind `json:"kind,omitempty"`
	// Detail is additional details about this completion item
	Detail string `json:"detail,omitempty"`
	// Documentation is the documentation for this completion item
	Documentation string `json:"documentation,omitempty"`
	// Deprecated indicates if this item is deprecated
	Deprecated bool `json:"deprecated,omitempty"`
	// Preselect indicates if this item should be preselected
	Preselect bool `json:"preselect,omitempty"`
	// SortText defines the sorting order relative to other items
	SortText string `json:"sortText,omitempty"`
	// FilterText defines what gets filtered when typing
	FilterText string `json:"filterText,omitempty"`
	// InsertText is the text to insert when selecting this completion
	InsertText string `json:"insertText,omitempty"`
	// InsertTextFormat defines the format of the insert text
	InsertTextFormat InsertTextFormat `json:"insertTextFormat,omitempty"`
	// TextEdit defines a text edit to be applied when selecting this completion
	TextEdit *TextEdit `json:"textEdit,omitempty"`
	// AdditionalTextEdits defines additional text edits to be applied
	AdditionalTextEdits []TextEdit `json:"additionalTextEdits,omitempty"`
	// CommitCharacters defines which characters trigger completion commit
	CommitCharacters []string `json:"commitCharacters,omitempty"`
	// Command defines a command to execute after inserting this completion
	Command *Command `json:"command,omitempty"`
	// Data is additional data that gets passed to resolve request
	Data interface{} `json:"data,omitempty"`
}

// CompletionItemKind defines the type of a completion entry
type CompletionItemKind int

const (
	CompletionItemKindText          CompletionItemKind = 1
	CompletionItemKindMethod        CompletionItemKind = 2
	CompletionItemKindFunction      CompletionItemKind = 3
	CompletionItemKindConstructor   CompletionItemKind = 4
	CompletionItemKindField         CompletionItemKind = 5
	CompletionItemKindVariable      CompletionItemKind = 6
	CompletionItemKindClass         CompletionItemKind = 7
	CompletionItemKindInterface     CompletionItemKind = 8
	CompletionItemKindModule        CompletionItemKind = 9
	CompletionItemKindProperty      CompletionItemKind = 10
	CompletionItemKindUnit          CompletionItemKind = 11
	CompletionItemKindValue         CompletionItemKind = 12
	CompletionItemKindEnum          CompletionItemKind = 13
	CompletionItemKindKeyword       CompletionItemKind = 14
	CompletionItemKindSnippet       CompletionItemKind = 15
	CompletionItemKindColor         CompletionItemKind = 16
	CompletionItemKindFile          CompletionItemKind = 17
	CompletionItemKindReference     CompletionItemKind = 18
	CompletionItemKindFolder        CompletionItemKind = 19
	CompletionItemKindEnumMember    CompletionItemKind = 20
	CompletionItemKindConstant      CompletionItemKind = 21
	CompletionItemKindStruct        CompletionItemKind = 22
	CompletionItemKindEvent         CompletionItemKind = 23
	CompletionItemKindOperator      CompletionItemKind = 24
	CompletionItemKindTypeParameter CompletionItemKind = 25
)

// InsertTextFormat defines the format of the insertion text
type InsertTextFormat int

const (
	// InsertTextFormatPlainText indicates the insertion text is plain text
	InsertTextFormatPlainText InsertTextFormat = 1
	// InsertTextFormatSnippet indicates the insertion text is a snippet
	InsertTextFormatSnippet InsertTextFormat = 2
)

// TextEdit represents a textual change to be applied
type TextEdit struct {
	// Range is the range of the text document to be manipulated
	Range protokoll.Range `json:"range"`
	// NewText is the new text for the provided range
	NewText string `json:"newText"`
}

// Command represents a reference to a command
type Command struct {
	// Title is the title of the command (for display)
	Title string `json:"title"`
	// Command is the identifier of the actual command handler
	Command string `json:"command"`
	// Arguments are the arguments that the command handler should be invoked with
	Arguments []interface{} `json:"arguments,omitempty"`
}
