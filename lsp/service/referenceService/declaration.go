package referenceService

import (
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/protokoll/declaration"
	"github.com/Winnetoe24/DMF/lsp/service/fileService"
	"github.com/Winnetoe24/DMF/lsp/util"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"strings"
)

func (r *ReferenceService) findDeclarationsFromPath(sourceNode *tree_sitter.Node, path base.ModelPath, element packages.PackageElement, content fileService.FileContent, file protokoll.DocumentURI) []declaration.DeclarationLink {
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
	links := make([]declaration.DeclarationLink, len(subelements))
	for i, subelement := range subelements {
		links[i] = declaration.NodeToDeclarationLink(sourceNode, subelement, file)
	}

	referenzen := r.findRefOfType(content, path)
	for _, referenz := range referenzen {
		links = append(links, declaration.NodeToDeclarationLink(sourceNode, referenz, file))
	}

	return links
}

func (r *ReferenceService) findDeclarationsFromName(sourceNode *tree_sitter.Node, name string, element packages.PackageElement, content fileService.FileContent, file protokoll.DocumentURI) []declaration.DeclarationLink {

	var f = func(element packages.PackageElement, _ *tree_sitter.Node) packages.PackageElement {
		return element
	}
	links := make([]declaration.DeclarationLink, 0)

	nodes := r.findRefsOfVarInElement(element, name)
	for _, node := range nodes {
		links = append(links, declaration.NodeToDeclarationLink(sourceNode, node, file))
	}

	subelements := findSubelements(content, element, f)
	for _, subelement := range subelements {
		nodes := r.findRefsOfVarInElement(subelement, name)
		for _, node := range nodes {
			links = append(links, declaration.NodeToDeclarationLink(sourceNode, node, file))
		}
	}

	return links
}
