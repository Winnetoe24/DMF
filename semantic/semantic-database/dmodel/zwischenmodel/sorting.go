package zwischenmodel

import "github.com/Winnetoe24/DMF/semantic/sorting"

func SortNamedElementWrapper(a, b *NamedElementWrapper) int {
	if cmp := sorting.SortPointer(a, b); cmp != 0 {
		return cmp
	}
	if cmp := sorting.SortInterface(a.Element, b.Element); cmp != 0 {
		return cmp
	}
	return sorting.SortNodes(a.Element.Element().Node, b.Element.Element().Node)
}
