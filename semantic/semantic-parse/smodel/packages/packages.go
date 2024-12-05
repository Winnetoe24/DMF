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

func (f *Funktion) Element() base.ModelElement {
	return f.ModelElement
}

func (f *Funktion) GetName() string {
	return f.Name.Name
}

type Identifier struct {
	base.ModelElement
	Variablen []base.ElementIdentifier
}
