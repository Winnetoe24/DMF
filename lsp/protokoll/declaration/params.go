package declaration

import (
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
)

// DeclarationParams represents the parameters sent in a declaration request
type DeclarationParams struct {
	// TextDocument identifies the document the declaration is requested for
	TextDocument protokoll.TextDocumentIdentifier `json:"textDocument"`

	// Position defines the position in the text document where declaration is requested
	Position protokoll.Position `json:"position"`
}

// DeclarationLink represents a declaration target with an optional origin range
type DeclarationLink struct {
	// Origin is the range of the symbol that is being declared
	Origin *protokoll.Range `json:"originSelectionRange,omitempty"`

	// Target is the URI and range of the declaration target
	TargetURI            string          `json:"targetUri"`
	TargetRange          protokoll.Range `json:"targetRange"`
	TargetSelectionRange protokoll.Range `json:"targetSelectionRange"`
}

func NodeToDeclarationLink(sourceNode *tree_sitter.Node, targetNode *tree_sitter.Node, link protokoll.DocumentURI) DeclarationLink {
	originRange := protokoll.ToRange(sourceNode.Range())
	return DeclarationLink{
		Origin:               &originRange,
		TargetURI:            string(link),
		TargetRange:          protokoll.ToRange(targetNode.Range()),
		TargetSelectionRange: protokoll.ToRange(targetNode.Range()),
	}
}
