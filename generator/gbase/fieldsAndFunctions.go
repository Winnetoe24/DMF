package gbase

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

type FieldData struct {
	Typ       string
	Name      string
	Value     *string
	Kommentar *base.Comment
	Override  *base.Override
}

// ParameterKontext kann genauso wie KonstruktorData für die Parameter genutzt werden
type ParameterKontext struct {
	Parameter     []VariableKontext
	ImportKontext ImportKontext
}
type FunktionKontext struct {
	Funktion      packages.Funktion
	ImportKontext ImportKontext
	UseDelegate   bool
}
