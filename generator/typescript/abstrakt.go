package typescript

import (
	"github.com/Winnetoe24/DMF/generator/gbase"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
)

func computeImplementNames(paths []base.ModelPath, kontext gbase.ImportKontext) []string {
	implements := make([]string, len(paths))
	for i, path := range paths {
		implements[i] = gbase.PathType(path, kontext)
	}
	return implements
}
