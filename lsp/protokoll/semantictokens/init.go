package semantictokens

// SemanticTokensClientCapabilities represents the client's capabilities for semantic tokens
type SemanticTokensClientCapabilities struct {
	// DynamicRegistration indicates whether the client supports dynamic registration
	DynamicRegistration bool `json:"dynamicRegistration,omitempty"`
	// Requests specifies which requests the client supports
	Requests struct {
		// Range indicates whether the client supports the range request
		Range bool `json:"range,omitempty"`
		// Full indicates whether the client supports the full request
		Full bool `json:"full,omitempty"`
	} `json:"requests,omitempty"`
	// TokenTypes is an array of token types that the client supports
	TokenTypes []string `json:"tokenTypes,omitempty"`
	// TokenModifiers is an array of token modifiers that the client supports
	TokenModifiers []string `json:"tokenModifiers,omitempty"`
	// Formats is an array of token formats that the client supports
	Formats []string `json:"formats,omitempty"`
	// Overlapping tokens are supported by the client
	OverlappingTokenSupport bool `json:"overlappingTokenSupport,omitempty"`
	// MultilineTokenSupport indicates whether the client supports multiline tokens
	MultilineTokenSupport bool `json:"multilineTokenSupport,omitempty"`
}

// SemanticTokensOptions represents the server's semantic tokens options
type SemanticTokensOptions struct {
	// Legend provides information about the tokens the server supports
	Legend SemanticTokensLegend `json:"legend"`
	// Range indicates whether the server supports range requests
	Range bool `json:"range,omitempty"`
	// Full indicates whether the server supports full document requests
	Full interface{} `json:"full,omitempty"`
}

// SemanticTokensLegend provides information about supported token types and modifiers
type SemanticTokensLegend struct {
	// TokenTypes is an array of supported token types
	TokenTypes []string `json:"tokenTypes"`
	// TokenModifiers is an array of supported token modifiers
	TokenModifiers []string `json:"tokenModifiers"`
}

// Standard token types as defined by the LSP specification
const (
	TokenTypeNamespace  = "namespace"
	TokenTypeType       = "type"
	TokenTypeClass      = "class"
	TokenTypeEnum       = "enum"
	TokenTypeInterface  = "interface"
	TokenTypeStruct     = "struct"
	TokenTypeParameter  = "parameter"
	TokenTypeVariable   = "variable"
	TokenTypeProperty   = "property"
	TokenTypeNumber     = "number"
	TokenTypeEnumMember = "enumMember"
	TokenTypeFunction   = "function"
	TokenTypeComment    = "comment"
	TokenTypeKeyword    = "keyword"
	TokenTypeString     = "string"
	TokenTypeModifier   = "modifier"
	TokenTypeDecorator  = "decorator"
)

// Standard token modifiers as defined by the LSP specification
const (
	TokenModifierDeclaration    = "declaration"
	TokenModifierDefinition     = "definition"
	TokenModifierReadonly       = "readonly"
	TokenModifierStatic         = "static"
	TokenModifierDeprecated     = "deprecated"
	TokenModifierAbstract       = "abstract"
	TokenModifierAsync          = "async"
	TokenModifierModification   = "modification"
	TokenModifierDocumentation  = "documentation"
	TokenModifierDefaultLibrary = "defaultLibrary"
)
