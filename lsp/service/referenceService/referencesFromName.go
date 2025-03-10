package referenceService

import (
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/service/fileService"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"github.com/tree-sitter/go-tree-sitter"
)

func (r *ReferenceService) findReferencesFromName(name string, element packages.PackageElement, content fileService.FileContent, file protokoll.DocumentURI) []protokoll.Location {
	// Variable References
	// -> References in own PackageElement
	// -> References in SubElements

	var f = func(element packages.PackageElement, _ *tree_sitter.Node) packages.PackageElement {
		return element
	}
	locations := make([]protokoll.Location, 0)

	nodes := r.findRefsOfVarInElement(element, name)
	for _, node := range nodes {
		locations = append(locations, protokoll.NodeToLocation(node, file))
	}

	subelements := findSubelements(content, element, f)
	for _, subelement := range subelements {
		nodes := r.findRefsOfVarInElement(subelement, name)
		for _, node := range nodes {
			//TOOD Prevent double References through Abstraction
			locations = append(locations, protokoll.NodeToLocation(node, file))
		}
	}

	return locations
}

func (r *ReferenceService) findRefsOfVarInElement(element packages.PackageElement, name string) []*tree_sitter.Node {
	nodes := []*tree_sitter.Node{}
	// Als Variable
	namedElement := element.GetBase().NamedElements[name]
	if namedElement != nil {
		nodes = append(nodes, namedElement.Element().Node)
	}

	// In EntityIdentifier
	switch entity := element.(type) {
	case *packages.EntityElement:
		for _, elementIdentifier := range entity.EntityIdentifier.Variablen {
			if elementIdentifier.Name == name {
				nodes = append(nodes, elementIdentifier.Node)
			}
		}
	}

	return nodes
}
