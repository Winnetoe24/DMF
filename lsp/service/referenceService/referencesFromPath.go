package referenceService

import (
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/service/fileService"
	"github.com/Winnetoe24/DMF/lsp/util"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"github.com/tree-sitter/go-tree-sitter"
	"strings"
)

func (r *ReferenceService) findReferencesFromPath(path base.ModelPath, element packages.PackageElement, content fileService.FileContent, file protokoll.DocumentURI) []protokoll.Location {
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
	subelements := findSubelements(content, element, f)
	locations := make([]protokoll.Location, len(subelements))
	for i, subelement := range subelements {
		locations[i] = protokoll.NodeToLocation(subelement, file)
	}

	referenzen := r.findRefOfType(content, path)
	for _, referenz := range referenzen {
		locations = append(locations, protokoll.NodeToLocation(referenz, file))
	}

	return locations

}

func (r *ReferenceService) findRefOfType(content fileService.FileContent, path base.ModelPath) []*tree_sitter.Node {
	var refs []*tree_sitter.Node
	for _, element := range content.LookUp {
		if element.GetBase().Path.ToString() == path.ToString() {
			refs = append(refs, element.GetBase().Identifier.Node)
		}
		for _, namedElement := range element.GetBase().NamedElements {
			switch ref := namedElement.(type) {
			case *packages.Referenz:
				if ref.Typ.ToString() == path.ToString() {
					refs = append(refs, ref.Node)
				}
			case *packages.MultiReferenz:
				if ref.Generics[0].ModelPath != nil && ref.Generics[0].ModelPath.ToString() == path.ToString() {
					refs = append(refs, ref.Node)
				}
				if ref.Generics[1].ModelPath != nil && ref.Generics[1].ModelPath.ToString() == path.ToString() {
					refs = append(refs, ref.Node)
				}
			case *packages.Funktion:
				for _, parameter := range ref.Parameter {
					switch lParam := parameter.(type) {
					case *packages.Referenz:
						if lParam.Typ.ToString() == path.ToString() {
							refs = append(refs, lParam.Node)
						}
					}
				}
			}
		}
	}
	return refs
}
