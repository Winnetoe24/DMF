package protokoll

import tree_sitter "github.com/tree-sitter/go-tree-sitter"

// Position represents a position in a text document
type Position struct {
	Line      uint32 `json:"line"`      // Line position in a document (zero-based)
	Character uint32 `json:"character"` // Character offset on a line (zero-based)
}

func ToPosition(point tree_sitter.Point) Position {
	return Position{
		Line:      uint32(point.Row),
		Character: uint32(point.Column),
	}
}

// Range represents a range in a text document
type Range struct {
	Start Position `json:"start"`
	End   Position `json:"end"`
}

func ToRange(r tree_sitter.Range) Range {
	return Range{
		Start: ToPosition(r.StartPoint),
		End:   ToPosition(r.EndPoint),
	}
}

// Location represents a location inside a resource
type Location struct {
	URI   DocumentURI `json:"uri"`
	Range Range       `json:"range"`
}

func NodeToLocation(node *tree_sitter.Node, uri DocumentURI) Location {
	return Location{
		URI:   uri,
		Range: ToRange(node.Range()),
	}
}

// TextDocumentItem represents an open text document
type TextDocumentItem struct {
	URI        DocumentURI `json:"uri"`
	LanguageID string      `json:"languageId"`
	Version    int32       `json:"version"`
	Text       string      `json:"text"`
}

// TextDocumentIdentifier identifies a text document
type TextDocumentIdentifier struct {
	URI DocumentURI `json:"uri"`
}

// VersionedTextDocumentIdentifier identifies a specific version of a text document
type VersionedTextDocumentIdentifier struct {
	TextDocumentIdentifier
	Version int32 `json:"version"`
}
