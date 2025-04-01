package javaGenBase

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

type JavaTemplate struct {
	template *template.Template
}

var _ gbase.DMFTemplate = JavaTemplate{}

func NewTemplate() JavaTemplate {
	funcMap := template.FuncMap{
		"subtract": func(a, b int) int {
			return a - b
		},
		"nameFromPath": func(path base.ModelPath) string {
			return path[len(path)-1]
		},
		"packagePath":                     gbase.PackagePath,
		"toFields":                        toJavaFields,
		"toArgs":                          toArgs,
		"variableName":                    gbase.VariableName,
		"variableType":                    variableType,
		"removeNewLine":                   gbase.RemoveNewLine,
		"capitalize":                      gbase.Capitalize,
		"variableDefaultValue":            variableDefaultValue,
		"toConstructor":                   gbase.ToConstructor,
		"toUpperCase":                     gbase.ToUpperCase,
		"valueInit":                       valueInit,
		"createImportKontext":             createJavaImportKontext,
		"getImports":                      getImports,
		"getImportedName":                 getImportedName,
		"createFunktionKontext":           gbase.CreateFunktionKontext,
		"createFunktionKontextDelegate":   createFunktionKontextDelegate,
		"prependThis":                     prependThis,
		"createParameterKontext":          createParameterKontext,
		"pathType":                        gbase.PathType,
		"createVererbungKontext":          createVererbungKontext,
		"createVererbungKontextInterface": createVererbungKontextInterface,
		"findImplementedFunctions":        gbase.FindImplementedFunctions,
		"generateIdentifier":              generateIdentifier,
		"isNotVoid":                       gbase.IsNotVoid,
		"overrideClassName":               overrideClassName,
		"overrideJavaDoc":                 overrideJavaDoc,
		"overrideType":                    overrideType,
		"overrideName":                    overrideName,
		"overrideExtends":                 JavaOverrideAdapter{}.GetExtends,
		"overrideImplements":              JavaOverrideAdapter{}.GetImplements,
	}
	must := template.Must(template.New("").Funcs(funcMap).ParseFS(tmplFiles, "template/*"))
	return JavaTemplate{template: must}
}

func (receiver JavaTemplate) GenerateStruct(writer io.Writer, element *packages.StructElement) error {
	println("Generate Struct: " + element.Path.ToString())
	return receiver.template.ExecuteTemplate(writer, "entity", element)
}

func (receiver JavaTemplate) GenerateEntity(writer io.Writer, element *packages.EntityElement) error {
	println("Generate Entity: " + element.Path.ToString())
	return receiver.template.ExecuteTemplate(writer, "entity", element)
}

func (receiver JavaTemplate) GenerateEnum(writer io.Writer, element *packages.EnumElement) error {
	println("Generate Enum: " + element.Path.ToString())
	return receiver.template.ExecuteTemplate(writer, "enum", element)
}

func (receiver JavaTemplate) GenerateInterface(writer io.Writer, element *packages.InterfaceElement) error {
	println("Generate Interface: " + element.Path.ToString())
	return receiver.template.ExecuteTemplate(writer, "interface", element)
}

func (receiver JavaTemplate) GenerateDelegate(writer io.Writer, element packages.PackageElement) error {
	var e packages.PackageElement
	delegate := gbase.CreateDelegate(element)
	e = delegate
	println("Generate Delegate: " + delegate.Path.ToString())
	return receiver.template.ExecuteTemplate(writer, "delegate", e)
}

func (receiver JavaTemplate) GenerateDelegateInterface(writer io.Writer, element packages.PackageElement) error {
	var e packages.PackageElement
	delegate := gbase.CreateDelegate(element)
	if delegate == nil {
		println("No Delegate found")
		return nil
	}
	e = delegate
	println("Generate Delegate Interface: " + delegate.Path.ToString())
	return receiver.template.ExecuteTemplate(writer, "delegateInterface", e)
}

func (receiver JavaTemplate) GenerateTable(writer io.Writer, table dmodel.Table) error {
	panic("Java kann keine Tabellen generieren")
}

func (receiver JavaTemplate) GetOverrideAdapter() gbase.OverrideAdapter {
	return JavaOverrideAdapter{}
}
