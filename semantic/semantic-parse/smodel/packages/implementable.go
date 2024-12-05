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

// StructElement
func (s *StructElement) GetImplementsPaths() []base.ModelPath {
	return s.ImplementsPaths
}

func (s *StructElement) GetImplements() []PackageElement {
	return s.Implements
}

func (s *StructElement) AddImplements(implements PackageElement) {
	s.Implements = append(s.Implements, implements)
}

func (s *StructElement) GetPath() base.ModelPath {
	return s.Path
}

// InterfaceElement
func (s *InterfaceElement) GetImplementsPaths() []base.ModelPath {
	return s.ImplementsPaths
}

func (s *InterfaceElement) GetImplements() []PackageElement {
	return s.Implements
}

func (s *InterfaceElement) AddImplements(implements PackageElement) {
	s.Implements = append(s.Implements, implements)
}

func (s *InterfaceElement) GetPath() base.ModelPath {
	return s.Path
}
