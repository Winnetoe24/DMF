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
		Full: true,
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

	cursor := content.Ast.Walk()

	s.WalkNode(cursor, []byte(content.Content), addToken)
	// Process all elements in the lookup
	s.walkElements(content, addToken)

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

func (s *SemanticTokensService) walkElements(content fileService.FileContent, addToken func(line uint32, start uint32, length uint32, tokenType uint32, tokenModifiers uint32)) {
	for _, element := range content.LookUp {
		for _, namedElement := range element.GetBase().NamedElements {
			switch element := namedElement.(type) {
			case *packages.Argument:
				node := element.Name.Node
				pos := node.StartPosition()
				addToken(uint32(pos.Row), uint32(pos.Column), uint32(len(node.Utf8Text([]byte(content.Content)))), indexVariable, indexReadonly)
			case *packages.Referenz:
				node := element.Name.Node
				pos := node.StartPosition()
				addToken(uint32(pos.Row), uint32(pos.Column), uint32(len(node.Utf8Text([]byte(content.Content)))), indexVariable, 0)
			case *packages.Funktion:
				node := element.Name.Node
				pos := node.StartPosition()
				addToken(uint32(pos.Row), uint32(pos.Column), uint32(len(node.Utf8Text([]byte(content.Content)))), indexFunction, indexDeclaration)

			}
		}
		switch e := element.(type) {
		//case *packages.Package:
		//	// Token for package name
		//	node := e.Identifier.Node
		//	pos := node.StartPosition()
		//
		//	case *packages.EntityElement:
		//		// Token for entity name
		//		node := e.GetBase().Node
		//		pos := node.StartPosition()
		//		addToken(uint32(pos.Row), uint32(pos.Column), uint32(len(e.StructElement.Identifier.Name)), 1, 1)
		//
		//		// Process arguments
		//		for _, arg := range e.NamedElements {
		//			switch a := arg.(type) {
		//			case *packages.Argument:
		//				pos := a.Node.StartPosition()
		//				addToken(uint32(pos.Row), uint32(pos.Column), uint32(len(a.Name.Name)), 6, 0)
		//			}
		//		}
		//
		case *packages.EnumElement:
			// Token for enum name
			//node := e.GetBase().Node
			//pos := node.StartPosition()
			//addToken(uint32(pos.Row), uint32(pos.Column), uint32(len(e.Identifier.Name)), 3, 1)
			//
			// Process enum constants
			for _, konstante := range e.Konstanten {
				node := konstante.Name.Node
				pos := node.StartPosition()
				addToken(uint32(pos.Row), uint32(pos.Column), uint32(len(node.Utf8Text([]byte(content.Content)))), indexProperty, indexStatic)

				for _, value := range konstante.Values {
					switch value.(type) {
					case values.StringValue:
						continue
					default:
						node := value.GetNode()
						pos := node.StartPosition()
						addToken(uint32(pos.Row), uint32(pos.Column), uint32(len(node.Utf8Text([]byte(content.Content)))), indexNumber, 0)

					}
				}
			}
			//
			//	case *packages.InterfaceElement:
			//		// Token for interface name
			//		node := e.GetBase().Node
			//		pos := node.StartPosition()
			//		addToken(uint32(pos.Row), uint32(pos.Column), uint32(len(e.Identifier.Name)), 4, 1)
			//	}
			//
			//	// Process comments if they exist
			//	if element.GetBase().Kommentar != nil {
			//		for _, comment := range *element.GetBase().Kommentar {
			//			node := element.GetBase().Node
			//			pos := node.StartPosition()
			//			addToken(uint32(pos.Row), uint32(pos.Column), uint32(len(comment)), 10, 4)
			//		}
		}
	}
}

func (s *SemanticTokensService) WalkNode(cursor *tree_sitter.TreeCursor, content []byte, addToken func(line uint32, start uint32, length uint32, tokenType uint32, tokenModifiers uint32)) {
	node := cursor.Node()
	switch node.GrammarName() {
	// Keywords
	case "struct":
		fallthrough
	case "entity":
		fallthrough
	case "enum":
		fallthrough
	case "interface":
		fallthrough

	case "func":
		fallthrough
	case "arg":
		fallthrough
	case "ref":
		fallthrough

	case "extends":
		fallthrough
	case "implements":
		fallthrough
	case "expand":
		fallthrough

	case "model":
		fallthrough
	case "dmf":
		fallthrough
	case "version":
		fallthrough

	case "int":
		fallthrough
	case "long":
		fallthrough
	case "double":
		fallthrough
	case "byte":
		fallthrough
	case "string":
		fallthrough
	case "date":
		fallthrough
	case "datetime":
		fallthrough
	case "boolean":
		fallthrough
	case "void":
		fallthrough
	case "package":
		startPosition := node.StartPosition()
		text := node.Utf8Text(content)
		addToken(uint32(startPosition.Row), uint32(startPosition.Column), uint32(len(text)), uint32(indexKeyword), 0)
	// Identifier keyword anhand parent, da identifier auch alle Namen der Elemente sind
	case "identifier_statement":
		identifierNode := node.Child(0)
		startPosition := identifierNode.StartPosition()
		text := identifierNode.Utf8Text(content)
		addToken(uint32(startPosition.Row), uint32(startPosition.Column), uint32(len(text)), uint32(indexKeyword), 0)
	// Type
	case "reftype":
		startPosition := node.StartPosition()
		text := node.Utf8Text(content)
		addToken(uint32(startPosition.Row), uint32(startPosition.Column), uint32(len(text)), uint32(indexType), 0)

	// String
	case "stringValue":
		startPosition := node.StartPosition()
		text := node.Utf8Text(content)
		addToken(uint32(startPosition.Row), uint32(startPosition.Column), uint32(len(text)), uint32(indexString), 0)

	// PackageString
	case "packageString":
		startPosition := node.StartPosition()
		text := node.Utf8Text(content)
		addToken(uint32(startPosition.Row), uint32(startPosition.Column), uint32(len(text)), indexClass, indexDeclaration)

	}

	hasChild := cursor.GotoFirstChild()
	if !hasChild {
		return
	}
	defer cursor.GotoParent()

	for {
		s.WalkNode(cursor, content, addToken)
		if !cursor.GotoNextSibling() {
			break
		}
	}

}
