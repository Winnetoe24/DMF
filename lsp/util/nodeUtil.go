package util

import (
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"slices"
)

// NodeFinder provides utilities for finding nodes in a Tree-sitter tree
// based on LSP positions
type NodeFinder struct {
	// sourceText is the full text of the document
	sourceText []byte
}

// NewNodeFinder creates a new NodeFinder instance
func NewNodeFinder(sourceText []byte) *NodeFinder {
	return &NodeFinder{
		sourceText: sourceText,
	}
}

// FindNodeAtPosition locates the most specific node in the tree that contains
// the given LSP position
func (nf *NodeFinder) FindNodeAtPosition(tree *tree_sitter.Tree, position protokoll.Position) *tree_sitter.Node {
	// Convert LSP position to byte offset
	offsetPtr := nf.positionToOffset(position)
	if offsetPtr == nil {
		return nil
	}
	offset := *offsetPtr

	// Start at the root node
	node := tree.RootNode()

	// Traverse down the tree to find the most specific node
	// that contains our position
	for {
		// Check if we've found a leaf node
		if node.ChildCount() == 0 {
			return node
		}

		// Look for a child node that contains our position
		foundChild := false
		for i := uint(0); i < node.ChildCount(); i++ {
			child := node.Child(i)
			if child == nil {
				continue
			}

			// Check if this child contains our position
			if nf.nodeContainsOffset(child, offset) {
				node = child
				foundChild = true
				break
			}
		}

		// If we didn't find a more specific child node, return the current node
		if !foundChild {
			return node
		}
	}
}

// positionToOffset converts an LSP position (line, character) to a byte offset
func (nf *NodeFinder) positionToOffset(position protokoll.Position) *uint {
	var currentLine uint32 = 0
	var currentChar uint32 = 0

	for offset := uint(0); offset < uint(len(nf.sourceText)); offset++ {
		// Have we reached the desired position?
		if currentLine == position.Line && currentChar == position.Character {
			return &offset
		}

		// Handle newlines
		if nf.sourceText[offset] == '\n' {
			currentLine++
			currentChar = 0
			continue
		}

		// For UTF-8, we need to handle multi-byte characters
		// This is a simplified version - you might want to use utf8.DecodeRune
		// for proper UTF-8 handling
		currentChar++
	}

	// Position not found
	return nil
}

// nodeContainsOffset checks if a node's range contains the given byte offset
func (nf *NodeFinder) nodeContainsOffset(node *tree_sitter.Node, offset uint) bool {
	return node.StartByte() <= offset && offset <= node.EndByte()
}

// GetNodeText retrieves the text content of a node
func (nf *NodeFinder) GetNodeText(node *tree_sitter.Node) string {
	if node == nil {
		return ""
	}
	return string(nf.sourceText[node.StartByte():node.EndByte()])
}

// FindSmallestNodeAroundPosition finds the smallest node that fully contains
// the given position, useful for precise hover information
func (nf *NodeFinder) FindSmallestNodeAroundPosition(tree *tree_sitter.Tree, position protokoll.Position) *tree_sitter.Node {
	node := nf.FindNodeAtPosition(tree, position)
	if node == nil {
		return nil
	}

	// Walk up the tree until we find a named node
	// This helps skip punctuation and other non-semantic nodes
	for node != nil && node.GrammarName() == "" {
		node = node.Parent()
	}

	return node
}

// FindSmallestNodeAroundPosition finds the smallest node that fully contains
// the given position, useful for precise hover information
func (nf *NodeFinder) FindSmallestNodeAroundPositionInSet(tree *tree_sitter.Tree, position protokoll.Position, set []string) *tree_sitter.Node {
	node := nf.FindNodeAtPosition(tree, position)
	if node == nil {
		return nil
	}

	// Walk up the tree until we find a named node
	// This helps skip punctuation and other non-semantic nodes
	for node != nil && (node.GrammarName() == "" || !slices.Contains(set, node.GrammarName())) {
		node = node.Parent()
	}

	return node
}

func (nf *NodeFinder) FindSmallestNodeAroundPositionInSets(tree *tree_sitter.Tree, position protokoll.Position, sets [][]string) []*tree_sitter.Node {
	node := nf.FindNodeAtPosition(tree, position)
	if node == nil {
		return nil
	}

	nodes := make([]*tree_sitter.Node, len(sets))

	// Walk up the tree until we find a named node
	// This helps skip punctuation and other non-semantic nodes
	for node != nil {
		if node.GrammarName() != "" {
			for i, set := range sets {
				if nodes[i] == nil && slices.Contains(set, node.GrammarName()) {
					nodes[i] = node
				}
			}
		}
		node = node.Parent()
	}

	return nodes
}
