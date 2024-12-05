package err_element

import (
	"github.com/tree-sitter/go-tree-sitter"
)

func CreateErrorElement(text []byte, node *tree_sitter.Node, err error) ErrorElement {
	return ErrorElement{
		Fehler: FehlerStelle{
			ModelCode: node.Utf8Text(text),
			Node:      node,
		},
		Error: err,
	}
}

func CreateErrorElementCxt(text []byte, node *tree_sitter.Node, err error, context *tree_sitter.Node) ErrorElement {
	return ErrorElement{
		Fehler: FehlerStelle{
			ModelCode:   context.Utf8Text(text),
			Node:        node,
			ContextNode: context,
		},
		Error: err,
	}
}
func CreateErrorElementCtxRef(text []byte, node *tree_sitter.Node, err error, context *tree_sitter.Node) *ErrorElement {
	cxt := CreateErrorElementCxt(text, node, err, context)
	return &cxt
}
func CreateErrorElementCause(text []byte, node *tree_sitter.Node, err error, cause *tree_sitter.Node) ErrorElement {
	return ErrorElement{
		Fehler: FehlerStelle{
			ModelCode: node.Utf8Text(text),
			Node:      node,
		},
		Error: err,
		Cause: &FehlerStelle{
			ModelCode: cause.Utf8Text(text),
			Node:      cause,
		},
	}
}
func CreateErrorElementCauseCxt(text []byte, node *tree_sitter.Node, err error, cause *tree_sitter.Node, causeContext *tree_sitter.Node) ErrorElement {
	return ErrorElement{
		Fehler: FehlerStelle{
			ModelCode: node.Utf8Text(text),
			Node:      node,
		},
		Error: err,
		Cause: &FehlerStelle{
			ModelCode:   causeContext.Utf8Text(text),
			Node:        cause,
			ContextNode: causeContext,
		},
	}
}

func CreateErrorElementFull(text []byte, node *tree_sitter.Node, err error, context *tree_sitter.Node, cause *tree_sitter.Node, causeContext *tree_sitter.Node) ErrorElement {
	return ErrorElement{
		Fehler: FehlerStelle{
			ModelCode:   context.Utf8Text(text),
			Node:        node,
			ContextNode: context,
		},
		Error: err,
		Cause: &FehlerStelle{
			ModelCode:   causeContext.Utf8Text(text),
			Node:        cause,
			ContextNode: causeContext,
		},
	}
}

func CreateErrorElementRef(text []byte, node *tree_sitter.Node, err error) *ErrorElement {
	element := CreateErrorElement(text, node, err)
	return &element
}
