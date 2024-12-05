package err_element

import (
	"fmt"
	"github.com/tree-sitter/go-tree-sitter"
	"strings"
)

type ErrorElement struct {
	Fehler FehlerStelle
	Error  error
	// Falls es einen Grund gibt, weshalb ein Fehler aufgetreten ist und dieser Grund an einer anderen Stelle des Codes liegt
	Cause *FehlerStelle
}

type FehlerStelle struct {
	// Die Node von der, der ModelCode stammt, und die ein Parent von der eigentlichen Node ist.
	// Ist nil, wenn der ModelCode von der eigentlichen Node kommt
	ContextNode *tree_sitter.Node
	ModelCode   string
	Node        *tree_sitter.Node
}

func (e ErrorElement) ToErrorMsg() string {
	return e.ToErrorMsgFile("example-file")
}
func (e ErrorElement) ToErrorMsgFile(filename string) string {
	var offsetStart int
	var offsetEnd int
	if e.Fehler.ContextNode != nil {
		offsetStart = int(e.Fehler.Node.StartPosition().Column - e.Fehler.ContextNode.StartPosition().Column)
		if e.Fehler.ContextNode.EndPosition().Row == e.Fehler.Node.EndPosition().Row && e.Fehler.Node.StartPosition().Row == e.Fehler.Node.EndPosition().Row {
			offsetEnd = int(e.Fehler.ContextNode.EndPosition().Column - e.Fehler.Node.EndPosition().Column)
		}
	}

	underline := strings.Repeat(" ", offsetStart) + strings.Repeat("^", len(e.Fehler.ModelCode)-offsetStart-offsetEnd) + strings.Repeat(" ", offsetEnd)

	return fmt.Sprintf("FehlerStelle in Position %v:%v:%v\n%s\n%s\n%v\n", filename, e.Fehler.Node.StartPosition().Row+1, e.Fehler.Node.StartPosition().Column, e.Fehler.ModelCode, underline, e.Error)
}

type ErrorCapable interface {
	GetAllErrorElements() []ErrorElement
}
