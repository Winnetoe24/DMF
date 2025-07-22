package semantic_parse

import (
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

func (p *Parser) Node() *tree_sitter.Node {
	return p.context.Cursor.Node()
}

func (p *Parser) GoToFirstChild() bool {
	return p.context.Cursor.GotoFirstChild()
}

func (p *Parser) GoToNextSibling() bool {
	return p.context.Cursor.GotoNextSibling()
}

func (p *Parser) AddErrorElement(element *errElement.ErrorElement) bool {
	if element != nil {
		p.context.ErrorElements = append(p.context.ErrorElements, *element)
		return true
	}
	return false
}

func (p *Parser) GoToParent() bool {
	return p.context.Cursor.GotoParent()
}
