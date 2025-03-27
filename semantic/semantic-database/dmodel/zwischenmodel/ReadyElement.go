package zwischenmodel

import "github.com/Winnetoe24/DMF/semantic/semantic-database/dmodel"

type ReadyElement struct {
	IdentifierReadyElement
	Columns []*dmodel.Column
}

func (r *ReadyElement) getIdentifiable() Identifiable {
	return r
}
