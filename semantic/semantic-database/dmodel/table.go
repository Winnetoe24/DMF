package dmodel

import "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"

type Table struct {
	Name string
	//For TableReason
	Columns           []*Column
	TablesForElements []TableReference
}

type Column struct {
	Name       string
	Type       base.PrimitivType
	PrimaryKey bool
	ForeignKey *ColumnReference
	Kommentar  string
}

type ColumnReference struct {
	TableName string
	Column    *Column
}

type TableReference struct {
	Referenzname string
	// Extra Tabellen werden für mehrere Tabellen generiert.
	// Sie werden im Datenbankschema besonders behandelt.
	IsExtra bool
	*Table
}
