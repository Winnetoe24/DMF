package smodel

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

type (
	Model struct {
		base.ModelElement
		ImportStatements []ImportStatement
		Packages         []packages.Package
		Version          []int32
		Name             string
		DMFVersion       []int32
	}

	ImportStatement struct {
		base.ModelElement
		Package      base.ModelPath
		FileName     base.StringValue
		ImportFailed bool
	}
)

func (m *ImportStatement) CleanTreeReferences() {
	m.ModelElement.CleanTreeReferences()
	m.FileName.CleanTreeReferences()
}
func (m *Model) CleanTreeReferences() {
	m.ModelElement.CleanTreeReferences()
	for _, statement := range m.ImportStatements {
		statement.CleanTreeReferences()
	}
	for _, p := range m.Packages {
		p.CleanTreeReferences()
	}
}
