package base

type NamedElement interface {
	Element() ModelElement
	GetName() string
}
