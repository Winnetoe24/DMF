package semantictokensService

import (
	"cmp"
	"encoding/json"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/protokoll/initialize"
	"github.com/Winnetoe24/DMF/lsp/protokoll/semantictokens"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/server/connect/connectUtils"
	"github.com/Winnetoe24/DMF/lsp/service"
	"github.com/Winnetoe24/DMF/lsp/service/fileService"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages/values"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"slices"
)

const semantictokensFullMethod = "textDocument/semanticTokens/full"

type SemanticTokensService struct {
	con connect.Connection
	fs  *fileService.FileService
}

func NewSemanticTokensService(connection connect.Connection, fs *fileService.FileService) *SemanticTokensService {
	return &SemanticTokensService{
		con: connection,
		fs:  fs,
	}
}

var _ service.MethodHandler = &SemanticTokensService{}

const (
	indexNamespace  = iota
	indexType       = iota
	indexClass      = iota
	indexEnum       = iota
	indexInterface  = iota
	indexStruct     = iota
	indexParameter  = iota
	indexVariable   = iota
	indexProperty   = iota
	indexNumber     = iota
	indexEnumMember = iota
	indexFunction   = iota
	indexComment    = iota
	indexKeyword    = iota
	indexString     = iota
	indexModifier   = iota
	indexDecorator  = iota
)

var tokenTypes = []string{
	semantictokens.TokenTypeNamespace,
	semantictokens.TokenTypeType,
	semantictokens.TokenTypeClass,
	semantictokens.TokenTypeEnum,
	semantictokens.TokenTypeInterface,
	semantictokens.TokenTypeStruct,
	semantictokens.TokenTypeParameter,
	semantictokens.TokenTypeVariable,
	semantictokens.TokenTypeProperty,
	semantictokens.TokenTypeNumber,
	semantictokens.TokenTypeEnumMember,
	semantictokens.TokenTypeFunction,
	semantictokens.TokenTypeComment,
	semantictokens.TokenTypeKeyword,
	semantictokens.TokenTypeString,
	semantictokens.TokenTypeModifier,
	semantictokens.TokenTypeDecorator,
}

const (
	indexNothing       = iota
	indexDeclaration   = iota
	indexDefinition    = iota
	indexReadonly      = iota
	indexDeprecated    = iota
	indexStatic        = iota
	indexDocumentation = iota
)

var tokenModifiers = []string{
	semantictokens.TokenModifierDeclaration,
	semantictokens.TokenModifierDefinition,
	semantictokens.TokenModifierReadonly,
	semantictokens.TokenModifierDeprecated,
	semantictokens.TokenModifierStatic,
	semantictokens.TokenModifierDocumentation,
}

type semanticElement struct {
	line           uint32
	start          uint32
	length         uint32
	tokenType      uint32
	tokenModifiers uint32
}

func (s *SemanticTokensService) Initialize(params *initialize.InitializeParams, result *initialize.InitializeResult) {
	// Set up semantic tokens capabilities
	result.Capabilities.SemanticTokensProvider = &semantictokens.SemanticTokensOptions{
		Legend: semantictokens.SemanticTokensLegend{
			TokenTypes:     tokenTypes,
			TokenModifiers: tokenModifiers,
		},
		Full: struct {
			Delta bool
		}{Delta: false},
	}
}

func (s *SemanticTokensService) GetMethods() []string {
	return []string{semantictokensFullMethod}
}

func (s *SemanticTokensService) HandleMethod(message protokoll.Message) {
	switch message.Method {
	case semantictokensFullMethod:
		params := semantictokens.SemanticTokensParams{}
		err := json.Unmarshal(message.Params, &params)
		if err != nil {
			connectUtils.WriteErrorToCon(s.con, message.ID, err, protokoll.ParseError)
			return
		}

		content, err := s.fs.GetFileContent(params.TextDocument.URI)
		defer content.Close()
		if err != nil {
			connectUtils.WriteErrorToCon(s.con, message.ID, err, protokoll.InternalError)
			return
		}

		tokens := s.computeSemanticTokens(content)

		s.con.WriteMessage(protokoll.Message{
			JsonRPC: "2.0",
			ID:      message.ID,
			Result:  tokens,
		})
	}
}

func (s *SemanticTokensService) computeSemanticTokens(content fileService.FileContent) semantictokens.SemanticTokens {
	var semanticElements = make([]*semanticElement, 0)

	// Helper function to add a token
	addToken := func(line, start uint32, length uint32, tokenType uint32, tokenModifiers uint32) {
		semanticElements = append(semanticElements, &semanticElement{
			line:           line,
			start:          start,
			length:         length,
			tokenType:      tokenType,
			tokenModifiers: tokenModifiers,
		})
	}
	byteContent := []byte(content.Content)
	addTokenWrapper := func(cNode *tree_sitter.Node, tokenType int, tokenModifiers ...int) {
		if cNode == nil {
			return
		}
		startPosition := cNode.StartPosition()
		text := cNode.Utf8Text(byteContent)
		modifier := uint32(0)
		for _, tokenModifier := range tokenModifiers {
			cMod := uint32(1)
			cMod = cMod << tokenModifier
			modifier |= cMod
		}
		addToken(uint32(startPosition.Row), uint32(startPosition.Column), uint32(len(text)), uint32(tokenType), modifier)
	}

	cursor := content.Ast.Walk()
	//logger := logService.GetLogger()
	//logger.Printf("%s Call Walk:\n", logService.TRACE)
	s.WalkNode(cursor, addTokenWrapper)
	// Process all elements in the lookup
	//logger.Printf("%s Call Walk:\n", logService.TRACE)

	s.walkElements(content, addTokenWrapper)

	slices.SortFunc(semanticElements, func(a, b *semanticElement) int {
		if a.line == b.line {
			return cmp.Compare(a.start, b.start)
		}
		return cmp.Compare(a.line, b.line)
	})
	data := make([]uint32, len(semanticElements)*5)

	lastLine := uint32(0)
	lastStart := uint32(0)

	for i, element := range semanticElements {
		line := element.line
		start := element.start
		length := element.length
		tokenType := element.tokenType
		tokenModifiers := element.tokenModifiers
		if line < lastLine {
			// Tokens must be sorted by line and character
			continue
		}

		if line == lastLine && start < lastStart {
			// Tokens must be sorted by line and character
			continue
		}

		// Calculate delta encoding
		deltaLine := line - lastLine
		deltaStart := uint32(0)
		if line == lastLine {
			deltaStart = start - lastStart
		} else {
			deltaStart = start
		}

		data[i*5] = deltaLine
		data[i*5+1] = deltaStart
		data[i*5+2] = length
		data[i*5+3] = tokenType
		data[i*5+4] = tokenModifiers

		lastLine = line
		lastStart = start
	}
	return semantictokens.SemanticTokens{
		Data: data,
	}
}

func (s *SemanticTokensService) walkElements(content fileService.FileContent, addToken func(cNode *tree_sitter.Node, tokenType int, tokenModifiers ...int)) {
	for _, element := range content.LookUp {
		for _, namedElement := range element.GetBase().NamedElements {
			switch element := namedElement.(type) {
			case *packages.Argument:
				addToken(element.Name.Node, indexVariable, indexDeclaration)
			case *packages.Referenz:
				addToken(element.Name.Node, indexVariable, indexDeclaration)
			case *packages.MultiReferenz:
				addToken(element.Name.Node, indexVariable, indexDeclaration)

			case *packages.Funktion:
				addToken(element.Name.Node, indexFunction, indexDeclaration)
				for _, p := range element.Parameter {
					switch variable := p.(type) {
					case *packages.Argument:
						addToken(variable.Name.Node, indexParameter, indexDeclaration)
					case *packages.Referenz:
						addToken(variable.Name.Node, indexParameter, indexDeclaration)
					case *packages.MultiReferenz:
						addToken(element.Name.Node, indexParameter, indexDeclaration)
					}
				}

			}
		}
		switch e := element.(type) {
		case *packages.EnumElement:
			// Process enum constants
			for _, konstante := range e.Konstanten {
				addToken(konstante.Name.Node, indexEnumMember, indexDeclaration)

				for _, value := range konstante.Values {
					switch value.(type) {
					case base.StringValue:
						continue
					case values.BooleanValue:
						continue
					default:
						addToken(value.GetNode(), indexNumber, indexDefinition)

					}
				}
			}
		case *packages.EntityElement:
			for _, identifier := range e.EntityIdentifier.Variablen {
				addToken(identifier.Node, indexVariable)
			}
		}
	}
}

func (s *SemanticTokensService) WalkNode(cursor *tree_sitter.TreeCursor, addToken func(cNode *tree_sitter.Node, tokenType int, tokenModifiers ...int)) {
	node := cursor.Node()
	//logger := logService.GetLogger()
	//logger.Printf("%sStart Walk:\n", logService.TRACE)

	switch node.GrammarName() {
	// Keywords
	case "struct", "entity", "enum", "interface":
		fallthrough
	case "override", "javaDoc", "java", "class", "name", "type", "annotations":
		fallthrough
	case "func", "arg", "ref":
		fallthrough
	case "true", "false":
		fallthrough
	case "extends", "implements", "expand":
		fallthrough
	case "model", "dmf", "version", "import", "from":
		fallthrough
	case "int", "long", "double", "byte", "string", "date", "datetime", "boolean", "void", "package":
		addToken(node, indexKeyword)
	// EntityIdentifier keyword anhand parent, da identifier auch alle Namen der Elemente sind
	case "identifier_statement":
		identifierNode := node.Child(0)
		addToken(identifierNode, indexKeyword)
	// Type
	case "reftype":
		addToken(node, indexType)
	// String
	case "stringValue":
		tokenType := indexString
		switch node.Parent().GrammarName() {
		case "java_implements":
			fallthrough
		case "java_class":
			fallthrough
		case "java_extends":
			tokenType = indexClass

		case "java_name":
			tokenType = indexVariable
		case "java_annotation":
			tokenType = indexDecorator
		case "java_doc":
			tokenType = indexComment
		case "java_type":
			tokenType = indexType

		}
		addToken(node, tokenType)

	// Identifier / Package String
	case "entity_block", "struct_block":
		child := node.Child(1)
		addToken(child, indexStruct, indexDeclaration)
	case "interface_block":
		child := node.Child(1)
		addToken(child, indexInterface, indexDeclaration)
	case "enum_block":
		child := node.Child(1)
		addToken(child, indexEnum, indexDeclaration)
	case "package_block":
		child := node.Child(1)
		addToken(child, indexNamespace, indexDeclaration)
	case "comment_block":
		addToken(node, indexComment)
	default:
		//logger.Println("Cant Color: " + node.GrammarName())

	}

	hasChild := cursor.GotoFirstChild()
	if !hasChild {
		return
	}
	defer cursor.GotoParent()

	for {
		s.WalkNode(cursor, addToken)
		if !cursor.GotoNextSibling() {
			break
		}
	}

}
