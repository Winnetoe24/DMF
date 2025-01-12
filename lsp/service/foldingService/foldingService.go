package foldingService

import (
	"encoding/json"
	tree_sitter_dmf "github.com/Winnetoe24/DMF/grammar/dmf_language"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/protokoll/folding"
	"github.com/Winnetoe24/DMF/lsp/protokoll/initialize"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/server/connect/connectUtils"
	"github.com/Winnetoe24/DMF/lsp/service"
	"github.com/Winnetoe24/DMF/lsp/service/fileService"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

const foldingRangeMethod = "textDocument/foldingRange"

type FoldingService struct {
	con            connect.Connection
	fs             *fileService.FileService
	lineFoldOnly   bool
	rangeLimit     *uint32
	kommentarQuery *tree_sitter.Query
}

func NewFoldingService(connection connect.Connection, fs *fileService.FileService) *FoldingService {
	query, queryError := tree_sitter_dmf.Query("(comment_block)")
	if queryError != nil {
		logService.GetLogger().Printf("%s%v\v", logService.ERROR, queryError)
	}
	return &FoldingService{
		con:            connection,
		fs:             fs,
		lineFoldOnly:   false,
		kommentarQuery: query,
	}
}

var _ service.MethodHandler = &FoldingService{}

func (f *FoldingService) Initialize(params *initialize.InitializeParams, result *initialize.InitializeResult) {
	result.Capabilities.FoldingRangeProvider = true

	// Check client capabilities for folding support
	if params.Capabilities.TextDocument != nil &&
		params.Capabilities.TextDocument.FoldingRange != nil {
		clientFoldingCaps := params.Capabilities.TextDocument.FoldingRange
		f.lineFoldOnly = clientFoldingCaps.LineFoldingOnly
		f.rangeLimit = clientFoldingCaps.RangeLimit
	}
}

func (f *FoldingService) GetMethods() []string {
	return []string{foldingRangeMethod}
}

func (f *FoldingService) HandleMethod(message protokoll.Message) {
	switch message.Method {
	case foldingRangeMethod:
		logger := logService.GetLogger()
		params := folding.FoldingRangeParams{}
		err := json.Unmarshal(message.Params, &params)
		if err != nil {
			connectUtils.WriteErrorToCon(f.con, message.ID, err, protokoll.ParseError)
			return
		}

		content, err := f.fs.GetFileContent(params.TextDocument.URI)
		if err != nil {
			connectUtils.WriteErrorToCon(f.con, message.ID, err, protokoll.InternalError)
			return
		}

		ranges := f.getFoldingRanges(content)
		if f.rangeLimit != nil && len(ranges) > int(*f.rangeLimit) {
			ranges = ranges[:*f.rangeLimit]
		}

		f.con.WriteMessage(protokoll.Message{
			JsonRPC: "2.0",
			ID:      message.ID,
			Result:  ranges,
		})

		logger.Printf("%sFinished Folding Range\n", logService.TRACE)
	}
}

func (f *FoldingService) getFoldingRanges(content fileService.FileContent) []folding.FoldingRange {
	var ranges []folding.FoldingRange

	// Add package folding ranges
	for _, element := range content.LookUp {
		ranges = append(ranges, f.createFoldingRange(element))
	}

	// Add comment folding ranges
	//ranges = append(ranges, f.getCommentFoldingRanges(&content.Ast)...)

	// Add import folding ranges
	ranges = append(ranges, f.getImportFoldingRanges(content.Model.ImportStatements)...)

	return ranges
}

func (f *FoldingService) createFoldingRange(element packages.PackageElement) folding.FoldingRange {
	baseElement := element.GetBase()

	cursor := baseElement.Node.Walk()
	var startNode *tree_sitter.Node = nil
	var endNode *tree_sitter.Node = nil
	cursor.GotoFirstChild()
	for {
		if cursor.Node().GrammarName() == "{" {
			startNode = cursor.Node()
		}
		if cursor.Node().GrammarName() == "}" {
			endNode = cursor.Node()
		}
		if !cursor.GotoNextSibling() {
			break
		}
	}
	startPos := startNode.StartPosition()
	endPos := endNode.EndPosition()

	fRange := folding.FoldingRange{
		StartLine: uint32(startPos.Row),
		EndLine:   uint32(endPos.Row),
	}

	if !f.lineFoldOnly {
		startChar := uint32(startPos.Column) + 1
		endChar := uint32(endPos.Column) - 1
		fRange.StartCharacter = &startChar
		fRange.EndCharacter = &endChar
	}

	return fRange
}

func (f *FoldingService) getCommentFoldingRanges(root *tree_sitter.Tree) []folding.FoldingRange {
	var ranges []folding.FoldingRange
	queryCursor := tree_sitter.NewQueryCursor()
	captures := queryCursor.Captures(f.kommentarQuery, root.RootNode(), nil)
	for match, index := captures.Next(); match != nil; match, index = captures.Next() {
		node := match.Captures[index].Node
		startPos := node.StartPosition()
		endPos := node.EndPosition()

		if startPos.Row != endPos.Row {
			kind := folding.Comment
			fRange := folding.FoldingRange{
				StartLine: uint32(startPos.Row),
				EndLine:   uint32(endPos.Row),
				Kind:      &kind,
			}

			if !f.lineFoldOnly {
				startChar := uint32(startPos.Column)
				endChar := uint32(endPos.Column)
				fRange.StartCharacter = &startChar
				fRange.EndCharacter = &endChar
			}

			ranges = append(ranges, fRange)
		}
	}
	//for {
	//	node := cursor.Node()
	//	if node.GrammarName() == "comment_block" {
	//
	//	}
	//
	//	if !cursor.GotoNextSibling() {
	//		if !cursor.GotoParent() {
	//			break
	//		}
	//	}
	//}

	return ranges
}

func (f *FoldingService) getImportFoldingRanges(imports []smodel.ImportStatement) []folding.FoldingRange {
	if len(imports) <= 1 {
		return nil
	}

	startPos := imports[0].Node.StartPosition()
	endPos := imports[len(imports)-1].Node.EndPosition()
	kind := folding.Imports

	fRange := folding.FoldingRange{
		StartLine: uint32(startPos.Row),
		EndLine:   uint32(endPos.Row),
		Kind:      &kind,
	}

	if !f.lineFoldOnly {
		startChar := uint32(startPos.Column)
		endChar := uint32(endPos.Column)
		fRange.StartCharacter = &startChar
		fRange.EndCharacter = &endChar
	}

	return []folding.FoldingRange{fRange}
}
