package smodel

import "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"

type TypeLookUp map[string]packages.PackageElement

func (t TypeLookUp) GetTypeLookUp() TypeLookUp {
	return t
}
