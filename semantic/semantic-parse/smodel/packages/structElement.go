package packages

import "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"

type StructElement struct {
	base.PackageElement
	ExtendsPath     *base.ModelPath
	Extends         PackageElement
	ImplementsPaths []base.ModelPath
	Implements      []PackageElement
	Argumente       []Argument
	Referenzen      []Referenz
	MultiReferenzen []MultiReferenz
	Funktionen      []Funktion
}

func (m *StructElement) CleanTreeReferences() {
	m.PackageElement.CleanTreeReferences()
	for i, argument := range m.Argumente {
		argument.CleanTreeReferences()
		m.Argumente[i] = argument
	}
	for i, referenz := range m.Referenzen {
		referenz.CleanTreeReferences()
		m.Referenzen[i] = referenz
	}
	for i, referenz := range m.MultiReferenzen {
		referenz.CleanTreeReferences()
		m.MultiReferenzen[i] = referenz
	}
	for i, funktion := range m.Funktionen {
		funktion.CleanTreeReferences()
		m.Funktionen[i] = funktion
	}
}

var _ Implementable = (*StructElement)(nil)
var _ PackageElement = (*StructElement)(nil)

func (s *StructElement) GetType() base.PackageElementType {
	return base.STRUCT
}

func (s *StructElement) GetPackageElement() PackageElement {
	return s
}
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

var _ StructAble = (*StructElement)(nil)

func (s *StructElement) GetExtendsPath() *base.ModelPath {
	return s.ExtendsPath
}

func (s *StructElement) GetArgumente() *[]Argument {
	return &s.Argumente
}

func (s *StructElement) GetReferenzen() *[]Referenz {
	return &s.Referenzen
}

func (s *StructElement) GetMultiReferenzen() *[]MultiReferenz {
	return &s.MultiReferenzen
}

func (s *StructElement) GetFunktionen() *[]Funktion {
	return &s.Funktionen
}

func (s *StructElement) GetNamedElements() *map[string]base.NamedElement {
	return &s.NamedElements
}

func (s *StructElement) GetEntity() *EntityElement {
	return nil
}
