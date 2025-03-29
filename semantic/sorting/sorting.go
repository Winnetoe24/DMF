package sorting

import (
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

func SortNodes(a, b *tree_sitter.Node) int {
	if cmp := SortPointer(a, b); cmp != 0 {
		return cmp
	}
	if cmp := int(a.StartPosition().Row) - int(b.StartPosition().Row); cmp != 0 {
		return cmp
	}
	return int(a.StartPosition().Column) - int(b.StartPosition().Column)
}

func SortInterface(a, b interface{}) int {
	if a == nil {
		if b == nil {
			return 0
		} else {
			return -1
		}
	} else {
		if b == nil {
			return -1
		} else {
			return 0
		}
	}
}

func SortPointer[E any](a, b *E) int {
	if a == nil {
		if b == nil {
			return 0
		} else {
			return -1
		}
	} else {
		if b == nil {
			return -1
		} else {
			return 0
		}
	}
}
