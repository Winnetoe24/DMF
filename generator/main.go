package main

import (
	"bufio"
	"errors"
	"flag"
	"fmt"
	"github.com/Winnetoe24/DMF/generator/gbase"
	"github.com/Winnetoe24/DMF/generator/javaGenBase"
	"github.com/Winnetoe24/DMF/generator/typescript"
	"github.com/Winnetoe24/DMF/semantic"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	err_element "github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/err-element"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"io"
	"os"
	"slices"
	"sync"
)

var template gbase.DMFTemplate
var operations = sync.WaitGroup{}

type GenerationMode string

const (
	NotSet              GenerationMode = "notSet"
	Java                GenerationMode = "java"
	JavaDelegates       GenerationMode = "javaDelegates"
	Typescript          GenerationMode = "ts"
	TypescriptDelegates GenerationMode = "tsDelegates"
)

func main() {
	var basePath = flag.String("basePath", ".", "the path where files are generated")
	var modelFile = flag.String("modelFile", "./test.dmf", "the model which is generated")
	var mode = flag.String("mode", string(NotSet), "the generation mode, choose from: java, javaDelegates, ts, tsDelegates")
	flag.Parse()
	if mode == nil || *mode == string(NotSet) {
		fmt.Println("A generation mode is required.")
		os.Exit(1)
	}
	file, err := os.ReadFile(*modelFile)
	if err != nil {
		panic(err)
	}
	afterTree := make(chan *tree_sitter.Tree, 1)
	defer close(afterTree)
	afterModel := make(chan *smodel.Model, 1)
	defer close(afterModel)
	errorElements, _, _, up := semantic.ParseNewFile(string(file), afterTree, afterModel)
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

	fmt.Printf("Generiere %v Elemente\n", len(up.GetTypeLookUp()))
	switch GenerationMode(*mode) {
	case Java:
		template = javaGenBase.NewTemplate()
		GenerateJava(*basePath, up)
	case JavaDelegates:
		template = javaGenBase.NewTemplate()
		GenerateJavaDelegates(*basePath, up)
	case Typescript:
		template = typescript.NewTemplate()
		GenerateTs(*basePath, up)
	}
	operations.Wait()
}

func GenerateJava(basePath string, lookup smodel.TypeLookUp) {
	for _, pElement := range lookup {
		operations.Add(1)

		switch element := pElement.(type) {
		case *packages.EnumElement:
			go generateFile(createFile(basePath, element.Path, buildJavaPath), apply(template.GenerateEnum, element))
		case *packages.EntityElement:
			go generateFile(createFile(basePath, element.Path, buildJavaPath), apply(template.GenerateEntity, element))
		case *packages.StructElement:
			go generateFile(createFile(basePath, element.Path, buildJavaPath), apply(template.GenerateStruct, element))
		case *packages.InterfaceElement:
			go generateFile(createFile(basePath, element.Path, buildJavaPath), apply(template.GenerateInterface, element))
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
			go generateFile(createFileIfNotExists(basePath, gbase.CreateDelegatePath(slices.Clone(element.Path))), apply(template.GenerateDelegate, pElement))
		case *packages.StructElement:
			go generateFile(createFileIfNotExists(basePath, gbase.CreateDelegatePath(slices.Clone(element.Path))), apply(template.GenerateDelegate, pElement))
		default:
			operations.Done()
		}
	}
}

func GenerateTs(basePath string, lookup smodel.TypeLookUp) {
	for _, pElement := range lookup {
		operations.Add(1)

		switch element := pElement.(type) {
		//case *packages.EnumElement:
		//	go generateFile(createFile(basePath, element.Path), apply(template.GenerateEnum, element))
		case *packages.EntityElement:
			go generateFile(createFile(basePath, element.Path, buildTsPath), apply(template.GenerateEntity, element))
		case *packages.StructElement:
			go generateFile(createFile(basePath, element.Path, buildTsPath), apply(template.GenerateStruct, element))
		//case *packages.InterfaceElement:
		//	go generateFile(createFile(basePath, element.Path), apply(template.GenerateInterface, element))
		default:
			operations.Done()
		}
	}
}

func createFileIfNotExists(basePath string, path base.ModelPath) *os.File {
	finalPath := buildJavaPath(basePath, path)
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

func createFile(basePath string, path base.ModelPath, buildPath func(string, base.ModelPath) string) *os.File {
	finalPath := buildPath(basePath, path)
	create, err := os.Create(finalPath)
	if err != nil {
		panic(err)
	}

	return create
}

func buildJavaPath(basePath string, path base.ModelPath) string {
	finalPath := basePath
	for i, s := range path {
		finalPath = finalPath + string(os.PathSeparator) + s
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
func buildTsPath(basePath string, path base.ModelPath) string {
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
