package builder

import "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"

// PreBuilder enthält alle Informationen,
// die vor der Entscheidung für einen StatementTypen,
// gesammelt werden
type PreBuilder struct {
	Kommentar   *base.Comment
	Expand      bool
	CurrentPath base.ModelPath
}
