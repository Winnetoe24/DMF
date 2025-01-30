package packages

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
)

type PackageElement interface {
	GetType() base.PackageElementType
	GetBase() *base.PackageElement
}

type Package struct {
	base.PackageElement
	Elements []PackageElement
}

func (m *Package) CleanTreeReferences() {
	m.PackageElement.CleanTreeReferences()
	for _, element := range m.Elements {
		element.(base.TreeCleaner).CleanTreeReferences()
	}
}

var _ PackageElement = (*Package)(nil)

func (p *Package) GetType() base.PackageElementType {
	return base.PACKAGE
}

type Funktion struct {
	base.ModelElement
	Name       base.ElementIdentifier
	ReturnType Variable
	Parameter  []Variable
}

func (m *Funktion) CleanTreeReferences() {
	m.ModelElement.CleanTreeReferences()
	switch casted := m.ReturnType.(type) {
	case VoidElement:
		casted.CleanTreeReferences()
		m.ReturnType = casted
	default:
		casted.(base.TreeCleaner).CleanTreeReferences()
		m.ReturnType = casted
	}
	m.Name.CleanTreeReferences()
	for _, element := range m.Parameter {
		element.(base.TreeCleaner).CleanTreeReferences()
	}
}

func (f *Funktion) Element() base.ModelElement {
	return f.ModelElement
}

func (f *Funktion) GetName() string {
	return f.Name.Name
}

type EntityIdentifier struct {
	base.ModelElement
	Variablen []base.ElementIdentifier
}

func (m *EntityIdentifier) CleanTreeReferences() {
	m.ModelElement.CleanTreeReferences()
	for _, element := range m.Variablen {
		element.CleanTreeReferences()
	}
}
