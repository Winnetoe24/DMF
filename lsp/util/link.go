package util

import (
	"fmt"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

var CharacterInMarkdownLinksActiv = false

func CreateMarkdownLinkFromNode(file protokoll.DocumentURI, node *tree_sitter.Node) string {
	position := protokoll.ToPosition(node.StartPosition())
	return CreateMarkdownLink(file, position)
}

func CreateMarkdownLink(file protokoll.DocumentURI, position protokoll.Position) string {
	if CharacterInMarkdownLinksActiv {
		return fmt.Sprintf("%s#L%v.%v", file, position.Line+1, position.Character)
	}
	return fmt.Sprintf("%s#L%v", file, position.Line+1)

}

func CreateMarkdownLinkComplete(file protokoll.DocumentURI, node *tree_sitter.Node, text string, hovertext string) string {
	return fmt.Sprintf("[%s](%s \"%s\")", text, CreateMarkdownLinkFromNode(file, node), hovertext)
}
