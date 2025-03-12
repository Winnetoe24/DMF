package gbase

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"io"
)

type DMFTemplate interface {
	GenerateStruct(writer io.Writer, element *packages.StructElement) error
	GenerateEntity(writer io.Writer, element *packages.EntityElement) error
	GenerateEnum(writer io.Writer, element *packages.EnumElement) error
	GenerateInterface(writer io.Writer, element *packages.InterfaceElement) error
	GenerateDelegate(writer io.Writer, element packages.PackageElement) error
	GenerateDelegateInterface(writer io.Writer, element packages.PackageElement) error
}
