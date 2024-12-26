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
type KonstruktorData struct {
	Name      string
	Parameter []packages.Variable
}

func NewTemplate() JavaTemplate {
	funcMap := template.FuncMap{
		"subtract": func(a, b int) int {
			return a - b
		},
		"nameFromPath": func(path base.ModelPath) string {
			return path[len(path)-1]
		},
		"packagePath":          packagePath,
		"toFields":             toFields,
		"toArgs":               toArgs,
		"variableName":         variableName,
		"variableType":         variableType,
		"removeNewLine":        removeNewLine,
		"variableDefaultValue": variableDefaultValue,
		"toConstructor":        toConstructor,
		"toUpperCase":          toUpperCase,
		"valueInit":            valueInit,
	}
	must := template.Must(template.New("").Funcs(funcMap).ParseFS(tmplFiles, "template/*"))
	return JavaTemplate{template: must}
}

func (receiver JavaTemplate) GenerateStruct(writer io.Writer, element *packages.StructElement) error {
	println("Generate Struct: " + element.Path.ToString())
	return receiver.template.ExecuteTemplate(writer, "class", element)
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
