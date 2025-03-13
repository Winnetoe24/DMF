package database

import (
	"embed"
	"github.com/Winnetoe24/DMF/generator/gbase"
	"github.com/Winnetoe24/DMF/semantic/semantic-database/dmodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"io"
	"text/template"
)

//go:embed template/*
var tmplFiles embed.FS

type DbTemplate struct {
	template *template.Template
}

var _ gbase.DMFTemplate = DbTemplate{}

func NewTemplate() DbTemplate {
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
		"toUpperCase": gbase.ToUpperCase,
		"mapType":     mapType,
		"isNotEmpty": func(string2 string) bool {
			return string2 != ""
		},
		"findPrimaryKeys": findPrimaryKeys,
	}
	must := template.Must(template.New("").Funcs(funcMap).ParseFS(tmplFiles, "template/*"))
	return DbTemplate{template: must}
}
func (d DbTemplate) GenerateStruct(writer io.Writer, element *packages.StructElement) error {
	panic("Ist keine DB Struktur")
}

func (d DbTemplate) GenerateEntity(writer io.Writer, element *packages.EntityElement) error {
	panic("Ist keine DB Struktur")
}

func (d DbTemplate) GenerateEnum(writer io.Writer, element *packages.EnumElement) error {
	panic("Ist keine DB Struktur")
}

func (d DbTemplate) GenerateInterface(writer io.Writer, element *packages.InterfaceElement) error {
	panic("Ist keine DB Struktur")
}

func (d DbTemplate) GenerateDelegate(writer io.Writer, element packages.PackageElement) error {
	panic("Ist keine DB Struktur")
}

func (d DbTemplate) GenerateDelegateInterface(writer io.Writer, element packages.PackageElement) error {
	panic("Ist keine DB Struktur")
}

func (d DbTemplate) GenerateTable(writer io.Writer, table dmodel.Table) error {
	println("Generate Table: " + table.Name)
	return d.template.ExecuteTemplate(writer, "table", table)
}
