package packages

import "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"

type InterfaceElement struct {
	base.PackageElement
	Funktionen      []Funktion
	TypeNode        base.TypeNode
	ImplementsPaths []base.ModelPath
	Implements      []PackageElement
}

var _ Implementable = (*InterfaceElement)(nil)
var _ PackageElement = (*InterfaceElement)(nil)

func (s *InterfaceElement) GetPackageElement() PackageElement {
	return s
}

func (s *InterfaceElement) GetType() base.PackageElementType {
	return base.INTERFACE
}

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
