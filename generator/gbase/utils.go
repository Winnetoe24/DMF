package gbase

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"slices"
	"strconv"
)

func ToFields(argumente []packages.Argument, referenzen []packages.Referenz, multiReferenzen []packages.MultiReferenz, kontext ImportKontext,
	primitiveTypeMapping func(base.PrimitivType, ImportKontext, bool) string,
	buildGenericType func(element *packages.MultiReferenz, kontext ImportKontext) (typ string, value string)) []FieldData {
	data := make([]FieldData, 0)
	lookup := make(map[uint]packages.Variable)
	keys := make([]uint, 0, len(argumente)+len(referenzen))
	for _, argument := range argumente {
		startByte := argument.Node.StartByte()
		_, found := lookup[startByte]
		if found {
			position := argument.Node.StartPosition()
			panic("Duplicate Elements at Pos: " + strconv.FormatUint(uint64(position.Row), 10) + ":" + strconv.FormatUint(uint64(position.Column), 10))
		}
		keys = append(keys, startByte)
		lookup[startByte] = &argument
	}
	for _, referenz := range referenzen {
		startByte := referenz.Node.StartByte()
		_, found := lookup[startByte]
		if found {
			position := referenz.Node.StartPosition()
			panic("Duplicate Elements at Pos: " + strconv.FormatUint(uint64(position.Row), 10) + ":" + strconv.FormatUint(uint64(position.Column), 10))
		}
		keys = append(keys, startByte)
		lookup[startByte] = &referenz
	}
	for _, referenz := range multiReferenzen {
		startByte := referenz.Node.StartByte()
		_, found := lookup[startByte]
		if found {
			position := referenz.Node.StartPosition()
			panic("Duplicate Elements at Pos: " + strconv.FormatUint(uint64(position.Row), 10) + ":" + strconv.FormatUint(uint64(position.Column), 10))
		}
		keys = append(keys, startByte)
		lookup[startByte] = &referenz
	}
	slices.Sort(keys)
	for _, key := range keys {
		variable := lookup[key]
		switch element := variable.(type) {
		case *packages.Argument:
			typ := primitiveTypeMapping(element.Typ, kontext, false)
			data = append(data, FieldData{
				Typ:       typ,
				Name:      element.Name.Name,
				Kommentar: element.Kommentar,
			})
		case *packages.Referenz:
			data = append(data, FieldData{
				Typ:       PathType(element.Typ, kontext),
				Name:      element.Name.Name,
				Kommentar: element.Kommentar,
			})
		case *packages.MultiReferenz:
			typ, value := buildGenericType(element, kontext)
			data = append(data, FieldData{
				Typ:       typ,
				Name:      element.Name.Name,
				Kommentar: element.Kommentar,
				Value:     &value,
			})

		}
	}
	return data
}

//func ImportedName(name string, fullQualifiedName string, up ImportLookUp) string {
//	lImport, found := up[name]
//	if found && lImport.OriginalName.ToString() == fullQualifiedName {
//		return name
//	} else {
//		return fullQualifiedName
//	}
//}

// PathType returns the Type used in the current ImportKontext for the given base.ModelPath
func PathType(pPath base.ModelPath, kontext ImportKontext) string {
	name := pPath[len(pPath)-1]
	path, found := kontext.ImportLookUp[name]
	if found && path.OriginalName.ToString() == pPath.ToString() {
		return name
	}
	return pPath.ToString()
}
