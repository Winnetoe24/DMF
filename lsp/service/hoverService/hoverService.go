package hoverService

import (
	"bytes"
	"embed"
	"encoding/json"
	"fmt"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/protokoll/hover"
	"github.com/Winnetoe24/DMF/lsp/protokoll/initialize"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/server/connect/connectUtils"
	"github.com/Winnetoe24/DMF/lsp/service"
	"github.com/Winnetoe24/DMF/lsp/service/fileService"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
	"github.com/Winnetoe24/DMF/lsp/util"
	base2 "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"strings"
	"text/template"
)

const hoverMethod = "textDocument/hover"

//go:embed template/*
var tmplFiles embed.FS

type HoverService struct {
	con                  connect.Connection
	fs                   *fileService.FileService
	preferredHoverFormat hover.MarkupKind
	templates            *template.Template
}

func NewHoverService(connection connect.Connection, fs *fileService.FileService) *HoverService {
	funcMap := template.FuncMap{}
	return &HoverService{
		con:                  connection,
		fs:                   fs,
		preferredHoverFormat: hover.Markdown,
		templates:            template.Must(template.New("").Funcs(funcMap).ParseFS(tmplFiles, "template/*")),
	}
}

var _ service.MethodHandler = &HoverService{}

func (h *HoverService) Initialize(params *initialize.InitializeParams, result *initialize.InitializeResult) {

	result.Capabilities.HoverProvider = true

	// Check client capabilities for hover support
	if params.Capabilities.TextDocument != nil &&
		params.Capabilities.TextDocument.Hover != nil {
		// Store client's preferred markup kinds for hover content
		clientHoverCaps := params.Capabilities.TextDocument.Hover
		if len(clientHoverCaps.ContentFormat) > 0 {
			// Store the client's preferred markup kinds for later use
			h.preferredHoverFormat = clientHoverCaps.ContentFormat[0]
		} else {
			// Default to markdown if client doesn't specify
			h.preferredHoverFormat = "markdown"
		}
	}

}

func (h *HoverService) GetMethods() []string {
	return []string{hoverMethod}
}

const (
	variable       = iota
	identifier     = iota
	kommentar      = iota
	packageElement = iota
)

var nodeFilter = [][]string{{"arg_block", "ref_block"}, {"identifier_statement"}, {"comment_block"}, {"package_block", "struct_block", "enum_block", "entity_block", "interface_block"}}

func (h *HoverService) HandleMethod(message protokoll.Message) {
	switch message.Method {
	case hoverMethod:
		logger := logService.GetLogger()
		params := hover.HoverParams{}
		err := json.Unmarshal(message.Params, &params)
		if err != nil {
			connectUtils.WriteErrorToCon(h.con, message.ID, err, protokoll.ParseError)
			return
		}
		logger.Printf("%sStart Get File Content\n", logService.TRACE)
		content, err := h.fs.GetFileContent(params.TextDocument.URI)
		if err != nil {
			panic(err)
		}

		logger.Printf("%Start Find Node\n", logService.TRACE)
		finder := util.NewNodeFinder([]byte(content.Content))
		nodesAroundPosition := finder.FindSmallestNodeAroundPositionInSets(&content.Ast, params.Position, nodeFilter)

		hoverContent := h.renderContent(nodesAroundPosition, params.TextDocument.URI, content, false)

		hoverResult := hover.HoverResult{
			Contents: createMarkupContent(
				h.preferredHoverFormat,
				hoverContent,
			),
			Range: &protokoll.Range{
				Start: params.Position,
				End:   params.Position,
			},
		}
		h.con.WriteMessage(protokoll.Message{
			JsonRPC: "2.0",
			ID:      message.ID,
			Method:  "",
			Params:  nil,
			Result:  hoverResult,
			Error:   nil,
		})
		logger.Printf("%sFinished Hover with Content: %s\n", logService.TRACE, hoverContent)
	default:
		logger := logService.GetLogger()
		logger.Printf("%sUnknown Method:%s\n", logService.ERROR, message.Method)
	}

}

func (h *HoverService) renderContent(nodesAroundPosition []*tree_sitter.Node, file protokoll.DocumentURI, content fileService.FileContent, rekursiv bool) string {
	for i, node := range nodesAroundPosition {
		if node == nil {
			continue
		}
		switch i {
		case variable:
			return h.renderVariableElementMarkdown(file, node, nodesAroundPosition[packageElement], content, rekursiv)
		case identifier:
			return h.renderIdentifierElementMarkdown(file, node, content, rekursiv)
		case kommentar:

		case packageElement:
			if h.preferredHoverFormat == hover.Markdown {
				return h.renderPackageElementMarkdown(file, node, content)
			} else {
				return h.renderPackageElementPlainText(node, content)
			}
		default:
			return "Found: " + node.GrammarName()
		}
	}
	return "NotFound"
}

type VariableElementTemplateData struct {
	Name string
	// Link zum Node der Variable. Wird bei der Dokumentation der Node der Variable nicht befüllt.
	Link      string
	Typ       string
	Kommentar string
}

func (h *HoverService) renderVariableElementMarkdown(file protokoll.DocumentURI, nodeVariable *tree_sitter.Node, packageElementNode *tree_sitter.Node, content fileService.FileContent, rekursiv bool) string {
	for _, element := range content.LookUp {
		base := element.GetBase()
		if base.Node.Id() != packageElementNode.Id() {
			continue
		}
		data := VariableElementTemplateData{}

		var namedElement base2.NamedElement
		for _, namedElement = range base.NamedElements {
			if namedElement.Element().Node.Id() == nodeVariable.Id() {
				break
			}
		}
		switch cElement := namedElement.(type) {
		case *packages.Argument:
			data.Typ = string(cElement.Typ)
			data.Name = cElement.Name.Name
			if cElement.Kommentar != nil {
				data.Kommentar = strings.Join(*cElement.Kommentar, "")
			}
		case *packages.Referenz:
			data.Name = cElement.Name.Name
			if cElement.Kommentar != nil {
				data.Kommentar = strings.Join(*cElement.Kommentar, "")
			}
			referenzierterTyp, found := content.LookUp[cElement.Typ.ToString()]
			if found {
				if rekursiv {
					data.Typ = util.CreateMarkdownLinkComplete(file, referenzierterTyp.GetBase().Node, cElement.Typ[len(cElement.Typ)-1], "")
				} else {
					data.Typ = util.CreateMarkdownLinkComplete(file, referenzierterTyp.GetBase().Node, cElement.Typ[len(cElement.Typ)-1],
						strings.ReplaceAll(h.renderPackageElementPlainText(referenzierterTyp.GetBase().Node, content), "\n", ""))
				}
			} else {
				data.Typ = cElement.Typ.ToString()
			}
		}

		buffer := bytes.NewBuffer(make([]byte, 0))
		err := h.templates.ExecuteTemplate(buffer, "variable", data)
		if err != nil {
			panic(err)
		}
		return buffer.String()
	}
	return h.renderPackageElementPlainText(packageElementNode, content)
}

type IdentifierElementTemplateData struct {
	Name      string
	NameLink  string
	Kommentar string
	Elemente  []VariableElementTemplateData
}

func (h *HoverService) renderIdentifierElementMarkdown(file protokoll.DocumentURI, node *tree_sitter.Node, content fileService.FileContent, rekursiv bool) string {
	entityElementNode := node.Parent()
	for _, element := range content.LookUp {
		base := element.GetBase()
		if base.Node.Id() == entityElementNode.Id() {
			data := IdentifierElementTemplateData{}

			var entityElement = element.(*packages.EntityElement)
			data.Name = base.Path[len(base.Path)-1]
			data.NameLink = util.CreateMarkdownLinkFromNode(file, base.Node)

			identifier := entityElement.Identifier
			if identifier.Kommentar != nil {
				data.Kommentar = strings.Join(*identifier.Kommentar, "")
			}
			for _, variable := range identifier.Variablen {
				namedElement := entityElement.NamedElements[variable.Name]
				typeName := "unknown"
				link := util.CreateMarkdownLinkFromNode(file, variable.Node)
				kommentar := ""
				switch cElement := namedElement.(type) {
				case *packages.Argument:
					typeName = string(cElement.Typ)
					link = util.CreateMarkdownLinkFromNode(file, cElement.Node)
					if cElement.Kommentar != nil {
						kommentar = strings.Join(*cElement.Kommentar, "")
					}
				case *packages.Referenz:
					link = util.CreateMarkdownLinkFromNode(file, cElement.Node)
					if cElement.Kommentar != nil {
						kommentar = strings.Join(*cElement.Kommentar, "")
					}
					referenzierterTyp, found := content.LookUp[cElement.Typ.ToString()]
					if found {
						if rekursiv {
							typeName = util.CreateMarkdownLinkComplete(file, referenzierterTyp.GetBase().Node, cElement.Typ[len(cElement.Typ)-1], "")
						} else {
							typeName = util.CreateMarkdownLinkComplete(file, referenzierterTyp.GetBase().Node, cElement.Typ[len(cElement.Typ)-1],
								strings.ReplaceAll(h.renderPackageElementPlainText(referenzierterTyp.GetBase().Node, content), "\n", ""))
						}
					} else {
						typeName = cElement.Typ.ToString()
					}
				}

				data.Elemente = append(data.Elemente, VariableElementTemplateData{
					Name:      variable.Name,
					Link:      link,
					Typ:       typeName,
					Kommentar: kommentar,
				})
			}
			buffer := bytes.NewBuffer(make([]byte, 0))
			err := h.templates.ExecuteTemplate(buffer, "identifier", data)
			if err != nil {
				panic(err)
			}
			return buffer.String()
		}
	}
	return "Ein Identifier einer Entity welcher die Identität bestimmt."
}

type PackageElementTemplateData struct {
	Name     string
	TypeName string
	Package  string
	// Bsp: test.dmf#L10.10 oder test.dmf#L10
	PackageLink string
	Kommentar   string
}

func (h *HoverService) renderPackageElementMarkdown(file protokoll.DocumentURI, node *tree_sitter.Node, content fileService.FileContent) string {
	data := PackageElementTemplateData{}
	found := false
	for _, element := range content.LookUp {
		base := element.GetBase()
		if base.Node.Id() == node.Id() {
			if base.Kommentar != nil {
				data.Kommentar = strings.Join(*base.Kommentar, "")
			}
			data.Name = base.Path[len(base.Path)-1]
			data.Package = base.Path[:len(base.Path)-1].ToString()

			// Package Link
			packageElement := content.LookUp[data.Package]
			if packageElement != nil {
				data.PackageLink = util.CreateMarkdownLinkFromNode(file, packageElement.GetBase().Identifier.Node)
			}

			switch element.(type) {
			case *packages.EntityElement:
				data.TypeName = "Entity"
			case *packages.EnumElement:
				data.TypeName = "Enum"
			case *packages.StructElement:
				data.TypeName = "Struct"
			case *packages.InterfaceElement:
				data.TypeName = "Interface"
			case *packages.Package:
				data.TypeName = "Package"
			default:
				data.TypeName = "Unknown"
			}
			found = true
			break
		}
	}
	if !found {
		return h.renderPackageElementPlainText(node, content)
	}

	buffer := bytes.NewBuffer(make([]byte, 0))
	err := h.templates.ExecuteTemplate(buffer, "package_element", data)
	if err != nil {
		panic(err)
	}
	return buffer.String()
}
func (h *HoverService) renderPackageElementPlainText(node *tree_sitter.Node, content fileService.FileContent) string {
	debugString := ""
	for _, element := range content.LookUp {
		base := element.GetBase()
		//if base.Node.Utf8Text([]byte(content.Content)) == node.Utf8Text([]byte(content.Content)) {
		if base.Node.Id() == node.Id() {
			kommentar := ""
			if base.Kommentar != nil {
				kommentar = strings.Join(*base.Kommentar, "")
			}
			typeString := ""
			switch cElement := element.(type) {
			case *packages.EntityElement:
				typeString = "Entity " + cElement.StructElement.Identifier.Name + " in Package " + cElement.Path[:len(cElement.Path)-1].ToString()
			case *packages.EnumElement:
				typeString = "Enum " + cElement.Identifier.Name + " in Package " + cElement.Path[:len(cElement.Path)-1].ToString()
			case *packages.StructElement:
				typeString = "Struct " + cElement.Identifier.Name + " in Package " + cElement.Path[:len(cElement.Path)-1].ToString()
			case *packages.InterfaceElement:
				typeString = "Interface " + cElement.Identifier.Name + " in Package " + cElement.Path[:len(cElement.Path)-1].ToString()
			case *packages.Package:
				typeString = "Package " + cElement.Path.ToString()
			}

			return fmt.Sprintf("%s%s\n", kommentar, typeString)
		}
		debugString += base.Path.ToString() + " => " + base.Node.GrammarName() + "\n"
	}
	return "didnt find PackageElement:\n\n" + debugString
}

// Helper function to create properly formatted markup content
// idnt find PackageElement: de. alex. brand => package_block de. alex. brand. other => package_block de. alex. brand. other. Test => struct_block de. alex. brand. other. Test => struct_block de. alex. brand. rekur => package_block de. alex. brand. rekur. One => struct_block de. alex. brand. grund => package_block de. alex. brand. other. Ort => enum_block de. alex. brand. other. Intes => interface_block de. alex. brand. rekur. OneE => entity_block de. alex. brand. rekur. TwoE => entity_block de. alex. brand. grund. IGrund => interface_block
func createMarkupContent(kind hover.MarkupKind, content string) json.RawMessage {
	markup := hover.MarkupContent{
		Kind:  kind,
		Value: content,
	}
	raw, _ := json.Marshal(markup)
	return raw
}
