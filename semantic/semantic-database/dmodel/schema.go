package dmodel

type Schema struct {
	TableLookUp map[string]*Table
	// Reihenfolge der Elemente deren Tabellen generiert wurden aus der Modelldatei.
	// Tabellen für Interfaces sind davon ausgenommen und folgen immer am Ende dieser Liste.
	FileOrdner []string
}
