package selectionRangeService

import (
	"encoding/json"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/protokoll/initialize"
	"github.com/Winnetoe24/DMF/lsp/protokoll/selectionRange"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/server/connect/connectUtils"
	"github.com/Winnetoe24/DMF/lsp/service"
	"github.com/Winnetoe24/DMF/lsp/service/fileService"
	"github.com/Winnetoe24/DMF/lsp/util"
)

const selectionRangeMethod = "textDocument/selectionRange"

type SelectionRangeService struct {
	con connect.Connection
	fs  *fileService.FileService
}

func NewSelectionRangeService(con connect.Connection, fs *fileService.FileService) *SelectionRangeService {
	return &SelectionRangeService{con: con, fs: fs}
}

var _ service.MethodHandler = &SelectionRangeService{}

func (s *SelectionRangeService) Initialize(params *initialize.InitializeParams, result *initialize.InitializeResult) {

	result.Capabilities.SelectionRangeProvider = selectionRange.SelectionRangeOptions{
		WorkDoneProgress: false,
	}

}

func (s *SelectionRangeService) GetMethods() []string {
	return []string{selectionRangeMethod}
}

func (s *SelectionRangeService) HandleMethod(message protokoll.Message) {
	switch message.Method {
	case selectionRangeMethod:
		params := selectionRange.SelectionRangeParams{}
		err := json.Unmarshal(message.Params, &params)
		if err != nil {
			connectUtils.WriteErrorToCon(s.con, message.ID, err, protokoll.ParseError)
			return
		}

		content, err := s.fs.GetFileContent(params.TextDocument.URI)
		defer content.Close()

		result := make(selectionRange.SelectionRangeResult, 0)
		for _, position := range params.Positions {
			selection := s.computeSelectionRangeForPosition(content, position)
			if selection != nil {
				result = append(result, *selection)
			}
		}
		s.con.WriteMessage(protokoll.Message{
			JsonRPC: "2.0",
			ID:      message.ID,
			Result:  result,
		})
	}
}

func (s *SelectionRangeService) computeSelectionRangeForPosition(content fileService.FileContent, position protokoll.Position) *selectionRange.SelectionRange {
	finder := util.NewNodeFinder([]byte(content.Content))
	node := finder.FindSmallestNodeAroundPosition(content.Ast, position)
	var currentRange *selectionRange.SelectionRange
	for node != nil {
		newRange := &selectionRange.SelectionRange{
			Range: protokoll.ToRange(node.Range()),
		}
		newRange.Parent = currentRange
		currentRange = newRange

		node = node.Parent()
	}
	return currentRange
}
