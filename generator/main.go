package main

import (
	"bufio"
	"errors"
	"flag"
	"fmt"
	"github.com/Winnetoe24/DMF/generator/database"
	"github.com/Winnetoe24/DMF/generator/gbase"
	"github.com/Winnetoe24/DMF/generator/javaGenBase"
	"github.com/Winnetoe24/DMF/generator/typescript"
	"github.com/Winnetoe24/DMF/semantic"
	semantic_database "github.com/Winnetoe24/DMF/semantic/semantic-database"
	"github.com/Winnetoe24/DMF/semantic/semantic-database/dmodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	err_element "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	"io"
	"os"
	"path/filepath"
	"slices"
	"sync"
)

var template gbase.DMFTemplate
var operations = sync.WaitGroup{}
var generationMode = NotSet

type GenerationMode string

const (
	NotSet              GenerationMode = "notSet"
	Java                GenerationMode = "java"
	JavaDelegates       GenerationMode = "javaDelegates"
	Typescript          GenerationMode = "ts"
	TypescriptDelegates GenerationMode = "tsDelegates"
	Database            GenerationMode = "database"
)

func main() {
	var basePath = flag.String("basePath", ".", "the path where files are generated")
	var modelFile = flag.String("modelFile", "./test.dmf", "the model which is generated")
	var mode = flag.String("mode", string(NotSet), "the generation mode, choose from: java, javaDelegates, ts, tsDelegates, database")
	flag.Parse()
	if mode == nil || *mode == string(NotSet) {
		fmt.Println("A generation mode is required.")
		os.Exit(1)
	}
	generationMode = GenerationMode(*mode)
	file, err := os.ReadFile(*modelFile)
	if err != nil {
		panic(err)
	}

	abs, err := filepath.Abs(*modelFile)
	if err != nil {
		panic(err)
	}
	errorElements, _, _, _, _, up := semantic.ParseNewFile(string(file), loadFile, []string{abs})
	context := err_element.ErrorContext{
		Dateiname:   *modelFile,
		Dateiinhalt: file,
	}
	for _, errElement := range errorElements {
		println(errElement.ToErrorMsg(&context))
	}
	if errorElements != nil && len(errorElements) > 0 {
		return
	}
	var schema dmodel.Schema
	if generationMode == Database {
		schema, errorElements = semantic_database.GenerateSchemaNew(up)
		for _, errElement := range errorElements {
			println(errElement.ToErrorMsg(&context))
		}
	}
	if errorElements != nil && len(errorElements) > 0 {
		return
	}

	fmt.Printf("Generiere %v Elemente\n", len(up.GetTypeLookUp()))
	switch generationMode {
	case Java:
		template = javaGenBase.NewTemplate()
		GenerateJava(*basePath, up)
	case JavaDelegates:
		template = javaGenBase.NewTemplate()
		GenerateJavaDelegates(*basePath, up)
	case Typescript:
		template = typescript.NewTemplate()
		GenerateTs(*basePath, up)
	case TypescriptDelegates:
		template = typescript.NewTemplate()
		GenerateTsDelegates(*basePath, up)
	case Database:
		template = database.NewTemplate()
		GenerateDatabase(*basePath, schema)
	}
	operations.Wait()
}

func loadFile(absPath string, usedFiles []string) (smodel.TypeLookUp, error) {
	file, err := os.ReadFile(absPath)
	if err != nil {
		return nil, err
	}
	newUsedFiles := append(append([]string{}, usedFiles...), absPath)
	context := err_element.ErrorContext{
		Dateiname:   absPath,
		Dateiinhalt: file,
	}
	errorElements, _, err, _, _, up := semantic.ParseNewFile(string(file), loadFile, newUsedFiles)
	if err != nil {
		return nil, err
	}
	if errorElements != nil && len(errorElements) > 0 {
		for _, element := range errorElements {
			println(element.ToErrorMsg(&context))
		}
		os.Exit(1)
	}
	return up, nil
}

func GenerateJava(basePath string, lookup smodel.TypeLookUp) {
	for _, pElement := range lookup {
		operations.Add(1)

		switch element := pElement.(type) {
		case *packages.EnumElement:
			go generateFile(createFile(basePath, element.Path, element.Override, buildJavaPath), apply(template.GenerateEnum, element))
		case *packages.EntityElement:
			go generateFile(createFile(basePath, element.Path, element.Override, buildJavaPath), apply(template.GenerateEntity, element))
		case *packages.StructElement:
			go generateFile(createFile(basePath, element.Path, element.Override, buildJavaPath), apply(template.GenerateStruct, element))
		case *packages.InterfaceElement:
			go generateFile(createFile(basePath, element.Path, element.Override, buildJavaPath), apply(template.GenerateInterface, element))
		default:
			operations.Done()
		}
	}
}

func GenerateJavaDelegates(basePath string, lookup smodel.TypeLookUp) {
	for _, pElement := range lookup {
		operations.Add(1)

		switch element := pElement.(type) {
		case *packages.EntityElement:
			go generateFile(createFileIfNotExists(basePath, gbase.CreateDelegatePath(slices.Clone(element.Path)), element.Override, buildJavaPath), apply(template.GenerateDelegate, pElement))
		case *packages.StructElement:
			go generateFile(createFileIfNotExists(basePath, gbase.CreateDelegatePath(slices.Clone(element.Path)), element.Override, buildJavaPath), apply(template.GenerateDelegate, pElement))
		default:
			operations.Done()
		}
	}
}

func GenerateTs(basePath string, lookup smodel.TypeLookUp) {
	for _, pElement := range lookup {
		operations.Add(1)

		switch element := pElement.(type) {
		case *packages.EnumElement:
			go generateFile(createFile(basePath, element.Path, element.Override, buildTsPath), apply(template.GenerateEnum, element))
		case *packages.EntityElement:
			go generateFile(createFile(basePath, element.Path, element.Override, buildTsPath), apply(template.GenerateEntity, element))
		case *packages.StructElement:
			go generateFile(createFile(basePath, element.Path, element.Override, buildTsPath), apply(template.GenerateStruct, element))
		case *packages.InterfaceElement:
			go generateFile(createFile(basePath, element.Path, element.Override, buildTsPath), apply(template.GenerateInterface, element))
		default:
			operations.Done()
		}
	}
}

func GenerateTsDelegates(basePath string, lookup smodel.TypeLookUp) {
	for _, pElement := range lookup {
		operations.Add(1)

		switch element := pElement.(type) {
		case *packages.EntityElement:
			go generateFile(createFileIfNotExists(basePath, gbase.CreateDelegatePath(append([]string{"delegates"}, slices.Clone(element.Path)...)), element.Override, buildTsPath), apply(template.GenerateDelegate, pElement))
		case *packages.StructElement:
			go generateFile(createFileIfNotExists(basePath, gbase.CreateDelegatePath(append([]string{"delegates"}, slices.Clone(element.Path)...)), element.Override, buildTsPath), apply(template.GenerateDelegate, pElement))
		default:
			operations.Done()
		}
	}
}

func GenerateDatabase(basePath string, schema dmodel.Schema) {
	file := createFile(basePath, base.ModelPath{}, nil, buildDbPath)

	extraTables := make(map[string]*dmodel.Table)
	for _, tabellenName := range schema.FileOrdner {
		tabelle := schema.TableLookUp[tabellenName]
		if tabelle == nil {
			panic("table for name " + tabellenName + " not found")
		}
		operations.Add(1)
		generateFile(file, apply(template.GenerateTable, *tabelle))
		for _, tableReference := range (*tabelle).TablesForElements {
			if tableReference.IsExtra {
				extraTables[tableReference.Name] = tableReference.Table
				continue
			}
			operations.Add(1)
			generateFile(file, apply(template.GenerateTable, *tableReference.Table))
		}
	}
	for _, tabelle := range extraTables {
		operations.Add(1)
		generateFile(file, apply(template.GenerateTable, *tabelle))
	}
}

func createFileIfNotExists(basePath string, path base.ModelPath, override *base.Override, buildPath func(string, base.ModelPath, *base.Override) string) *os.File {
	finalPath := buildPath(basePath, path, override)
	if _, err := os.Stat(finalPath); err == nil {
		return nil
	} else {
		create, err := os.Create(finalPath)
		if err != nil {
			panic(err)
		}

		return create
	}
}

func createFile(basePath string, path base.ModelPath, override *base.Override, buildPath func(string, base.ModelPath, *base.Override) string) *os.File {
	finalPath := buildPath(basePath, path, override)
	create, err := os.Create(finalPath)
	if err != nil {
		panic(err)
	}

	return create
}

func buildJavaPath(basePath string, path base.ModelPath, override *base.Override) string {
	finalPath := basePath

	for i, s := range path {
		if override != nil && i == len(path)-1 {
			if class := template.GetOverrideAdapter().GetClass(override); class != nil {
				finalPath = finalPath + string(os.PathSeparator) + *class
				if generationMode == JavaDelegates {
					finalPath = finalPath + "Delegate"
				}
			} else {
				finalPath = finalPath + string(os.PathSeparator) + s
			}
		} else {
			finalPath = finalPath + string(os.PathSeparator) + s
		}

		if i == len(path)-1 {
			finalPath += ".java"
			break
		}
		err := os.MkdirAll(finalPath, 0750)
		if err != nil {
			panic(err)
		}
	}
	return finalPath
}
func buildTsPath(basePath string, path base.ModelPath, _ *base.Override) string {
	finalPath := basePath
	for i, s := range path {
		finalPath = finalPath + string(os.PathSeparator) + s
		if i == len(path)-1 {
			finalPath += ".ts"
			break
		}
		err := os.MkdirAll(finalPath, 0750)
		if err != nil {
			panic(err)
		}
	}
	return finalPath
}
func buildDbPath(basePath string, path base.ModelPath, _ *base.Override) string {
	return basePath + string(os.PathSeparator) + "schema.ddl"
}

func apply[E any](f func(writer io.Writer, e E) error, data E) func(writer io.Writer) error {
	return func(writer io.Writer) error {
		return f(writer, data)
	}
}
func generateFile(file *os.File, f func(writer io.Writer) error) {
	if file != nil {
		writer := bufio.NewWriter(file)
		err := f(writer)
		if err != nil {
			panic(errors.Join(err, errors.New(file.Name())))
		}
		err = writer.Flush()
		if err != nil {
			panic(err)
		}
	}
	operations.Done()
}
