package base

import (
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

type Comment []string

type ModelElement struct {
	Kommentar *Comment
	Node      *tree_sitter.Node
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

type ElementIdentifier struct {
	ModelElement
	Name string
}
