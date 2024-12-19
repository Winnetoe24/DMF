package protokoll

// SymbolKind represents the kind of a symbol
type SymbolKind int

const (
	// SymbolKindFile represents a file symbol
	SymbolKindFile SymbolKind = 1
	// SymbolKindModule represents a module symbol
	SymbolKindModule SymbolKind = 2
	// SymbolKindNamespace represents a namespace symbol
	SymbolKindNamespace SymbolKind = 3
	// SymbolKindPackage represents a package symbol
	SymbolKindPackage SymbolKind = 4
	// SymbolKindClass represents a class symbol
	SymbolKindClass SymbolKind = 5
	// SymbolKindMethod represents a method symbol
	SymbolKindMethod SymbolKind = 6
	// SymbolKindProperty represents a property symbol
	SymbolKindProperty SymbolKind = 7
	// SymbolKindField represents a field symbol
	SymbolKindField SymbolKind = 8
	// SymbolKindConstructor represents a constructor symbol
	SymbolKindConstructor SymbolKind = 9
	// SymbolKindEnum represents an enum symbol
	SymbolKindEnum SymbolKind = 10
	// SymbolKindInterface represents an interface symbol
	SymbolKindInterface SymbolKind = 11
	// SymbolKindFunction represents a function symbol
	SymbolKindFunction SymbolKind = 12
	// SymbolKindVariable represents a variable symbol
	SymbolKindVariable SymbolKind = 13
	// SymbolKindConstant represents a constant symbol
	SymbolKindConstant SymbolKind = 14
	// SymbolKindString represents a string symbol
	SymbolKindString SymbolKind = 15
	// SymbolKindNumber represents a number symbol
	SymbolKindNumber SymbolKind = 16
	// SymbolKindBoolean represents a boolean symbol
	SymbolKindBoolean SymbolKind = 17
	// SymbolKindArray represents an array symbol
	SymbolKindArray SymbolKind = 18
	// SymbolKindObject represents an object symbol
	SymbolKindObject SymbolKind = 19
	// SymbolKindKey represents a key symbol
	SymbolKindKey SymbolKind = 20
	// SymbolKindNull represents a null symbol
	SymbolKindNull SymbolKind = 21
	// SymbolKindEnumMember represents an enum member symbol
	SymbolKindEnumMember SymbolKind = 22
	// SymbolKindStruct represents a struct symbol
	SymbolKindStruct SymbolKind = 23
	// SymbolKindEvent represents an event symbol
	SymbolKindEvent SymbolKind = 24
	// SymbolKindOperator represents an operator symbol
	SymbolKindOperator SymbolKind = 25
	// SymbolKindTypeParameter represents a type parameter symbol
	SymbolKindTypeParameter SymbolKind = 26
)

// SymbolTag represents the tag of a symbol
type SymbolTag int

const (
	// SymbolTagDeprecated marks a symbol as deprecated
	SymbolTagDeprecated SymbolTag = 1
)

// SymbolInformation represents information about a symbol
type SymbolInformation struct {
	// The name of the symbol
	Name string `json:"name"`

	// The kind of the symbol
	Kind SymbolKind `json:"kind"`

	// Tags associated with the symbol
	Tags []SymbolTag `json:"tags,omitempty"`

	// The container name of the symbol
	ContainerName string `json:"containerName,omitempty"`

	// The location of the symbol
	Location Location `json:"location"`

	// Optional extra data
	Data interface{} `json:"data,omitempty"`
}

// DocumentSymbol represents a symbol in a document with hierarchical structure
type DocumentSymbol struct {
	// The name of the symbol
	Name string `json:"name"`

	// The detail of the symbol
	Detail string `json:"detail,omitempty"`

	// The kind of the symbol
	Kind SymbolKind `json:"kind"`

	// Tags associated with the symbol
	Tags []SymbolTag `json:"tags,omitempty"`

	// The range enclosing this symbol
	Range Range `json:"range"`

	// The range that should be selected for this symbol
	SelectionRange Range `json:"selectionRange"`

	// Child symbols contained in this symbol
	Children []DocumentSymbol `json:"children,omitempty"`
}

// String returns the string representation of the SymbolKind
func (s SymbolKind) String() string {
	switch s {
	case SymbolKindFile:
		return "File"
	case SymbolKindModule:
		return "Module"
	case SymbolKindNamespace:
		return "Namespace"
	case SymbolKindPackage:
		return "Package"
	case SymbolKindClass:
		return "Class"
	case SymbolKindMethod:
		return "Method"
	case SymbolKindProperty:
		return "Property"
	case SymbolKindField:
		return "Field"
	case SymbolKindConstructor:
		return "Constructor"
	case SymbolKindEnum:
		return "Enum"
	case SymbolKindInterface:
		return "Interface"
	case SymbolKindFunction:
		return "Function"
	case SymbolKindVariable:
		return "Variable"
	case SymbolKindConstant:
		return "Constant"
	case SymbolKindString:
		return "String"
	case SymbolKindNumber:
		return "Number"
	case SymbolKindBoolean:
		return "Boolean"
	case SymbolKindArray:
		return "Array"
	case SymbolKindObject:
		return "Object"
	case SymbolKindKey:
		return "Key"
	case SymbolKindNull:
		return "Null"
	case SymbolKindEnumMember:
		return "EnumMember"
	case SymbolKindStruct:
		return "Struct"
	case SymbolKindEvent:
		return "Event"
	case SymbolKindOperator:
		return "Operator"
	case SymbolKindTypeParameter:
		return "TypeParameter"
	default:
		return "Unknown"
	}
}

// IsValidSymbolKind checks if a symbol kind is valid
func IsValidSymbolKind(kind SymbolKind) bool {
	return kind >= SymbolKindFile && kind <= SymbolKindTypeParameter
}

// GetSymbolKindFromString converts a string to a SymbolKind
func GetSymbolKindFromString(s string) (SymbolKind, bool) {
	switch s {
	case "File":
		return SymbolKindFile, true
	case "Module":
		return SymbolKindModule, true
	case "Namespace":
		return SymbolKindNamespace, true
	case "Package":
		return SymbolKindPackage, true
	case "Class":
		return SymbolKindClass, true
	case "Method":
		return SymbolKindMethod, true
	case "Property":
		return SymbolKindProperty, true
	case "Field":
		return SymbolKindField, true
	case "Constructor":
		return SymbolKindConstructor, true
	case "Enum":
		return SymbolKindEnum, true
	case "Interface":
		return SymbolKindInterface, true
	case "Function":
		return SymbolKindFunction, true
	case "Variable":
		return SymbolKindVariable, true
	case "Constant":
		return SymbolKindConstant, true
	case "String":
		return SymbolKindString, true
	case "Number":
		return SymbolKindNumber, true
	case "Boolean":
		return SymbolKindBoolean, true
	case "Array":
		return SymbolKindArray, true
	case "Object":
		return SymbolKindObject, true
	case "Key":
		return SymbolKindKey, true
	case "Null":
		return SymbolKindNull, true
	case "EnumMember":
		return SymbolKindEnumMember, true
	case "Struct":
		return SymbolKindStruct, true
	case "Event":
		return SymbolKindEvent, true
	case "Operator":
		return SymbolKindOperator, true
	case "TypeParameter":
		return SymbolKindTypeParameter, true
	default:
		return 0, false
	}
}
