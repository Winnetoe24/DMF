package semantic_database

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"slices"
)

func createImplementationLookUp(up smodel.TypeLookUp) map[string][]packages.PackageElement {
	interfaces := make([]string, 0)
	for _, element := range up {
		switch inte := element.(type) {
		case *packages.InterfaceElement:
			interfaces = append(interfaces, inte.Path.ToString())
		}
	}

	implementationLookUp := make(map[string][]packages.PackageElement)
	for _, interfaceName := range interfaces {
		implementationsLast := []string{}
		implementations := []string{interfaceName}
		for !slices.Equal(implementations, implementationsLast) {
			implementationsLast = implementations
			for _, element := range up {
				if slices.Contains(implementations, element.GetBase().Path.ToString()) {
					continue
				}
				switch element := element.(type) {
				case *packages.InterfaceElement:
					for _, path := range element.ImplementsPaths {
						if slices.Contains(implementations, path.ToString()) {
							implementations = append(implementations, element.Path.ToString())
							break
						}
					}
				case *packages.EntityElement:
					found := false
					for _, path := range element.ImplementsPaths {
						if slices.Contains(implementations, path.ToString()) {
							implementations = append(implementations, element.Path.ToString())
							found = true
							break
						}
					}
					if !found && element.ExtendsPath != nil {
						if slices.Contains(implementations, element.ExtendsPath.ToString()) {
							implementations = append(implementations, element.Path.ToString())
						}
					}
				case *packages.StructElement:
					found := false
					for _, path := range element.ImplementsPaths {
						if slices.Contains(implementations, path.ToString()) {
							implementations = append(implementations, element.Path.ToString())
							found = true
							break
						}
					}
					if !found && element.ExtendsPath != nil {
						if slices.Contains(implementations, element.ExtendsPath.ToString()) {
							implementations = append(implementations, element.Path.ToString())
						}
					}
				}
			}
		}
		implementationPackageElements := make([]packages.PackageElement, 0, len(implementations)-1)
		for _, element := range implementations {
			if element != interfaceName {
				implementationPackageElements = append(implementationPackageElements, up[element])
			}
		}
		implementationLookUp[interfaceName] = implementationPackageElements
	}
	return implementationLookUp
}
