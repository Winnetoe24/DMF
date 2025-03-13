package database

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-database/dmodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
)

func mapType(primitivType base.PrimitivType) string {
	switch primitivType {
	case base.BOOLEAN:
		return "boolean"
	case base.STRING:
		return "VARCHAR(255)"
	case base.BYTE:
		return "SMALLINT"
	case base.INT:
		return "INTEGER"
	case base.LONG:
		return "INTEGER"
	case base.DATE:
		return "DATE"
	case base.DATETIME:
		return "TIMESTAMP"
	case base.DOUBLE:
		return "float(8)"
	}
	return ""
}

func findPrimaryKeys(table dmodel.Table) []string {
	keys := make([]string, 0)
	for _, column := range table.Columns {
		if column.PrimaryKey {
			keys = append(keys, column.Name)
		}
	}
	return keys
}
