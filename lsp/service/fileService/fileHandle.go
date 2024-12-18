package fileService

import (
	"fmt"
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/protokoll/textEdit"
	"github.com/Winnetoe24/DMF/lsp/service/logService"
	"github.com/Winnetoe24/DMF/semantic"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	errElement "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	semantic_rules "github.com/Winnetoe24/DMF/semantic/semantic-rules"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"strings"
)

type fileHandle struct {
	//handleMutex sync.RWMutex
	//subscribers []interface{}
	FileContent string
	Ast         *tree_sitter.Tree
	Model       *smodel.Model
	LookUp      *smodel.TypeLookUp
	Version     int32
}

func openFileHandle(params textEdit.DidOpenTextDocumentParams) (fileHandle, error) {

	afterTree := make(chan *tree_sitter.Tree)
	afterModel := make(chan *smodel.Model)

	errorElements, errPos, err, up := semantic.ParseNewFile(params.TextDocument.Text, afterTree, afterModel)

	// TODO Handle Error Elements DiagnosenService
	if errorElements != nil {
		path, _ := params.TextDocument.URI.ToFilePath()
		var ctx = &errElement.ErrorContext{
			Dateiname:   path,
			Dateiinhalt: []byte(params.TextDocument.Text),
		}
		for _, element := range errorElements {
			logger.Printf("%sError in TextFile:\n%s\n", logService.DEBUG, element.ToErrorMsg(ctx))
		}
	}
	if err != nil {
		switch errPos {
		case semantic_rules.ERROR_AFTER_TREE_SITTER_PARSER:
			logger.Printf("%sError after treesitter parser\n", logService.ERROR)
		case semantic_rules.ERROR_AFTER_SEMANTIC_PARSE:
			logger.Printf("%sError after semantic parser\n", logService.ERROR)
		}
		return fileHandle{}, err
	}
	tree := <-afterTree
	model := <-afterModel
	return fileHandle{
		FileContent: params.TextDocument.Text,
		Ast:         tree,
		Model:       model,
		LookUp:      &up,
	}, nil
}
func (receiver *fileHandle) EditFile(params textEdit.DidChangeTextDocumentParams) {

}

// InputEditResult contains the new content and the generated tree-sitter edits
type InputEditResult struct {
	NewContent      string
	TreeSitterEdits []tree_sitter.InputEdit
	Error           error
}

// ApplyChanges applies the LSP changes to the document content and generates tree-sitter input edits
func (doc *fileHandle) ApplyChanges(params *textEdit.DidChangeTextDocumentParams) InputEditResult {
	if doc.Version >= params.TextDocument.Version {
		return InputEditResult{
			Error: fmt.Errorf("version conflict: document version %d is newer than change version %d",
				doc.Version, params.TextDocument.Version),
		}
	}

	content := doc.FileContent
	var tsEdits []tree_sitter.InputEdit

	// Apply changes in order
	for _, change := range params.ContentChanges {
		var startIndex, endIndex int
		var err error

		if change.Range != nil {
			// Calculate byte offsets for the range
			startIndex, err = getByteOffset(content, change.Range.Start)
			if err != nil {
				return InputEditResult{Error: fmt.Errorf("start offset calculation failed: %w", err)}
			}

			endIndex, err = getByteOffset(content, change.Range.End)
			if err != nil {
				return InputEditResult{Error: fmt.Errorf("end offset calculation failed: %w", err)}
			}
		} else {
			// Full document replacement
			startIndex = 0
			endIndex = len(content)
		}

		// Create tree-sitter input edit
		tsEdit := tree_sitter.InputEdit{
			StartByte:      uint(startIndex),
			OldEndByte:     uint(endIndex),
			NewEndByte:     uint(startIndex + len(change.Text)),
			StartPosition:  pointFromPosition(change.Range.Start),
			OldEndPosition: pointFromPosition(change.Range.End),
			NewEndPosition: calculateNewEndPoint(content, startIndex, change.Text),
		}
		tsEdits = append(tsEdits, tsEdit)

		// Apply the change to the content
		content = content[:startIndex] + change.Text + content[endIndex:]
	}

	// Update document
	doc.FileContent = content
	doc.Version = params.TextDocument.Version

	return InputEditResult{
		NewContent:      content,
		TreeSitterEdits: tsEdits,
	}
}

// getByteOffset converts an LSP Position to a byte offset in the content
func getByteOffset(content string, pos protokoll.Position) (int, error) {
	lines := strings.Split(content, "\n")

	if int(pos.Line) >= len(lines) {
		return 0, fmt.Errorf("line number %d exceeds content lines %d", pos.Line, len(lines))
	}

	// Calculate offset up to the target line
	offset := 0
	for i := 0; i < int(pos.Line); i++ {
		offset += len(lines[i]) + 1 // +1 for the newline character
	}

	// Add character offset on the target line
	line := lines[pos.Line]
	if int(pos.Character) > len(line) {
		return 0, fmt.Errorf("character number %d exceeds line length %d", pos.Character, len(line))
	}

	return offset + int(pos.Character), nil
}

// pointFromPosition converts an LSP Position to a tree-sitter Point
func pointFromPosition(pos protokoll.Position) tree_sitter.Point {
	return tree_sitter.Point{
		Row:    uint(pos.Line),
		Column: uint(pos.Character),
	}
}

// calculateNewEndPoint calculates the ending Point after applying a change
func calculateNewEndPoint(content string, startOffset int, newText string) tree_sitter.Point {
	// Find the starting point
	startLine := 0
	startCol := 0
	for i := 0; i < startOffset; i++ {
		if content[i] == '\n' {
			startLine++
			startCol = 0
		} else {
			startCol++
		}
	}

	// Calculate the end point by counting lines and columns in the new text
	endLine := startLine
	endCol := startCol
	for _, ch := range newText {
		if ch == '\n' {
			endLine++
			endCol = 0
		} else {
			endCol++
		}
	}

	return tree_sitter.Point{
		Row:    uint(endLine),
		Column: uint(endCol),
	}
}

// Helper function to validate position
func isValidPosition(content string, pos protokoll.Position) bool {
	lines := strings.Split(content, "\n")
	if int(pos.Line) >= len(lines) {
		return false
	}
	return int(pos.Character) <= len(lines[pos.Line])
}
