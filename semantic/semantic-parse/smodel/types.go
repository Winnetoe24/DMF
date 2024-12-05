package smodel

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
)

type (
	Model struct {
		base.ModelElement
		Packages []packages.Package
		Version  []int32
		Name     string
	}
)
