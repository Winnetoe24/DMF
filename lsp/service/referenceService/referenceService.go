package referenceService

import (
	"encoding/json"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/protokoll/initialize"
	"github.com/Winnetoe24/DMF/lsp/protokoll/reference"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/server/connect/connectUtils"
	"github.com/Winnetoe24/DMF/lsp/service"
	"github.com/Winnetoe24/DMF/lsp/service/fileService"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
	"github.com/Winnetoe24/DMF/lsp/util"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"strings"
)

const referenceMethod = "textDocument/references"

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
}

func (r *ReferenceService) GetMethods() []string {
	return []string{referenceMethod}
}

const (
	identifier     = iota
	packageElement = iota
)

var nodeFilter = [][]string{{"identifier_statement"}, {"package_block", "struct_block", "enum_block", "entity_block", "interface_block"}}

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
	}
}

func (r *ReferenceService) findReferences(nodes []*tree_sitter.Node, content fileService.FileContent, file protokoll.DocumentURI, includeDeclaration bool) []protokoll.Location {
	var references []protokoll.Location

	//node := nodes[identifier]
	//packageElementNode := nodes[packageElement]
	// Get the identifier name we're looking for
	targetPath, namePtr := r.findModelPath(nodes, content)

	// Find Package Element
	element := content.LookUp[targetPath.ToString()]
	if element == nil {
		return references
	}

	return r.findReferencesFromPath(targetPath, namePtr, element, content, file)

	// Look through all named elements in the lookup table
	//for _, element := range content.LookUp {
	//	base := element.GetBase()
	//
	//	if base.Node.Id() != packageElementNode.Id() {
	//		continue
	//	}
	//
	//	// Check if this element references our target
	//	for _, namedElement := range base.NamedElements {
	//		if namedElement.GetName() == targetName {
	//			// Convert the node position to an LSP location
	//			location := protokoll.Location{
	//				URI:   file,
	//				Range: protokoll.ToRange(namedElement.Element().Node.Range()),
	//			}
	//			references = append(references, location)
	//		}
	//	}
	//}

	//return references
}

// findModelPath findet den ModelPath des PackageElements für den LookUp sowie den evt. Namen des Named Elements
func (r *ReferenceService) findModelPath(nodes []*tree_sitter.Node, content fileService.FileContent) (base.ModelPath, *string) {
	return make(base.ModelPath, 0), nil
}

func (r *ReferenceService) findReferencesFromPath(path base.ModelPath, namePtr *string, element packages.PackageElement, content fileService.FileContent, file protokoll.DocumentURI) []protokoll.Location {

	if namePtr == nil {
		// Type References
		// -> ref Usages
		// -> References in SubElements
		// --> Interface -> extends in InterfaceElementen und implements
		// --> Struct -> extends in StructElementen & EntityElementen
		// --> Entity -> extends in EntityElementen
		// --> Package -> All Elements
		var f func(element packages.PackageElement, node *tree_sitter.Node) *tree_sitter.Node
		if element.GetType() == base.PACKAGE {
			f = func(element packages.PackageElement, node *tree_sitter.Node) *tree_sitter.Node {
				return node
			}
		} else {
			finder := util.NewNodeFinder(make([]byte, 0))
			// Find Node
			f = func(foundElement packages.PackageElement, node *tree_sitter.Node) *tree_sitter.Node {
				nodes := finder.FindChildrenInSet(node, []string{"reftype"})
				for _, fNode := range nodes {
					if fNode == nil || fNode.Parent() == nil {
						continue
					}
					parentGrammarName := fNode.Parent().GrammarName()
					if parentGrammarName != "implements_block" && parentGrammarName != "extends_block" {
						continue
					}
					if strings.Contains(fNode.Utf8Text([]byte(content.Content)), element.GetBase().Identifier.Name) {
						return fNode
					}
				}
				return node
			}
		}
	} else {
		// Variable References
		// -> References in own PackageElement
		// -> References in SubElements
	}
	return nil
}

// findSubelements macht aus jedem Subelement ein Element E mithilfe der Funktion f. "f" bekommt das gefundene Element und die Node des gefundenen Elements.
// f ist gedacht um entweder direkt die Nodes( oder SubNodes) oder die PackageElemente zurückzugeben. Nodes werden direkt für Referenzen genutzt, PackageElements können weiter verarbeitet werden.
func findSubelements[E interface{}](path base.ModelPath, content fileService.FileContent, element packages.PackageElement, f func(element packages.PackageElement, node *tree_sitter.Node) E) []E {
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
