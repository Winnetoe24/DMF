package initialize

import (
	"github.com/Winnetoe24/DMF/lsp/protokoll"
)

// InitializeParams represents the parameters sent in an initialize request
type InitializeParams struct {
	// The process ID of the parent process that started the server
	ProcessID *int32 `json:"processId,omitempty"`

	// The rootPath of the workspace. Deprecated in favor of RootURI
	RootPath string `json:"rootPath,omitempty"`

	// The rootUri of the workspace
	RootURI protokoll.DocumentURI `json:"rootUri"`

	// User provided initialization options
	InitializationOptions interface{} `json:"initializationOptions,omitempty"`

	// The capabilities provided by the client (editor or tool)
	Capabilities ClientCapabilities `json:"capabilities"`

	// The initial trace setting
	Trace string `json:"trace,omitempty"`

	// The workspace folders
	WorkspaceFolders []WorkspaceFolder `json:"workspaceFolders,omitempty"`
}

// WorkspaceFolder represents a workspace folder
type WorkspaceFolder struct {
	// The associated URI for this workspace folder
	URI protokoll.DocumentURI `json:"uri"`

	// The name of the workspace folder
	Name string `json:"name"`
}

// ClientCapabilities represents the capabilities provided by the client
type ClientCapabilities struct {
	// Workspace specific client capabilities
	Workspace *WorkspaceClientCapabilities `json:"workspace,omitempty"`

	// Text document specific client capabilities
	TextDocument *TextDocumentClientCapabilities `json:"textDocument,omitempty"`

	// Window specific client capabilities
	Window *WindowClientCapabilities `json:"window,omitempty"`

	// General client capabilities
	General *GeneralClientCapabilities `json:"general,omitempty"`

	// Experimental client capabilities
	Experimental interface{} `json:"experimental,omitempty"`
}

// WorkspaceClientCapabilities represents the workspace capabilities of the client
type WorkspaceClientCapabilities struct {
	// The client supports applying batch edits to the workspace
	ApplyEdit bool `json:"applyEdit,omitempty"`

	// Workspace edit capabilities
	WorkspaceEdit *WorkspaceEditCapabilities `json:"workspaceEdit,omitempty"`

	// Did change configuration notification capabilities
	DidChangeConfiguration *DidChangeConfigurationCapabilities `json:"didChangeConfiguration,omitempty"`

	// Did change watched files notification capabilities
	DidChangeWatchedFiles *DidChangeWatchedFilesCapabilities `json:"didChangeWatchedFiles,omitempty"`

	// Symbol capabilities
	Symbol *WorkspaceSymbolCapabilities `json:"symbol,omitempty"`

	// Execute command capabilities
	ExecuteCommand *ExecuteCommandCapabilities `json:"executeCommand,omitempty"`

	// Workspace folders support
	WorkspaceFolders bool `json:"workspaceFolders,omitempty"`

	// The client supports file operations
	FileOperations *FileOperationCapabilities `json:"fileOperations,omitempty"`
}

// ServerCapabilities represents the capabilities provided by the language server
type ServerCapabilities struct {
	// Position encoding supported by the server
	PositionEncoding protokoll.PositionEncodingKind `json:"positionEncoding,omitempty"`

	// Text document sync options
	TextDocumentSync interface{} `json:"textDocumentSync,omitempty"`

	// The server provides completion support
	CompletionProvider *CompletionOptions `json:"completionProvider,omitempty"`

	// The server provides hover support
	HoverProvider bool `json:"hoverProvider,omitempty"`

	// The server provides signature help support
	SignatureHelpProvider *SignatureHelpOptions `json:"signatureHelpProvider,omitempty"`

	// The server provides go to declaration support
	DeclarationProvider bool `json:"declarationProvider,omitempty"`

	// The server provides goto definition support
	DefinitionProvider bool `json:"definitionProvider,omitempty"`

	// The server provides goto type definition support
	TypeDefinitionProvider interface{} `json:"typeDefinitionProvider,omitempty"`

	// The server provides goto implementation support
	ImplementationProvider interface{} `json:"implementationProvider,omitempty"`

	// The server provides find references support
	ReferencesProvider bool `json:"referencesProvider,omitempty"`

	// The server provides document highlight support
	DocumentHighlightProvider bool `json:"documentHighlightProvider,omitempty"`

	// The server provides document symbol support
	DocumentSymbolProvider bool `json:"documentSymbolProvider,omitempty"`

	// The server provides workspace symbol support
	WorkspaceSymbolProvider bool `json:"workspaceSymbolProvider,omitempty"`

	// The server provides code actions
	CodeActionProvider interface{} `json:"codeActionProvider,omitempty"`

	// The server provides code lens
	CodeLensProvider *CodeLensOptions `json:"codeLensProvider,omitempty"`

	// The server provides document formatting
	DocumentFormattingProvider bool `json:"documentFormattingProvider,omitempty"`

	// The server provides document range formatting
	DocumentRangeFormattingProvider bool `json:"documentRangeFormattingProvider,omitempty"`

	// The server provides document formatting on typing
	DocumentOnTypeFormattingProvider *DocumentOnTypeFormattingOptions `json:"documentOnTypeFormattingProvider,omitempty"`

	// The server provides rename support
	RenameProvider interface{} `json:"renameProvider,omitempty"`

	// The server provides document link support
	DocumentLinkProvider *DocumentLinkOptions `json:"documentLinkProvider,omitempty"`

	// The server provides color support
	ColorProvider interface{} `json:"colorProvider,omitempty"`

	// The server provides folding range support
	FoldingRangeProvider interface{} `json:"foldingRangeProvider,omitempty"`

	// The server provides execute command support
	ExecuteCommandProvider *ExecuteCommandOptions `json:"executeCommandProvider,omitempty"`

	// The server provides call hierarchy support
	CallHierarchyProvider interface{} `json:"callHierarchyProvider,omitempty"`

	// The server provides selection range support
	SelectionRangeProvider interface{} `json:"selectionRangeProvider,omitempty"`

	// The server provides linked editing range support
	LinkedEditingRangeProvider interface{} `json:"linkedEditingRangeProvider,omitempty"`

	// The server provides semantic tokens support
	SemanticTokensProvider interface{} `json:"semanticTokensProvider,omitempty"`

	// The server provides moniker support
	MonikerProvider interface{} `json:"monikerProvider,omitempty"`

	DiagnosticOptions *DiagnosticOptions `json:"diagnosticProvider,omitempty"`

	// Workspace specific server capabilities
	Workspace *WorkspaceServerCapabilities `json:"workspace,omitempty"`

	// Experimental server capabilities
	Experimental interface{} `json:"experimental,omitempty"`
}

// InitializeResult represents the result of an initialize request
type InitializeResult struct {
	// The capabilities the language server provides
	Capabilities ServerCapabilities `json:"capabilities"`

	// Information about the server
	ServerInfo *ServerInfo `json:"serverInfo,omitempty"`
}

// ServerInfo represents information about the server
type ServerInfo struct {
	// The name of the server
	Name string `json:"name"`

	// The server's version
	Version string `json:"version,omitempty"`
}

// CompletionOptions represents completion options
type CompletionOptions struct {
	// Whether the server supports providing additional text edits
	ResolveProvider bool `json:"resolveProvider,omitempty"`

	// Characters that trigger completion
	TriggerCharacters []string `json:"triggerCharacters,omitempty"`

	// Characters that re-trigger completion
	AllCommitCharacters []string `json:"allCommitCharacters,omitempty"`
}

// CodeLensOptions represents code lens options
type CodeLensOptions struct {
	// Whether the server supports resolving additional code lens information
	ResolveProvider bool `json:"resolveProvider,omitempty"`
}

// DocumentOnTypeFormattingOptions represents on type formatting options
type DocumentOnTypeFormattingOptions struct {
	// Character that triggers formatting
	FirstTriggerCharacter string `json:"firstTriggerCharacter"`

	// Additional characters that trigger formatting
	MoreTriggerCharacter []string `json:"moreTriggerCharacter,omitempty"`
}

// DocumentLinkOptions represents document link options
type DocumentLinkOptions struct {
	// Whether the server supports resolving additional information for a document link
	ResolveProvider bool `json:"resolveProvider,omitempty"`
}

// ExecuteCommandOptions represents execute command options
type ExecuteCommandOptions struct {
	// List of commands supported by the server
	Commands []string `json:"commands"`
}

// WorkspaceServerCapabilities represents workspace-specific server capabilities
type WorkspaceServerCapabilities struct {
	// Workspace folders configuration
	WorkspaceFolders *WorkspaceFoldersServerCapabilities `json:"workspaceFolders,omitempty"`

	// File operations configuration
	FileOperations *FileOperationOptions `json:"fileOperations,omitempty"`
}

// WorkspaceFoldersServerCapabilities represents workspace folders capabilities
type WorkspaceFoldersServerCapabilities struct {
	// Whether the server supports workspace folders
	Supported bool `json:"supported,omitempty"`

	// Whether the server allows workspace folders to be changed
	ChangeNotifications bool `json:"changeNotifications,omitempty"`
}

// WindowClientCapabilities represents the client's window capabilities
type WindowClientCapabilities struct {
	// Whether the client supports handling work done progress
	WorkDoneProgress bool `json:"workDoneProgress,omitempty"`

	// Capabilities specific to the showMessage request
	ShowMessage *ShowMessageRequestClientCapabilities `json:"showMessage,omitempty"`

	// Capabilities specific to the showDocument request
	ShowDocument *ShowDocumentClientCapabilities `json:"showDocument,omitempty"`
}

// ShowMessageRequestClientCapabilities represents the client's showMessage capabilities
type ShowMessageRequestClientCapabilities struct {
	// Capabilities specific to the MessageActionItem
	MessageActionItem *MessageActionItemCapabilities `json:"messageActionItem,omitempty"`
}

// MessageActionItemCapabilities represents MessageActionItem capabilities
type MessageActionItemCapabilities struct {
	// Whether the client supports additional attributes which
	// are preserved and sent back to the server in the request
	AdditionalPropertiesSupport bool `json:"additionalPropertiesSupport,omitempty"`
}

// ShowDocumentClientCapabilities represents the client's showDocument capabilities
type ShowDocumentClientCapabilities struct {
	// The client supports opening documents provided by the server
	Support bool `json:"support"`
}

// GeneralClientCapabilities represents the general client capabilities
type GeneralClientCapabilities struct {
	// Client supports regexes in pattern or glob parameters
	RegularExpressions *RegularExpressionsClientCapabilities `json:"regularExpressions,omitempty"`

	// Client supports the markdown format
	Markdown *MarkdownClientCapabilities `json:"markdown,omitempty"`

	// Client supports position encodings
	PositionEncodings []protokoll.PositionEncodingKind `json:"positionEncodings,omitempty"`

	// Client supports stale requests (e.g., versioned document changes)
	StaleRequestSupport *StaleRequestSupportClientCapabilities `json:"staleRequestSupport,omitempty"`
}

// RegularExpressionsClientCapabilities represents regex capabilities
type RegularExpressionsClientCapabilities struct {
	// The engine's name
	Engine string `json:"engine"`

	// The engine's version
	Version string `json:"version,omitempty"`
}

// MarkdownClientCapabilities represents markdown capabilities
type MarkdownClientCapabilities struct {
	// The parser's name
	Parser string `json:"parser"`

	// The parser's version
	Version string `json:"version,omitempty"`

	// A list of supported content formats
	AllowedTags []string `json:"allowedTags,omitempty"`
}

// StaleRequestSupportClientCapabilities represents stale request support
type StaleRequestSupportClientCapabilities struct {
	// The client will actively cancel the request
	Cancel bool `json:"cancel"`

	// The list of requests for which the client will retry the request if it receives a response with error code 'ContentModified`
	RetryOnContentModified []string `json:"retryOnContentModified"`
}

// WorkspaceEditCapabilities represents workspace edit capabilities
type WorkspaceEditCapabilities struct {
	// The client supports versioned document changes
	DocumentChanges bool `json:"documentChanges,omitempty"`

	// The client supports resource operations
	ResourceOperations []ResourceOperationKind `json:"resourceOperations,omitempty"`

	// The client supports failure handling
	FailureHandling *FailureHandlingKind `json:"failureHandling,omitempty"`

	// Whether the client normalizes line endings
	NormalizesLineEndings bool `json:"normalizesLineEndings,omitempty"`

	// Whether the client supports change annotations
	ChangeAnnotationSupport *ChangeAnnotationSupport `json:"changeAnnotationSupport,omitempty"`
}

// ResourceOperationKind represents kinds of resource operations
type ResourceOperationKind string

const (
	// Create represents the create operation
	Create ResourceOperationKind = "create"
	// Rename represents the rename operation
	Rename ResourceOperationKind = "rename"
	// Delete represents the delete operation
	Delete ResourceOperationKind = "delete"
)

// FailureHandlingKind represents kinds of failure handling
type FailureHandlingKind string

const (
	// Abort indicates to abort the operation if one operation fails
	Abort FailureHandlingKind = "abort"
	// Transactional indicates to undo all operations if one fails
	Transactional FailureHandlingKind = "transactional"
	// TextOnlyTransactional indicates to undo all text edits if one fails
	TextOnlyTransactional FailureHandlingKind = "textOnlyTransactional"
	// Undo indicates to undo the failed operation
	Undo FailureHandlingKind = "undo"
)

// ChangeAnnotationSupport represents support for change annotations
type ChangeAnnotationSupport struct {
	// Whether the client supports grouping annotations
	GroupsOnLabel bool `json:"groupsOnLabel,omitempty"`
}

// DidChangeConfigurationCapabilities represents configuration change capabilities
type DidChangeConfigurationCapabilities struct {
	// Whether the client supports dynamic registration
	DynamicRegistration bool `json:"dynamicRegistration,omitempty"`
}

// DidChangeWatchedFilesCapabilities represents file watching capabilities
type DidChangeWatchedFilesCapabilities struct {
	// Whether the client supports dynamic registration
	DynamicRegistration bool `json:"dynamicRegistration,omitempty"`

	// Whether the client has support for relative patterns
	RelativePatternSupport bool `json:"relativePatternSupport,omitempty"`
}

// WorkspaceSymbolCapabilities represents workspace symbol capabilities
type WorkspaceSymbolCapabilities struct {
	// Whether the client supports dynamic registration
	DynamicRegistration bool `json:"dynamicRegistration,omitempty"`

	// Specific capabilities for the SymbolKind
	SymbolKind *struct {
		// The symbol kind values the client supports
		ValueSet []protokoll.SymbolKind `json:"valueSet,omitempty"`
	} `json:"symbolKind,omitempty"`

	// The client supports tags on SymbolInformation
	TagSupport *struct {
		// The tags supported by the client
		ValueSet []protokoll.SymbolTag `json:"valueSet"`
	} `json:"tagSupport,omitempty"`

	// The client supports resolving additional information for a workspace symbol
	ResolveSupport *struct {
		// The properties that a client can resolve lazily
		Properties []string `json:"properties"`
	} `json:"resolveSupport,omitempty"`
}

// ExecuteCommandCapabilities represents execute command capabilities
type ExecuteCommandCapabilities struct {
	// Whether the client supports dynamic registration
	DynamicRegistration bool `json:"dynamicRegistration,omitempty"`
}

// FileOperationCapabilities represents file operation capabilities
type FileOperationCapabilities struct {
	// Whether the client supports dynamic registration for file operations
	DynamicRegistration bool `json:"dynamicRegistration,omitempty"`

	// Whether the client supports sending didCreateFiles notifications
	DidCreate bool `json:"didCreate,omitempty"`

	// Whether the client supports sending willCreateFiles requests
	WillCreate bool `json:"willCreate,omitempty"`

	// Whether the client supports sending didRenameFiles notifications
	DidRename bool `json:"didRename,omitempty"`

	// Whether the client supports sending willRenameFiles requests
	WillRename bool `json:"willRename,omitempty"`

	// Whether the client supports sending didDeleteFiles notifications
	DidDelete bool `json:"didDelete,omitempty"`

	// Whether the client supports sending willDeleteFiles requests
	WillDelete bool `json:"willDelete,omitempty"`
}

// SignatureHelpOptions represents signature help options
type SignatureHelpOptions struct {
	// The characters that trigger signature help
	TriggerCharacters []string `json:"triggerCharacters,omitempty"`

	// The characters that re-trigger signature help
	RetriggerCharacters []string `json:"retriggerCharacters,omitempty"`
}

// FileOperationOptions represents server capabilities for file operations
type FileOperationOptions struct {
	// The server is interested in receiving didCreateFiles notifications
	DidCreate *FileOperationRegistrationOptions `json:"didCreate,omitempty"`

	// The server is interested in receiving willCreateFiles requests
	WillCreate *FileOperationRegistrationOptions `json:"willCreate,omitempty"`

	// The server is interested in receiving didRenameFiles notifications
	DidRename *FileOperationRegistrationOptions `json:"didRename,omitempty"`

	// The server is interested in receiving willRenameFiles requests
	WillRename *FileOperationRegistrationOptions `json:"willRename,omitempty"`

	// The server is interested in receiving didDeleteFiles notifications
	DidDelete *FileOperationRegistrationOptions `json:"didDelete,omitempty"`

	// The server is interested in receiving willDeleteFiles requests
	WillDelete *FileOperationRegistrationOptions `json:"willDelete,omitempty"`
}

// FileOperationRegistrationOptions represents file operation registration options
type FileOperationRegistrationOptions struct {
	// The actual filters
	Filters []FileOperationFilter `json:"filters"`
}

// FileOperationFilter represents a filter for file operations
type FileOperationFilter struct {
	// A glob pattern for matching file paths
	Pattern FileOperationPattern `json:"pattern"`

	// A set of file operations to which this filter applies
	Scheme string `json:"scheme,omitempty"`
}

// FileOperationPattern represents a pattern for matching file paths
type FileOperationPattern struct {
	// The glob pattern to match
	Glob string `json:"glob"`

	// Whether the pattern matches a folder
	Matches *FileOperationPatternKind `json:"matches,omitempty"`

	// Additional options
	Options *FileOperationPatternOptions `json:"options,omitempty"`
}

// FileOperationPatternKind represents kinds of file operation patterns
type FileOperationPatternKind string

const (
	// FileOperationPatternKindFile matches files only
	FileOperationPatternKindFile FileOperationPatternKind = "file"
	// FileOperationPatternKindFolder matches folders only
	FileOperationPatternKindFolder FileOperationPatternKind = "folder"
)

// FileOperationPatternOptions represents options for file operation patterns
type FileOperationPatternOptions struct {
	// Whether to ignore case
	IgnoreCase bool `json:"ignoreCase,omitempty"`
}
