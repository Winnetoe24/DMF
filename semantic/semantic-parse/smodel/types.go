package smodel

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages/values"
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
		Package   base.ModelPath
		FileName  values.StringValue
		ModelName *values.StringValue
	}
)

func (m *ImportStatement) CleanTreeReferences() {
	m.ModelElement.CleanTreeReferences()
	m.FileName.CleanTreeReferences()
	if m.ModelName != nil {
		m.ModelName.CleanTreeReferences()
	}
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
