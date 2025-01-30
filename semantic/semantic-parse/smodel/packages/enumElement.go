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

func (m *EnumElement) CleanTreeReferences() {
	m.PackageElement.CleanTreeReferences()
	for i, argument := range m.Argumente {
		argument.CleanTreeReferences()
		m.Argumente[i] = argument
	}
	for i, konstante := range m.Konstanten {
		konstante.CleanTreeReferences()
		m.Konstanten[i] = konstante
	}
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

func (m *Konstante) CleanTreeReferences() {
	m.ModelElement.CleanTreeReferences()
	for i, value := range m.Values {
		switch casted := value.(type) {
		case values.IntValue:
			casted.CleanTreeReferences()
			m.Values[i] = casted
		case values.DoubleValue:
			casted.CleanTreeReferences()
			m.Values[i] = casted
		case values.BooleanValue:
			casted.CleanTreeReferences()
			m.Values[i] = casted
		case values.DateTimeValue:
			casted.CleanTreeReferences()
			m.Values[i] = casted
		case values.DateValue:
			casted.CleanTreeReferences()
			m.Values[i] = casted
		case values.LongValue:
			casted.CleanTreeReferences()
			m.Values[i] = casted
		case values.StringValue:
			casted.CleanTreeReferences()
			m.Values[i] = casted
		default:
			casted.(base.TreeCleaner).CleanTreeReferences()
			m.Values[i] = casted
		}
	}
	m.Name.Node = nil
}
func (k Konstante) Element() base.ModelElement {
	return k.ModelElement
}

func (k Konstante) GetName() string {
	return k.Name.Name
}
