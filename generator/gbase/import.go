package gbase

import "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"

type ImportKontext struct {
	ImportLookUp ImportLookUp
	Path         base.ModelPath
	HasDelegate  bool
}
type ImportLookUp map[string]Import
type Import struct {
	OriginalName base.ModelPath
}
