package zwischenmodel

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-database/dmodel"
)

type IdentifierReadyElement struct {
	UnfinishedElement
	Identifier []*dmodel.Column
}

func (i *IdentifierReadyElement) GetIdentifiable() Identifiable {
	return i
}

func (i *IdentifierReadyElement) getIdentifier() []*dmodel.Column {
	return i.Identifier
}
