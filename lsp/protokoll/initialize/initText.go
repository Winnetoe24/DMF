package initialize

import "github.com/Winnetoe24/DMF/lsp/protokoll/textEdit"

// TextDocumentClientCapabilities describes capabilities the editor / tool provides
// related to text documents.
type TextDocumentClientCapabilities struct {
	// Synchronization defines which synchronization capabilities the client supports
	Synchronization *textEdit.TextDocumentSyncClientCapabilities `json:"synchronization,omitempty"`

	//// Completion capabilities of the client
	//Completion *CompletionClientCapabilities `json:"completion,omitempty"`
	//
	//// Hover capabilities of the client
	//Hover *HoverClientCapabilities `json:"hover,omitempty"`
	//
	//// SignatureHelp capabilities of the client
	//SignatureHelp *SignatureHelpClientCapabilities `json:"signatureHelp,omitempty"`
	//
	//// Declaration capabilities of the client
	//Declaration *DeclarationClientCapabilities `json:"declaration,omitempty"`
	//
	//// Definition capabilities of the client
	//Definition *DefinitionClientCapabilities `json:"definition,omitempty"`
	//
	//// TypeDefinition capabilities of the client
	//TypeDefinition *TypeDefinitionClientCapabilities `json:"typeDefinition,omitempty"`
	//
	//// Implementation capabilities of the client
	//Implementation *ImplementationClientCapabilities `json:"implementation,omitempty"`
	//
	//// References capabilities of the client
	//References *ReferenceClientCapabilities `json:"references,omitempty"`
	//
	//// DocumentHighlight capabilities of the client
	//DocumentHighlight *DocumentHighlightClientCapabilities `json:"documentHighlight,omitempty"`
	//
	//// DocumentSymbol capabilities of the client
	//DocumentSymbol *DocumentSymbolClientCapabilities `json:"documentSymbol,omitempty"`
	//
	//// CodeAction capabilities of the client
	//CodeAction *CodeActionClientCapabilities `json:"codeAction,omitempty"`
	//
	//// CodeLens capabilities of the client
	//CodeLens *CodeLensClientCapabilities `json:"codeLens,omitempty"`
	//
	//// DocumentLink capabilities of the client
	//DocumentLink *DocumentLinkClientCapabilities `json:"documentLink,omitempty"`
	//
	//// DocumentColor capabilities of the client
	//ColorProvider *DocumentColorClientCapabilities `json:"colorProvider,omitempty"`
	//
	//// Formatting capabilities of the client
	//Formatting *DocumentFormattingClientCapabilities `json:"formatting,omitempty"`
	//
	//// RangeFormatting capabilities of the client
	//RangeFormatting *DocumentRangeFormattingClientCapabilities `json:"rangeFormatting,omitempty"`
	//
	//// OnTypeFormatting capabilities of the client
	//OnTypeFormatting *DocumentOnTypeFormattingClientCapabilities `json:"onTypeFormatting,omitempty"`
	//
	//// Rename capabilities of the client
	//Rename *RenameClientCapabilities `json:"rename,omitempty"`
	//
	// PublishDiagnostics capabilities of the client
	PublishDiagnostics *PublishDiagnosticsClientCapabilities `json:"publishDiagnostics,omitempty"`
	//
	//// FoldingRange capabilities of the client
	//FoldingRange *FoldingRangeClientCapabilities `json:"foldingRange,omitempty"`
	//
	//// SelectionRange capabilities of the client
	//SelectionRange *SelectionRangeClientCapabilities `json:"selectionRange,omitempty"`
	//
	//// LinkedEditingRange capabilities of the client
	//LinkedEditingRange *LinkedEditingRangeClientCapabilities `json:"linkedEditingRange,omitempty"`
	//
	//// CallHierarchy capabilities of the client
	//CallHierarchy *CallHierarchyClientCapabilities `json:"callHierarchy,omitempty"`
	//
	//// SemanticTokens capabilities of the client
	//SemanticTokens *SemanticTokensClientCapabilities `json:"semanticTokens,omitempty"`
	//
	//// Moniker capabilities of the client
	//Moniker *MonikerClientCapabilities `json:"moniker,omitempty"`
}

// TextDocumentServerCapabilities describes capabilities the server provides
// related to text documents.
type TextDocumentServerCapabilities struct {
	// Synchronization defines how text document syncing is handled
	Synchronization *textEdit.TextDocumentSyncOptions `json:"synchronization,omitempty"`

	// Completion provider options
	CompletionProvider *CompletionOptions `json:"completionProvider,omitempty"`

	// Hover provider options
	HoverProvider interface{} `json:"hoverProvider,omitempty"` // can be bool or HoverOptions

	// SignatureHelp provider options
	SignatureHelpProvider *SignatureHelpOptions `json:"signatureHelpProvider,omitempty"`

	// Declaration provider options
	DeclarationProvider interface{} `json:"declarationProvider,omitempty"` // can be bool or DeclarationOptions or DeclarationRegistrationOptions

	// Definition provider options
	DefinitionProvider interface{} `json:"definitionProvider,omitempty"` // can be bool or DefinitionOptions

	// TypeDefinition provider options
	TypeDefinitionProvider interface{} `json:"typeDefinitionProvider,omitempty"` // can be bool or TypeDefinitionOptions or TypeDefinitionRegistrationOptions

	// Implementation provider options
	ImplementationProvider interface{} `json:"implementationProvider,omitempty"` // can be bool or ImplementationOptions or ImplementationRegistrationOptions

	// References provider options
	ReferencesProvider interface{} `json:"referencesProvider,omitempty"` // can be bool or ReferenceOptions

	// DocumentHighlight provider options
	DocumentHighlightProvider interface{} `json:"documentHighlightProvider,omitempty"` // can be bool or DocumentHighlightOptions

	// DocumentSymbol provider options
	DocumentSymbolProvider interface{} `json:"documentSymbolProvider,omitempty"` // can be bool or DocumentSymbolOptions

	// CodeAction provider options
	CodeActionProvider interface{} `json:"codeActionProvider,omitempty"` // can be bool or CodeActionOptions

	// CodeLens provider options
	CodeLensProvider *CodeLensOptions `json:"codeLensProvider,omitempty"`

	// DocumentLink provider options
	DocumentLinkProvider *DocumentLinkOptions `json:"documentLinkProvider,omitempty"`

	// DocumentColor provider options
	ColorProvider interface{} `json:"colorProvider,omitempty"` // can be bool or DocumentColorOptions or DocumentColorRegistrationOptions

	// Document formatting provider options
	DocumentFormattingProvider interface{} `json:"documentFormattingProvider,omitempty"` // can be bool or DocumentFormattingOptions

	// Document range formatting provider options
	DocumentRangeFormattingProvider interface{} `json:"documentRangeFormattingProvider,omitempty"` // can be bool or DocumentRangeFormattingOptions

	// Document formatting provider options
	DocumentOnTypeFormattingProvider *DocumentOnTypeFormattingOptions `json:"documentOnTypeFormattingProvider,omitempty"`

	// Rename provider options
	RenameProvider interface{} `json:"renameProvider,omitempty"` // can be bool or RenameOptions

	// FoldingRange provider options
	FoldingRangeProvider interface{} `json:"foldingRangeProvider,omitempty"` // can be bool or FoldingRangeOptions or FoldingRangeRegistrationOptions

	// ExecuteCommand provider options
	ExecuteCommandProvider *ExecuteCommandOptions `json:"executeCommandProvider,omitempty"`

	// Selection range provider options
	SelectionRangeProvider interface{} `json:"selectionRangeProvider,omitempty"` // can be bool or SelectionRangeOptions or SelectionRangeRegistrationOptions

	// LinkedEditing range provider options
	LinkedEditingRangeProvider interface{} `json:"linkedEditingRangeProvider,omitempty"` // can be bool or LinkedEditingRangeOptions or LinkedEditingRangeRegistrationOptions

	// Call hierarchy provider options
	CallHierarchyProvider interface{} `json:"callHierarchyProvider,omitempty"` // can be bool or CallHierarchyOptions or CallHierarchyRegistrationOptions

	// Semantic tokens provider options
	SemanticTokensProvider interface{} `json:"semanticTokensProvider,omitempty"` // can be SemanticTokensOptions or SemanticTokensRegistrationOptions

	// Moniker provider options
	MonikerProvider interface{} `json:"monikerProvider,omitempty"` // can be bool or MonikerOptions or MonikerRegistrationOptions

	// Workspace symbol provider options
	WorkspaceSymbolProvider interface{} `json:"workspaceSymbolProvider,omitempty"` // can be bool or WorkspaceSymbolOptions
}
