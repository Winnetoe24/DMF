package main

import (
	"bufio"
	"errors"
	"flag"
	"github.com/Winnetoe24/DMF/javaGenerator/javaGenBase"
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

var template = javaGenBase.NewTemplate()
var operations = sync.WaitGroup{}

func main() {
	var basePath = flag.String("basePath", ".", "the base path where files are generated")
	var modelFile = flag.String("modelFile", "./test.dmf", "the model which is generated")
	var genDelegates = flag.Bool("delegates", false, "generate only Delegates")
	flag.Parse()
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
	if genDelegates != nil && *genDelegates {
		GenerateDelegates(*basePath, up)
	} else {
		Generate(*basePath, up)
	}
	operations.Wait()
}

func Generate(basePath string, lookup smodel.TypeLookUp) {
	for _, pElement := range lookup {
		operations.Add(1)

		switch element := pElement.(type) {
		case *packages.EnumElement:
			go generateJavaFile(createFile(basePath, element.Path), apply(template.GenerateEnum, element))
		case *packages.EntityElement:
			go generateJavaFile(createFile(basePath, element.Path), apply(template.GenerateEntity, element))
			operations.Add(1)
			go generateJavaFile(createFile(basePath, javaGenBase.CreateDelegateInterfacePath(slices.Clone(element.Path))), apply(template.GenerateDelegateInterface, pElement))
		case *packages.StructElement:
			go generateJavaFile(createFile(basePath, element.Path), apply(template.GenerateStruct, element))
			operations.Add(1)
			go generateJavaFile(createFile(basePath, javaGenBase.CreateDelegateInterfacePath(slices.Clone(element.Path))), apply(template.GenerateDelegateInterface, pElement))
		case *packages.InterfaceElement:
			go generateJavaFile(createFile(basePath, element.Path), apply(template.GenerateInterface, element))
		default:
			operations.Done()
		}
	}
}

func GenerateDelegates(basePath string, lookup smodel.TypeLookUp) {
	for _, pElement := range lookup {
		operations.Add(1)

		switch element := pElement.(type) {
		case *packages.EntityElement:
			go generateJavaFile(createFileIfNotExists(basePath, javaGenBase.CreateDelegatePath(slices.Clone(element.Path))), apply(template.GenerateDelegate, pElement))
		case *packages.StructElement:
			go generateJavaFile(createFileIfNotExists(basePath, javaGenBase.CreateDelegatePath(slices.Clone(element.Path))), apply(template.GenerateDelegate, pElement))
		case *packages.InterfaceElement:
			go generateJavaFile(createFileIfNotExists(basePath, javaGenBase.CreateDelegatePath(slices.Clone(element.Path))), apply(template.GenerateDelegate, pElement))
		default:
			operations.Done()
		}
	}
}

func createFileIfNotExists(basePath string, path base.ModelPath) *os.File {
	finalPath := buildPath(basePath, path)
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

func createFile(basePath string, path base.ModelPath) *os.File {
	finalPath := buildPath(basePath, path)
	create, err := os.Create(finalPath)
	if err != nil {
		panic(err)
	}

	return create
}

func buildPath(basePath string, path base.ModelPath) string {
	finalPath := basePath
	for i, s := range path {
		finalPath = finalPath + string(os.PathSeparator) + s
		if i == len(path)-1 {
			finalPath += ".java"
			break
		}
		err := os.MkdirAll(finalPath, os.ModeDir)
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
func generateJavaFile(file *os.File, f func(writer io.Writer) error) {
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
