package semantic_parse

import (
	"errors"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/tree-sitter/go-tree-sitter"
)

func assertNodeState(text []byte, node *tree_sitter.Node, nodeName string) *errElement.ErrorElement {
	if node.IsError() {
		return errElement.CreateErrorElementRef(text, node, errors.New(nodeName+" ist error"))
	}

	return nil
}
func assertNodeStateCtx(text []byte, node *tree_sitter.Node, nodeName string, ctx *tree_sitter.Node) *errElement.ErrorElement {
	if node.IsError() {
		return errElement.CreateErrorElementCtxRef(text, node, errors.New(nodeName+" ist error"), ctx)
	}

	return nil
}
