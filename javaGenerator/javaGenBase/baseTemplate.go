package javaGenBase

import (
	"embed"
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

type FieldData struct {
	Typ       string
	Name      string
	Kommentar *base.Comment
}
type VariableKontext struct {
	Variable      packages.Variable
	ImportKontext ImportKontext
}
type KonstruktorData struct {
	Name          string
	Parameter     []VariableKontext
	ImportKontext ImportKontext
}

type ImportLookUp map[string]Import
type ImportKontext struct {
	ImportLookUp ImportLookUp
	Path         base.ModelPath
}
type Import struct {
	OriginalName base.ModelPath
}

type VererbungKontext struct {
	ImportKontext   ImportKontext
	ExtendsPath     *base.ModelPath
	ImplementsPaths []base.ModelPath
}

// ParameterKontext kann genauso wie KonstruktorData für die Parameter genutzt werden
type ParameterKontext struct {
	Parameter     []VariableKontext
	ImportKontext ImportKontext
}
type FunktionKontext struct {
	Funktion      packages.Funktion
	ImportKontext ImportKontext
}

func NewTemplate() JavaTemplate {
	funcMap := template.FuncMap{
		"subtract": func(a, b int) int {
			return a - b
		},
		"nameFromPath": func(path base.ModelPath) string {
			return path[len(path)-1]
		},
		"packagePath":              packagePath,
		"toFields":                 toFields,
		"toArgs":                   toArgs,
		"variableName":             variableName,
		"variableType":             variableType,
		"removeNewLine":            removeNewLine,
		"variableDefaultValue":     variableDefaultValue,
		"toConstructor":            toConstructor,
		"toUpperCase":              toUpperCase,
		"valueInit":                valueInit,
		"createImportKontext":      createImportKontext,
		"getImports":               getImports,
		"getImportedName":          getImportedName,
		"createFunktionKontext":    createFunktionKontext,
		"createParameterKontext":   createParameterKontext,
		"pathType":                 pathType,
		"createVererbungKontext":   createVererbungKontext,
		"findImplementedFunctions": findImplementedFunctions,
		"generateIdentifier":       generateIdentifier,
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
	return receiver.template.ExecuteTemplate(writer, "enum", element)
}

func (receiver JavaTemplate) GenerateInterface(writer io.Writer, element *packages.InterfaceElement) error {
	return receiver.template.ExecuteTemplate(writer, "interface", element)
}

func (receiver JavaTemplate) GenerateDelegate(writer io.Writer, element packages.PackageElement) error {
	var e packages.PackageElement
	delegate := CreateDelegate(element)
	e = delegate
	println("Generate Delegate: " + delegate.Path.ToString())
	return receiver.template.ExecuteTemplate(writer, "delegate", e)
}
