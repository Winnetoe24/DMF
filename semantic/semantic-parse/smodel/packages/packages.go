package packages

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages/values"
)

type PackageElement interface {
	GetType() base.PackageElementType
	GetBase() *base.PackageElement
}

type Package struct {
	base.PackageElement
	Elements []PackageElement
}

type StructElement struct {
	base.PackageElement
	ExtendsPath     *base.ModelPath
	Extends         PackageElement
	ImplementsPaths []base.ModelPath
	Implements      []PackageElement
	Argumente       []Argument
	Referenzen      []Referenz
	Funktionen      []Funktion
}

type Argument struct {
	base.ModelElement
	Typ  base.PrimitivType
	Name base.ElementIdentifier
}

type Referenz struct {
	base.ModelElement
	Typ  base.ModelPath
	Name base.ElementIdentifier
}

type Variable interface {
	GetVariableType() (*base.ModelPath, *base.PrimitivType)
	SetName(base.ElementIdentifier)
}

type Funktion struct {
	base.ModelElement
	Name       base.ElementIdentifier
	ReturnType Variable
	Parameter  []Variable
}

type VoidElement struct {
	base.ModelElement
}

type EntityElement struct {
	StructElement
	Identifier
}

type Identifier struct {
	base.ModelElement
	Variablen []base.ElementIdentifier
}

type EnumElement struct {
	base.PackageElement
	Argumente  []Argument
	Konstanten []Konstante
}

type Konstante struct {
	base.ModelElement
	Name   base.ElementIdentifier
	Values []values.Value
}

type InterfaceElement struct {
	base.PackageElement
	Funktionen []Funktion
	TypeNode   base.TypeNode
	Implements []base.ModelPath
}

func (v VoidElement) SetName(base.ElementIdentifier) {
	panic("should not be used")
}

func (a *Argument) SetName(identifier base.ElementIdentifier) {
	a.Name = identifier
}

func (r *Referenz) SetName(identifier base.ElementIdentifier) {
	r.Name = identifier
}

func (v VoidElement) GetVariableType() (*base.ModelPath, *base.PrimitivType) {
	return nil, nil
}

func (p *Package) GetType() base.PackageElementType {
	return base.PACKAGE
}
func (s *StructElement) GetType() base.PackageElementType {
	return base.STRUCT
}
func (s *EntityElement) GetType() base.PackageElementType {
	return base.ENTITY
}
func (s *EnumElement) GetType() base.PackageElementType {
	return base.ENUM
}
func (s *InterfaceElement) GetType() base.PackageElementType {
	return base.INTERFACE
}

func (a *Argument) GetVariableType() (*base.ModelPath, *base.PrimitivType) {
	return nil, &a.Typ
}

func (r *Referenz) GetVariableType() (*base.ModelPath, *base.PrimitivType) {
	return &r.Typ, nil
}
