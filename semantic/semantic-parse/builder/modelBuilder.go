package builder

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
)

type ModelBuilder struct {
	DMFVersion   []int32
	ModelVersion []int32
}

func (m *ModelBuilder) Build() interface{} {
	return &smodel.Model{
		ModelElement:     base.ModelElement{},
		ImportStatements: nil,
		Packages:         nil,
		Version:          m.ModelVersion,
		Name:             "",
		DMFVersion:       m.DMFVersion,
	}
}

var _ Builder = &ModelBuilder{}
