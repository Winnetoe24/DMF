package packages

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

type Implementable interface {
	GetImplementsPaths() []base.ModelPath
	GetImplements() []PackageElement
	AddImplements(implements PackageElement)
	GetNode() *tree_sitter.Node
	GetPath() base.ModelPath
	GetPackageElement() PackageElement
}
