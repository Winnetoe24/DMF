package values

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"

	"math/big"
	"time"
)

type Value interface {
	GetDataType() base.PrimitivType
	GetValue() any
	GetNode() *tree_sitter.Node
}

type IntValue struct {
	base.ModelElement
	Ignored bool
	Value   int
}

type DoubleValue struct {
	base.ModelElement
	Value float64
}

type LongValue struct {
	base.ModelElement
	Value *big.Int
}

type DateValue struct {
	base.ModelElement
	Value time.Time
}

type DateTimeValue struct {
	base.ModelElement
	Value time.Time
}

type StringValue struct {
	base.ModelElement
	Value string
}

type BooleanValue struct {
	base.ModelElement
	Value bool
}

func (i IntValue) GetValue() any {
	return i.Value
}

func (i IntValue) GetDataType() base.PrimitivType {
	return base.INT
}
func (d DoubleValue) GetDataType() base.PrimitivType {
	return base.DOUBLE
}

func (d DoubleValue) GetValue() any {
	return d.Value
}
func (l LongValue) GetDataType() base.PrimitivType {
	return base.LONG
}

func (l LongValue) GetValue() any {
	return l.Value
}

func (d DateValue) GetDataType() base.PrimitivType {
	return base.DATE
}

func (d DateValue) GetValue() any {
	return d.Value
}
func (d DateTimeValue) GetDataType() base.PrimitivType {
	return base.DATETIME
}

func (d DateTimeValue) GetValue() any {
	return d.Value
}
func (s StringValue) GetDataType() base.PrimitivType {
	return base.STRING
}

func (s StringValue) GetValue() any {
	return s.Value
}
func (b BooleanValue) GetDataType() base.PrimitivType {
	return base.BOOLEAN
}

func (b BooleanValue) GetValue() any {
	return b.Value
}
