package packages

import "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"

type StructAble interface {
	GetExtendsPath() *base.ModelPath
	GetArgumente() *[]Argument
	GetReferenzen() *[]Referenz
	GetMultiReferenzen() *[]MultiReferenz
	GetFunktionen() *[]Funktion
	GetNamedElements() *map[string]base.NamedElement
	GetEntity() *EntityElement
	GetPackageElement() PackageElement
}
