package packages

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages/values"
)

type EnumElement struct {
	base.PackageElement
	Argumente  []Argument
	Konstanten []Konstante
}

var _ PackageElement = (*EnumElement)(nil)

func (s *EnumElement) GetType() base.PackageElementType {
	return base.ENUM
}

type Konstante struct {
	base.ModelElement
	Name   base.ElementIdentifier
	Values []values.Value
}

func (k Konstante) Element() base.ModelElement {
	return k.ModelElement
}

func (k Konstante) GetName() string {
	return k.Name.Name
}
