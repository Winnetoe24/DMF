package packages

import "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"

type EntityElement struct {
	StructElement
	EntityIdentifier
}

func (m *EntityElement) CleanTreeReferences() {
	m.StructElement.CleanTreeReferences()
	m.EntityIdentifier.CleanTreeReferences()
}

var _ Implementable = (*EntityElement)(nil)
var _ PackageElement = (*EntityElement)(nil)

func (s *EntityElement) GetPackageElement() PackageElement {
	return s
}

func (s *EntityElement) GetType() base.PackageElementType {
	return base.ENTITY
}

var _ StructAble = (*EntityElement)(nil)

func (s *EntityElement) GetEntity() *EntityElement {
	return s
}
