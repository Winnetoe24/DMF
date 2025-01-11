package util

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

// findElementOfNode findet das PackageElement im LookUp durch die Id
func FindElementOfNode(lookUp smodel.TypeLookUp, node *tree_sitter.Node) packages.PackageElement {
	for _, element := range lookUp {
		if element.GetBase().Node.Id() == node.Id() {
			return element
		}
	}
	return nil
}
