package semantic_database

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"iter"
	"maps"
	"slices"
	"strings"
)

func createTableLookUp(up smodel.TypeLookUp) map[string]string {
	nameToPaths := make(map[string][]base.ModelPath)

	// Menge der Pfade für jeden Namen bestimmen
	for _, element := range up {
		switch element.(type) {
		case *packages.EntityElement:
		case *packages.InterfaceElement:
		default:
			continue
		}
		path := element.GetBase().Path
		name := path[len(path)-1]
		nameToPaths[name] = append(nameToPaths[name], path)
	}

	tableLookUp := make(map[string]string)
	for _, paths := range nameToPaths {
		slices.SortFunc(paths, func(a, b base.ModelPath) int {
			return len(a) - len(b)
		})
		determineTableNames(paths, &tableLookUp)
	}
	return tableLookUp
}

func determineTableNames(paths []base.ModelPath, tableLookUp *map[string]string) {
	//tablePath := base.ModelPath{path[len(path)-1]}
	//for _, verglichenerPfad := range paths {
	//	if len(verglichenerPfad) <= len(path) {
	//		tablePath = append(base.ModelPath{path[len(path)-len(tablePath)-1]}, tablePath...)
	//	}
	//}
	currentNames := make(map[string]base.ModelPath)
	for _, path := range paths {
		currentNames[path.ToString()] = base.ModelPath{path[len(path)-1]}
	}

	for duplicateLength := namesUnique(maps.Values(currentNames)); duplicateLength >= 0; duplicateLength = namesUnique(maps.Values(currentNames)) {
		//fmt.Printf("currentNames: %v\n", currentNames)
		for i := len(paths) - 1; i >= 0; i-- {

			path := paths[i]
			fullName := path.ToString()
			name := currentNames[fullName]
			lenName := len(name)
			if lenName < duplicateLength || len(path) == duplicateLength {
				break
			}

			// add Package to Name
			if lenName == duplicateLength {
				name = append(base.ModelPath{path[len(path)-lenName-1]}, name...)
				currentNames[fullName] = name
			}

		}
	}
	ziel := *tableLookUp
	for path, name := range currentNames {
		ziel[path] = modelPathToTableName(name)
	}
	//return func(yield func(string) bool) {
	//	next, stop := iter.Pull(values)
	//	defer stop()
	//	for {
	//		path, ok := next()
	//		if !ok {
	//			return
	//		}
	//		name := ""
	//		for _, element := range path {
	//			name += strings.ToUpper(element[0:1]) + element[1:]
	//		}
	//		yield(name)
	//	}
	//}
}

// namesUnique findet die Länge des längsten base.ModelPath welcher nicht unique ist.
// Sind alle Werte unique, wird -1 zurückgegeben.
func namesUnique(values iter.Seq[base.ModelPath]) int {
	sortedValues := make([]base.ModelPath, 0)
	for path := range values {
		sortedValues = append(sortedValues, path)
	}
	slices.SortFunc(sortedValues, func(a, b base.ModelPath) int {
		return len(b) - len(a)
	})
	m := make(map[string]bool)
	for _, path := range sortedValues {
		exists := m[path.ToString()]
		if exists {
			return len(path)
		}
		m[path.ToString()] = true
	}
	return -1
}

func modelPathToTableName(path base.ModelPath) string {
	name := ""
	for _, element := range path {
		name += strings.ToUpper(element[0:1]) + element[1:]
	}
	return name
}
