package gbase

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
)

type VererbungKontext struct {
	ImportKontext   ImportKontext
	ExtendsPath     *base.ModelPath
	ImplementsPaths []base.ModelPath
	Interface       bool
}
