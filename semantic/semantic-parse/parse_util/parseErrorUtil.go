package parse_old

import (
	"errors"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/tree-sitter/go-tree-sitter"
)

func AssertNodeState(node *tree_sitter.Node, nodeName string) *errElement.ErrorElement {
	if node.IsError() {
		return errElement.CreateErrorElementRef(node, errors.New(nodeName+" ist error"))
	}
	if node.IsMissing() {
		return errElement.CreateErrorElementRef(node, errors.New(nodeName+" ist missing"))
	}

	return nil
}

func AssertNodeStateGrammar(node *tree_sitter.Node, nodeName string, grammarName string) *errElement.ErrorElement {
	if node.GrammarName() != grammarName {
		return errElement.CreateErrorElementRef(node, errors.New(nodeName+" grammar name mismatch:"+node.GrammarName()))
	}
	if err := AssertNodeState(node, nodeName); err != nil {
		return err
	}
	return nil
}

func CreateMissingElementError(parent *tree_sitter.Node, nodeName string) *errElement.ErrorElement {
	return errElement.CreateErrorElementRef(parent, errors.New(nodeName+" is missing"))
}
