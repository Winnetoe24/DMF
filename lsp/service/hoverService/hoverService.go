package hoverService

import (
	"encoding/json"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/protokoll/hover"
	"github.com/Winnetoe24/DMF/lsp/protokoll/initialize"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/server/connect/connectUtils"
	"github.com/Winnetoe24/DMF/lsp/service"
	"github.com/Winnetoe24/DMF/lsp/service/fileService"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
	"github.com/Winnetoe24/DMF/lsp/util"
)

const hoverMethod = "textDocument/hover"

type HoverService struct {
	con                  connect.Connection
	fs                   *fileService.FileService
	preferredHoverFormat hover.MarkupKind
}

func NewHoverService(connection connect.Connection, fs *fileService.FileService) *HoverService {
	return &HoverService{
		con:                  connection,
		fs:                   fs,
		preferredHoverFormat: hover.Markdown,
	}
}

var _ service.MethodHandler = &HoverService{}

func (h *HoverService) Initialize(params *initialize.InitializeParams, result *initialize.InitializeResult) {

	result.Capabilities.HoverProvider = true

	// Check client capabilities for hover support
	if params.Capabilities.TextDocument != nil &&
		params.Capabilities.TextDocument.Hover != nil {
		// Store client's preferred markup kinds for hover content
		clientHoverCaps := params.Capabilities.TextDocument.Hover
		if len(clientHoverCaps.ContentFormat) > 0 {
			// Store the client's preferred markup kinds for later use
			h.preferredHoverFormat = clientHoverCaps.ContentFormat[0]
		} else {
			// Default to markdown if client doesn't specify
			h.preferredHoverFormat = "markdown"
		}
	}

}

func (h *HoverService) GetMethods() []string {
	return []string{hoverMethod}
}

func (h *HoverService) HandleMethod(message protokoll.Message) {
	switch message.Method {
	case hoverMethod:
		logger := logService.GetLogger()
		params := hover.HoverParams{}
		err := json.Unmarshal(message.Params, &params)
		if err != nil {
			connectUtils.WriteErrorToCon(h.con, message.ID, err, protokoll.ParseError)
			return
		}
		logger.Printf("%sStart Get File Content\n", logService.TRACE)
		content, err := h.fs.GetFileContent(params.TextDocument.URI)
		if err != nil {
			panic(err)
		}

		logger.Printf("%Start Find Node\n", logService.TRACE)
		finder := util.NewNodeFinder([]byte(content.Content))
		nodeAroundPosition := finder.FindSmallestNodeAroundPosition(&content.Ast, params.Position)
		hoverContent := "Example hover content"
		if nodeAroundPosition != nil {
			hoverContent = "Found: " + nodeAroundPosition.GrammarName()
		}
		hoverResult := hover.HoverResult{
			Contents: createMarkupContent(
				h.preferredHoverFormat,
				hoverContent,
			),
			Range: &protokoll.Range{
				Start: params.Position,
				End:   params.Position,
			},
		}
		h.con.WriteMessage(protokoll.Message{
			JsonRPC: "2.0",
			ID:      message.ID,
			Method:  "",
			Params:  nil,
			Result:  hoverResult,
			Error:   nil,
		})
		logger.Printf("%sFinished Hover with Content: %s\n", logService.TRACE, hoverContent)
	default:
		logger := logService.GetLogger()
		logger.Printf("%sUnknown Method:%s\n", logService.ERROR, message.Method)
	}

}

// Helper function to create properly formatted markup content
func createMarkupContent(kind hover.MarkupKind, content string) json.RawMessage {
	markup := hover.MarkupContent{
		Kind:  kind,
		Value: content,
	}
	raw, _ := json.Marshal(markup)
	return raw
}
