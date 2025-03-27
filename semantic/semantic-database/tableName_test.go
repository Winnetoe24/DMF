package semantic_database

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"slices"
	"testing"
)

func TestPathSort(t *testing.T) {
	paths := []base.ModelPath{{"com", "beispiel", "Test"}, {"de", "Test"}, {"com", "Test"}, {"de", "beispiel", "Test"}}
	slices.SortFunc(paths, func(a, b base.ModelPath) int {
		return len(a) - len(b)
	})
	if len(paths[0]) != 2 {
		t.Errorf("paths not sorted: %+v\n", paths)
	}
	if len(paths[1]) != 2 {
		t.Errorf("paths not sorted: %+v\n", paths)
	}
	if len(paths[2]) != 3 {
		t.Errorf("paths not sorted: %+v\n", paths)
	}
	if len(paths[3]) != 3 {
		t.Errorf("paths not sorted: %+v\n", paths)
	}
	//fmt.Printf("paths sorted: %+v\n", paths)
}

func TestDetermineTableNames(t *testing.T) {
	paths := []base.ModelPath{{"de", "Test"}, {"com", "Test"}, {"com", "beispiel", "Test"}, {"de", "beispiel", "Test"}}

	tableLookUp := make(map[string]string)
	determineTableNames(paths, &tableLookUp)

	if tableLookUp["de.Test"] != "DeTest" {
		t.Errorf("tableLookUp not deTest: %+v\n", tableLookUp)
	}
}
