package data

import (
	"fmt"
)

type (
	Stack[E any] struct {
		top    *node[E]
		length int
	}
	node[E any] struct {
		value E
		prev  *node[E]
	}
)

func CreateStack[E any](values ...E) *Stack[E] {
	stack := &Stack[E]{}
	for _, value := range values {
		stack.Push(value)
	}
	return stack
}

func (s *Stack[E]) Peek() E {
	return s.top.value
}

func (s *Stack[E]) Pop() E {
	top := s.top
	s.top = top.prev
	s.length--
	return top.value
}

func (s *Stack[E]) Length() int {
	return s.length
}

func (s *Stack[E]) Push(value E) {
	newNode := &node[E]{
		value: value,
		prev:  s.top,
	}
	s.top = newNode
	s.length++
}

func (s *Stack[E]) String() string {
	array := "["
	current := s.top
	if current != nil {
		array += fmt.Sprintf("%v", current.value)
		current = current.prev
	}
	for current != nil {
		array += fmt.Sprintf(", %v", current.value)
		current = current.prev
	}
	array += "]"
	return fmt.Sprintf("Stack(%v, %s)", s.length, array)
}
