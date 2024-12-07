package err_element

import (
	"github.com/tree-sitter/go-tree-sitter"
)

func CreateErrorElement(node *tree_sitter.Node, err error) ErrorElement {
	return ErrorElement{
		Fehler: FehlerStelle{
			Node: node,
		},
		Error: err,
	}
}

func CreateErrorElementCxt(node *tree_sitter.Node, err error, context *tree_sitter.Node) ErrorElement {
	return ErrorElement{
		Fehler: FehlerStelle{
			Node:        node,
			ContextNode: context,
		},
		Error: err,
	}
}
func CreateErrorElementCtxRef(node *tree_sitter.Node, err error, context *tree_sitter.Node) *ErrorElement {
	cxt := CreateErrorElementCxt(node, err, context)
	return &cxt
}
func CreateErrorElementCause(node *tree_sitter.Node, err error, cause *tree_sitter.Node) ErrorElement {
	return ErrorElement{
		Fehler: FehlerStelle{
			Node: node,
		},
		Error: err,
		Cause: &FehlerStelle{
			Node: cause,
		},
	}
}
func CreateErrorElementCauseCxt(node *tree_sitter.Node, err error, cause *tree_sitter.Node, causeContext *tree_sitter.Node) ErrorElement {
	return ErrorElement{
		Fehler: FehlerStelle{
			Node: node,
		},
		Error: err,
		Cause: &FehlerStelle{
			Node:        cause,
			ContextNode: causeContext,
		},
	}
}

func CreateErrorElementFull(node *tree_sitter.Node, err error, context *tree_sitter.Node, cause *tree_sitter.Node, causeContext *tree_sitter.Node) ErrorElement {
	return ErrorElement{
		Fehler: FehlerStelle{
			Node:        node,
			ContextNode: context,
		},
		Error: err,
		Cause: &FehlerStelle{
			Node:        cause,
			ContextNode: causeContext,
		},
	}
}

func CreateErrorElementRef(node *tree_sitter.Node, err error) *ErrorElement {
	element := CreateErrorElement(node, err)
	return &element
}
