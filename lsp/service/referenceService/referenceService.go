package referenceService

import (
	"encoding/json"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/protokoll/declaration"
	"github.com/Winnetoe24/DMF/lsp/protokoll/initialize"
	"github.com/Winnetoe24/DMF/lsp/protokoll/reference"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/server/connect/connectUtils"
	"github.com/Winnetoe24/DMF/lsp/service"
	"github.com/Winnetoe24/DMF/lsp/service/fileService"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
	"github.com/Winnetoe24/DMF/lsp/util"
	semantic_parse "github.com/Winnetoe24/DMF/semantic/semantic-parse"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

const referenceMethod = "textDocument/references"
const declarationMethod = "textDocument/declaration"

type ReferenceService struct {
	con connect.Connection
	fs  *fileService.FileService
}

func NewReferenceService(connection connect.Connection, fs *fileService.FileService) *ReferenceService {
	return &ReferenceService{
		con: connection,
		fs:  fs,
	}
}

var _ service.MethodHandler = &ReferenceService{}

func (r *ReferenceService) Initialize(params *initialize.InitializeParams, result *initialize.InitializeResult) {
	// Check if client supports references
	if params.Capabilities.TextDocument != nil &&
		params.Capabilities.TextDocument.References != nil {
		// Enable reference provider in server capabilities
		result.Capabilities.ReferencesProvider = true
	}

	// DeclarationSupport
	if params.Capabilities.TextDocument != nil && params.Capabilities.TextDocument.Declaration != nil {
		result.Capabilities.DeclarationProvider = true
	}

}

func (r *ReferenceService) GetMethods() []string {
	return []string{referenceMethod, declarationMethod}
}

const (
	identifier     = iota
	refType        = iota
	primitiveType  = iota
	packageElement = iota
)

var nodeFilter = [][]string{{"identifier"}, {"reftype"}, {"primitive_type"}, {"package_block", "struct_block", "enum_block", "entity_block", "interface_block"}}

func (r *ReferenceService) HandleMethod(message protokoll.Message) {
	switch message.Method {
	case referenceMethod:
		logger := logService.GetLogger()
		params := reference.ReferenceParams{} // Using the new type
		err := json.Unmarshal(message.Params, &params)
		if err != nil {
			connectUtils.WriteErrorToCon(r.con, message.ID, err, protokoll.ParseError)
			return
		}

		// Get the file content
		content, err := r.fs.GetFileContent(params.TextDocument.URI)
		if err != nil {
			connectUtils.WriteErrorToCon(r.con, message.ID, err, protokoll.InternalError)
			return
		}

		// Find the node at the cursor position
		finder := util.NewNodeFinder([]byte(content.Content))
		nodes := finder.FindSmallestNodeAroundPositionInSets(&content.Ast, params.Position, nodeFilter)

		// Find all references to this node
		references := r.findReferences(nodes, content, params.TextDocument.URI, params.Context.IncludeDeclaration)

		// Send the response
		r.con.WriteMessage(protokoll.Message{
			JsonRPC: "2.0",
			ID:      message.ID,
			Result:  reference.ReferenceResult(references), // Using the new type
		})

		logger.Printf("%sFinished References request\n", logService.TRACE)
	case declarationMethod:
		params := declaration.DeclarationParams{}
		err := json.Unmarshal(message.Params, &params)
		if err != nil {
			connectUtils.WriteErrorToCon(r.con, message.ID, err, protokoll.ParseError)
			return
		}

		// Get the file content
		content, err := r.fs.GetFileContent(params.TextDocument.URI)
		if err != nil {
			connectUtils.WriteErrorToCon(r.con, message.ID, err, protokoll.InternalError)
			return
		}

		// Find the node at the cursor position
		finder := util.NewNodeFinder([]byte(content.Content))
		nodes := finder.FindSmallestNodeAroundPositionInSets(&content.Ast, params.Position, nodeFilter)

		// Find all declarations to this node
		declarations := r.findDeclarations(nodes, content, params.TextDocument.URI)

		// Send the response
		r.con.WriteMessage(protokoll.Message{
			JsonRPC: "2.0",
			ID:      message.ID,
			Result:  declarations,
		})
	}
}

func (r *ReferenceService) findReferences(nodes []*tree_sitter.Node, content fileService.FileContent, file protokoll.DocumentURI, includeDeclaration bool) []protokoll.Location {
	var references []protokoll.Location

	//node := nodes[identifier]
	//packageElementNode := nodes[packageElement]
	// Get the identifier name we're looking for
	_, targetPath, namePtr := r.findModelPath(nodes, content)

	if targetPath == nil {
		return references
	}

	// Find Package Element
	element := content.LookUp[targetPath.ToString()]
	if element == nil {
		return references
	}

	if namePtr == nil {
		return r.findReferencesFromPath(*targetPath, element, content, file)
	} else {
		return r.findReferencesFromName(*namePtr, element, content, file)
	}
}

func (r *ReferenceService) findDeclarations(nodes []*tree_sitter.Node, content fileService.FileContent, file protokoll.DocumentURI) []declaration.DeclarationLink {
	var declarations []declaration.DeclarationLink

	//node := nodes[identifier]
	//packageElementNode := nodes[packageElement]
	// Get the identifier name we're looking for
	sourceNode, targetPath, namePtr := r.findModelPath(nodes, content)

	if targetPath == nil {
		return declarations
	}

	// Find Package Element
	element := content.LookUp[targetPath.ToString()]
	if element == nil {
		return declarations
	}

	if namePtr == nil {
		return r.findDeclarationsFromPath(sourceNode, *targetPath, element, content, file)
	} else {
		return r.findDeclarationsFromName(sourceNode, *namePtr, element, content, file)
	}
}

// findModelPath findet den ModelPath des PackageElements für den LookUp sowie den evt. Namen des Named Elements
func (r *ReferenceService) findModelPath(nodes []*tree_sitter.Node, content fileService.FileContent) (*tree_sitter.Node, *base.ModelPath, *string) {

	bytes := []byte(content.Content)
	for i, node := range nodes {
		switch i {
		case identifier:
			name := node.Utf8Text(bytes)
			packageElementNode := nodes[packageElement]
			if packageElementNode == nil {
				return nil, nil, &name
			}
			element := util.FindElementOfNode(content.LookUp, packageElementNode)
			if element == nil {
				return nil, nil, &name
			}
			return node, &element.GetBase().Path, &name
		case refType:
			context := semantic_parse.SemanticContext{
				ErrorElements: nil,
				Model:         smodel.Model{},
				Text:          bytes,
				Cursor:        node.Walk(),
			}
			packageElementNode := nodes[packageElement]
			if packageElementNode == nil {
				return nil, nil, nil
			}
			element := util.FindElementOfNode(content.LookUp, packageElementNode)
			if element == nil {
				return nil, nil, nil
			}
			parseRefType, errorElement := context.ParseRefType(element.GetBase().Path)
			if errorElement != nil {
				return nil, nil, nil
			}
			return node, &parseRefType, nil
		}
	}
	return nil, nil, nil
}

// findSubelements macht aus jedem Subelement ein Element E mithilfe der Funktion f. "f" bekommt das gefundene Element und die Node des gefundenen Elements.
// f ist gedacht um entweder direkt die Nodes( oder SubNodes) oder die PackageElemente zurückzugeben. Nodes werden direkt für Referenzen genutzt, PackageElements können weiter verarbeitet werden.
func findSubelements[E interface{}](content fileService.FileContent, element packages.PackageElement, f func(element packages.PackageElement, node *tree_sitter.Node) E) []E {
	ret := make([]E, 0)
	switch element.(type) {
	// Find all Subelements for an InterfaceElement
	case *packages.InterfaceElement:
		for _, lElement := range content.LookUp {
			if lElement == element {
				continue
			}

			switch pElement := lElement.(type) {
			case *packages.InterfaceElement:
				for _, implement := range pElement.Implements {
					if implement == element {
						ret = append(ret, f(implement, pElement.Node))
					}
				}
			case *packages.EntityElement:
				for _, implement := range pElement.Implements {
					if implement == element {
						ret = append(ret, f(implement, pElement.Node))
					}
				}
			case *packages.StructElement:
				for _, implement := range pElement.Implements {
					if implement == element {
						ret = append(ret, f(implement, pElement.Node))
					}
				}
			}
		}
	// Find all SubElements of StructElement
	case *packages.EntityElement:
		for _, lElement := range content.LookUp {
			if lElement == element {
				continue
			}

			switch pElement := lElement.(type) {
			case *packages.EntityElement:
				if pElement.Extends == element {
					ret = append(ret, f(pElement, pElement.Node))
				}
			}
		}
	// Find all SubElements of StructElement
	case *packages.StructElement:
		for _, lElement := range content.LookUp {
			if lElement == element {
				continue
			}

			switch pElement := lElement.(type) {
			case *packages.EntityElement:
				if pElement.Extends == element {
					ret = append(ret, f(pElement, pElement.Node))
				}
			case *packages.StructElement:
				if pElement.Extends == element {
					ret = append(ret, f(pElement, pElement.Node))
				}
			}
		}
	// Find all SubElements of Package
	case *packages.Package:
		pElement := element.(*packages.Package)
		for _, p := range pElement.Elements {
			ret = append(ret, f(p, p.GetBase().Node))
		}
	}
	return ret
}
