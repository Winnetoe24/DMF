package dmf_language

// #cgo CFLAGS: -std=c11 -fPIC
// #include "../src/parser.c"
// // NOTE: if your language has an external scanner, add it here.
import "C"

import (
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"unsafe"
)

// Get the tree-sitter Language for this grammar.
func Language() unsafe.Pointer {
	return unsafe.Pointer(C.tree_sitter_dmf())
}

func Query(query string) (*tree_sitter.Query, *tree_sitter.QueryError) {
	language := tree_sitter.NewLanguage(Language())
	return tree_sitter.NewQuery(language, query)
}

func ForEachQuery(query *tree_sitter.Query, tree *tree_sitter.Tree, f func(uint, *tree_sitter.Node) bool) {
	queryCursor := tree_sitter.NewQueryCursor()
	captures := queryCursor.Captures(query, tree.RootNode(), nil)
	for match, index := captures.Next(); match != nil; match, index = captures.Next() {
		node := match.Captures[index].Node
		if f(index, &node) {
			return
		}
	}
}
