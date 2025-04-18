package typescript

import (
	"embed"
	"github.com/Winnetoe24/DMF/generator/gbase"
	"github.com/Winnetoe24/DMF/semantic/semantic-database/dmodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"io"
	"text/template"
)

//go:embed template/*
var tmplFiles embed.FS

type TsTemplate struct {
	template *template.Template
}

var _ gbase.DMFTemplate = TsTemplate{}

func NewTemplate() TsTemplate {
	funcMap := template.FuncMap{
		"subtract": func(a, b int) int {
			return a - b
		},
		"sub": func(a, b int) int {
			return a - b
		},
		"add": func(a, b int) int {
			return a + b
		},
		"nameFromPath": func(path base.ModelPath) string {
			return path[len(path)-1]
		},
		"pathType":                 gbase.PathType,
		"toUpperCase":              gbase.ToUpperCase,
		"createImportKontext":      createTsImportKontext,
		"getImports":               getImports,
		"findImplementedFunctions": gbase.FindImplementedFunctions,
		"toPackageElement":         toPackageElement,
		"toFields":                 toTsFields,
		"toArgs":                   toArgs,
		"computeImplementNames":    computeImplementNames,
		"createTsKlasse":           createTsKlasse,
		"createTsInterface":        createTsInterface,
		"removeNewLine":            gbase.RemoveNewLine,
		"createFunktionKontext":    gbase.CreateFunktionKontext,
		"variableName":             gbase.VariableName,
		"variableType":             variableType,
		"toConstructor":            gbase.ToConstructor,
		"valueInit":                valueInit,
		"variableDefaultValue":     variableDefaultValue,
		"isNotVoid":                gbase.IsNotVoid,
	}
	must := template.Must(template.New("").Funcs(funcMap).ParseFS(tmplFiles, "template/*"))
	return TsTemplate{template: must}
}

func (receiver TsTemplate) GenerateStruct(writer io.Writer, element *packages.StructElement) error {
	println("Generate Struct: " + element.Path.ToString())
	return receiver.template.ExecuteTemplate(writer, "classFile", element)
}

func (receiver TsTemplate) GenerateEntity(writer io.Writer, element *packages.EntityElement) error {
	println("Generate Entity: " + element.Path.ToString())
	return receiver.template.ExecuteTemplate(writer, "classFile", element)
}

func (receiver TsTemplate) GenerateEnum(writer io.Writer, element *packages.EnumElement) error {
	println("Generate Enum: " + element.Path.ToString())
	return receiver.template.ExecuteTemplate(writer, "enumFile", element)
}

func (receiver TsTemplate) GenerateInterface(writer io.Writer, element *packages.InterfaceElement) error {
	println("Generate Interface: " + element.Path.ToString())
	return receiver.template.ExecuteTemplate(writer, "interfaceFile", element)
}

func (receiver TsTemplate) GenerateDelegate(writer io.Writer, element packages.PackageElement) error {

	var e packages.PackageElement
	delegate := gbase.CreateDelegate(element)
	//prepareDelegateFunktionen(delegate)
	e = delegate
	e.GetBase().Path = append([]string{"delegates"}, e.GetBase().Path...)
	println("Generate Delegate: " + e.GetBase().Path.ToString())
	return receiver.template.ExecuteTemplate(writer, "delegateFile", e)
}

func (receiver TsTemplate) GenerateDelegateInterface(writer io.Writer, element packages.PackageElement) error {
	panic("Typescript enthält keine Interfaces")
}

func (receiver TsTemplate) GenerateTable(writer io.Writer, table dmodel.Table) error {
	panic("Typescript kann keine Tabellen generieren")
}

func (receiver TsTemplate) GetOverrideAdapter() gbase.OverrideAdapter {
	panic("Typescript enthält keine Override Optionen")
}
