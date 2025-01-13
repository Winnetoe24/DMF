package completionService

import (
	"encoding/json"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/protokoll/completion"
	"github.com/Winnetoe24/DMF/lsp/protokoll/initialize"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/server/connect/connectUtils"
	"github.com/Winnetoe24/DMF/lsp/service"
	"github.com/Winnetoe24/DMF/lsp/service/fileService"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

const completionMethod = "textDocument/completion"

type CompletionService struct {
	con connect.Connection
	fs  *fileService.FileService
}

func NewCompletionService(con connect.Connection, fs *fileService.FileService) *CompletionService {
	return &CompletionService{
		con: con,
		fs:  fs,
	}
}

var _ service.MethodHandler = &CompletionService{}

func (c CompletionService) Initialize(params *initialize.InitializeParams, result *initialize.InitializeResult) {
	result.Capabilities.CompletionProvider = &initialize.CompletionOptions{
		ResolveProvider:     false,
		TriggerCharacters:   nil,
		AllCommitCharacters: nil,
	}
}

func (c CompletionService) GetMethods() []string {
	return []string{completionMethod}
}

func (c CompletionService) HandleMethod(message protokoll.Message) {
	switch message.Method {
	case completionMethod:
		params := completion.CompletionParams{}
		err := json.Unmarshal(message.Params, &params)
		if err != nil {
			connectUtils.WriteErrorToCon(c.con, message.ID, err, protokoll.ParseError)
			return
		}

		logger := logService.GetLogger()
		logger.Printf("%sStart Get File Content\n", logService.TRACE)
		content, err := c.fs.GetFileContent(params.TextDocument.URI)

		if err != nil {
			panic(err)
		}
		node := content.Ast.RootNode()
		cursor := content.Ast.Walk()
		logger.Printf("%sStart Find Completion Node\n", logService.TRACE)
		completionNode := findCompletionNode(cursor, node, params.Position)
		logger.Printf("%sStart Node to Completion with node: %v\n", logService.TRACE, completionNode)
		completionItem := nodeToCompletion(completionNode)
		c.con.WriteMessage(protokoll.Message{
			JsonRPC: "2.0",
			ID:      message.ID,
			Method:  "",
			Params:  nil,
			Result: completion.CompletionResponse{
				IsIncomplete: false,
				Items:        []completion.CompletionItem{completionItem},
			},
			Error: nil,
		})
	}

}

func findCompletionNode(cursor *tree_sitter.TreeCursor, node *tree_sitter.Node, position protokoll.Position) *tree_sitter.Node {
	if isInRange(node.Range(), position) {
		logService.GetLogger().Printf("%sNode in Range: %v\n", logService.TRACE, node)
		children := node.Children(cursor)
		if len(children) > 0 {
			for _, child := range children {
				foundNode := findCompletionNode(cursor, &child, position)
				if foundNode != nil {
					return foundNode
				}
			}
		} else {
			return node
		}
	}
	return nil
}

func isInRange(p tree_sitter.Range, position protokoll.Position) bool {
	return p.StartPoint.Row <= uint(position.Line) && p.StartPoint.Column <= uint(position.Character) &&
		p.EndPoint.Row >= uint(position.Line) && p.EndPoint.Column >= uint(position.Character)
}

func nodeToCompletion(node *tree_sitter.Node) completion.CompletionItem {
	name := node.GrammarName()
	return completion.CompletionItem{
		Label:               name,
		Kind:                0,
		Detail:              "",
		Documentation:       "",
		Deprecated:          false,
		Preselect:           false,
		SortText:            "",
		FilterText:          "",
		InsertText:          name,
		InsertTextFormat:    0,
		TextEdit:            nil,
		AdditionalTextEdits: nil,
		CommitCharacters:    nil,
		Command:             nil,
		Data:                nil,
	}
}
