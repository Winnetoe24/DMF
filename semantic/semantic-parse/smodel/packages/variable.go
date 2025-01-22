package packages

import "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"

type Variable interface {
	GetVariableType() (*base.ModelPath, *base.PrimitivType, *MultiReferenzType)
	SetName(base.ElementIdentifier)
}

type Argument struct {
	base.ModelElement
	Typ  base.PrimitivType
	Name base.ElementIdentifier
}

var _ Variable = (*Argument)(nil)
var _ base.NamedElement = (*Argument)(nil)

func (a *Argument) Element() base.ModelElement {
	return a.ModelElement
}

func (a *Argument) GetName() string {
	return a.Name.Name
}

func (a *Argument) GetVariableType() (*base.ModelPath, *base.PrimitivType, *MultiReferenzType) {
	return nil, &a.Typ, nil
}

func (a *Argument) SetName(identifier base.ElementIdentifier) {
	a.Name = identifier
}

type Referenz struct {
	base.ModelElement
	Typ  base.ModelPath
	Name base.ElementIdentifier
}

var _ Variable = (*Referenz)(nil)
var _ base.NamedElement = (*Referenz)(nil)

func (r *Referenz) Element() base.ModelElement {
	return r.ModelElement
}

func (r *Referenz) GetName() string {
	return r.Name.Name
}

func (r *Referenz) GetVariableType() (*base.ModelPath, *base.PrimitivType, *MultiReferenzType) {
	return &r.Typ, nil, nil
}

func (r *Referenz) SetName(identifier base.ElementIdentifier) {
	r.Name = identifier
}

type MultiReferenzType string

const (
	MAP  MultiReferenzType = "Map"
	SET  MultiReferenzType = "Set"
	LIST MultiReferenzType = "List"
)

type MultiType struct {
	*base.ModelPath
	*base.PrimitivType
}

type MultiReferenz struct {
	base.ModelElement
	Typ      MultiReferenzType
	Name     base.ElementIdentifier
	Generics [2]MultiType
}

var _ Variable = (*MultiReferenz)(nil)
var _ base.NamedElement = (*MultiReferenz)(nil)

func (m MultiReferenz) Element() base.ModelElement {
	return m.ModelElement
}

func (m MultiReferenz) GetName() string {
	return m.Name.Name
}

func (m MultiReferenz) GetVariableType() (*base.ModelPath, *base.PrimitivType, *MultiReferenzType) {
	return nil, nil, &m.Typ
}

func (m MultiReferenz) SetName(identifier base.ElementIdentifier) {
	m.Name = identifier
}

type VoidElement struct {
	base.ModelElement
}

var _ Variable = (*VoidElement)(nil)

func (v VoidElement) GetVariableType() (*base.ModelPath, *base.PrimitivType, *MultiReferenzType) {
	return nil, nil, nil
}

func (v VoidElement) SetName(base.ElementIdentifier) {
	panic("should not be used")
}
