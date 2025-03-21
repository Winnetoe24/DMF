package base

import (
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

type Comment []string

type ModelElement struct {
	Kommentar *Comment
	Node      *tree_sitter.Node
	Override  *Override
}

func (i *ModelElement) CleanTreeReferences() {
	i.Node = nil
}

// Für Value.getNode()
func (i ModelElement) GetNode() *tree_sitter.Node {
	return i.Node
}

type PackageElement struct {
	ModelElement
	Path          ModelPath
	Identifier    ElementIdentifier
	NamedElements map[string]NamedElement
	Expand        bool
}

func (m *PackageElement) CleanTreeReferences() {
	m.ModelElement.CleanTreeReferences()
	m.Identifier.CleanTreeReferences()
}

type TypeNode struct {
	Path       string
	Element    *PackageElement
	SuperType  *TypeNode
	Implements []TypeNode
}

func (m *PackageElement) GetTypeNode() TypeNode {
	return TypeNode{}
}

func (m *PackageElement) GetBase() *PackageElement {
	return m
}

func (m *PackageElement) GetType() PackageElementType {
	panic("TODO GetType not implemented")
}

type ModelPath []string

func (m ModelPath) ToString() string {
	s := ""
	first := true
	for _, s2 := range m {
		if !first {
			s += "."
		} else {
			first = false
		}
		s += s2
	}
	return s
}
func (m ModelPath) Equals(path ModelPath) bool {
	if len(m) != len(path) {
		return false
	}
	for i, s := range m {
		if s != path[i] {
			return false
		}
	}
	return true
}
func (m ModelPath) IsSubPath(path ModelPath) bool {
	if len(m) > len(path) {
		return false
	}
	for i, s := range m {
		if s != path[i] {
			return false
		}
	}
	return true
}

type ElementIdentifier struct {
	ModelElement
	Name string
}

type Override struct {
	JavaOverride *JavaOverride
}

type JavaOverride struct {
	JavaDoc     *StringValue
	Extends     *StringValue
	Annotations *StringValue
	Implements  *StringValue
	Class       *StringValue
	Name        *StringValue
	Type        *StringValue
}

type StringValue struct {
	ModelElement
	Value string
}

func (s StringValue) GetDataType() PrimitivType {
	return STRING
}

func (s StringValue) GetValue() any {
	return s.Value
}
