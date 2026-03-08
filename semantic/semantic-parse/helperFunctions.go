package semantic_parse

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/builder"
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

func (p *Parser) PushBuilder(newBuilder builder.Builder) builder.Builder {
	p.currentBuilder = newBuilder
	p.builders.Push(newBuilder)
	return newBuilder
}

func (p *Parser) Build() interface{} {
	build := p.builders.Pop().Build()
	p.currentBuilder = p.builders.Peek()
	return build
}

func (p *Parser) PurgeUntilBuilder(destination builder.Builder) {
	for p.builders.Peek() != destination && p.builders.Length() > 0 {
		p.builders.Pop()
	}
	if p.builders.Length() != 0 {
		p.currentBuilder = p.builders.Peek()
	} else {
		p.currentBuilder = nil
	}
}
