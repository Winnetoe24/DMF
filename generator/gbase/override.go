package gbase

import "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"

type OverrideAdapter interface {
	GetDoc(override *base.Override) *base.Comment
	GetExtends(override *base.Override) *string
	GetImplements(override *base.Override) *string
	GetClass(override *base.Override) *string
	GetName(override *base.Override) *string
	GetType(override *base.Override) *string
}
