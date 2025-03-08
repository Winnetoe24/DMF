package foldingService

import (
	"encoding/json"
	tree_sitter_dmf "github.com/Winnetoe24/DMF/grammar/dmf_language"
	"github.com/Winnetoe24/DMF/lsp/args"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/protokoll/folding"
	"github.com/Winnetoe24/DMF/lsp/protokoll/initialize"
	"github.com/Winnetoe24/DMF/lsp/server/connect"
	"github.com/Winnetoe24/DMF/lsp/server/connect/connectUtils"
	"github.com/Winnetoe24/DMF/lsp/service"
	"github.com/Winnetoe24/DMF/lsp/service/fileService"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"strings"
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
	query, queryError := tree_sitter_dmf.Query("(comment_block) @cb")
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
		defer content.Close()

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
	var ranges = make([]folding.FoldingRange, 0)

	// Add package folding ranges
	for _, element := range content.LookUp {
		ranges = append(ranges, f.createFoldingRange(element))
	}

	// Add comment folding ranges
	ranges = append(ranges, f.getCommentFoldingRanges(content.Ast, content.Content)...)

	// Add import folding ranges
	ranges = append(ranges, f.getImportFoldingRanges(content.Ast, content.Content)...)

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

	kind := folding.Region
	fRange := folding.FoldingRange{
		Kind:      &kind,
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

func (f *FoldingService) getCommentFoldingRanges(root *tree_sitter.Tree, content string) []folding.FoldingRange {
	var ranges []folding.FoldingRange
	//logger := logService.GetLogger()
	queryCursor := tree_sitter.NewQueryCursor()
	captures := queryCursor.Captures(f.kommentarQuery, root.RootNode(), nil)
	bytes := []byte(content)
	for match, index := captures.Next(); match != nil; match, index = captures.Next() {
		node := match.Captures[index].Node
		startPos := node.StartPosition()
		endPos := node.EndPosition()
		endPos.Row--

		if startPos.Row != endPos.Row {
			kind := folding.Comment
			fRange := folding.FoldingRange{
				StartLine: uint32(startPos.Row),
				EndLine:   uint32(endPos.Row),
				Kind:      &kind,
			}

			if !f.lineFoldOnly {
				text := node.Utf8Text(bytes)
				split := strings.Split(text, "\n")
				if len(split) > 0 {
					endPos.Column = uint(len(split[len(split)-2]))
					startIndex := strings.Index(split[0], "//") + 2
					startPos.Column = uint(startIndex)
					collapsed := split[0][startIndex:]
					fRange.CollapsedText = &collapsed
				}
				startChar := uint32(startPos.Column)
				endChar := uint32(endPos.Column)
				fRange.StartCharacter = &startChar
				fRange.EndCharacter = &endChar
			}

			ranges = append(ranges, fRange)
		} else if !args.DisableSingleLineCommentsFolding {
			text := node.Utf8Text(bytes)
			endPos.Column = uint(len(text))
			startPos.Column = uint(strings.Index(text, "//") + 2)
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

	//logger.Printf("%sFound %v Comment Ranges\n", logService.TRACE, len(ranges))
	return ranges
}

func (f *FoldingService) getImportFoldingRanges(ast *tree_sitter.Tree, content string) []folding.FoldingRange {

	cursor := ast.Walk()
	cursor.GotoFirstChild()
	var importBlock *tree_sitter.Node = nil
	var endPos tree_sitter.Point
	for {
		if cursor.Node().GrammarName() == "import_block" {
			importBlock = cursor.Node()
			cursor.GotoLastChild()
			endPos = cursor.Node().EndPosition()
			text := cursor.Node().Utf8Text([]byte(content))
			split := strings.Split(text, "\n")
			length := len(split)
			for i := range split {
				s := split[length-i-1]
				if strings.ContainsFunc(s, func(r rune) bool {
					switch r {
					case ' ', '\n':
						return false
					default:
						return true
					}
				}) {
					endPos.Column = uint(len(split[length-i-1]))
				} else {
					endPos.Row--
				}
			}
			break
		}
		if !cursor.GotoNextSibling() {
			break
		}
	}
	kind := folding.Imports

	if importBlock == nil || importBlock.GrammarName() != "import_block" {
		return []folding.FoldingRange{}
	}
	startPos := importBlock.StartPosition()

	collapsed := "Imports\n"
	fRange := folding.FoldingRange{
		StartLine:     uint32(startPos.Row),
		EndLine:       uint32(endPos.Row),
		Kind:          &kind,
		CollapsedText: &collapsed,
	}

	if !f.lineFoldOnly {
		startChar := uint32(startPos.Column)
		endChar := uint32(endPos.Column)
		fRange.StartCharacter = &startChar
		fRange.EndCharacter = &endChar
	}

	return []folding.FoldingRange{fRange}
}
