package main

import (
	"bufio"
	"flag"
	"github.com/Winnetoe24/DMF/javaGenerator/javaGenBase"
	"github.com/Winnetoe24/DMF/semantic"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/packages"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"io"
	"os"
	"sync"
)

var template = javaGenBase.NewTemplate()
var operations = sync.WaitGroup{}

func main() {
	var basePath = flag.String("basePath", ".", "the base path where files are generated")
	var modelFile = flag.String("modelFile", "./test.dmf", "the model which is generated")
	flag.Parse()
	file, err := os.ReadFile(*modelFile)
	if err != nil {
		panic(err)
	}
	afterTree := make(chan *tree_sitter.Tree, 1)
	defer close(afterTree)
	afterModel := make(chan *smodel.Model, 1)
	defer close(afterModel)
	_, _, _, up := semantic.ParseNewFile(string(file), afterTree, afterModel)
	Generate(*basePath, up)
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
		case *packages.StructElement:
			go generateJavaFile(createFile(basePath, element.Path), apply(template.GenerateStruct, element))
		case *packages.InterfaceElement:
			go generateJavaFile(createFile(basePath, element.Path), apply(template.GenerateInterface, element))
		default:
			operations.Done()
		}
	}
}

func createFile(basePath string, path base.ModelPath) *os.File {
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
	create, err := os.Create(finalPath)
	if err != nil {
		panic(err)
	}

	return create
}

func apply[E any](f func(writer io.Writer, e E) error, data E) func(writer io.Writer) error {
	return func(writer io.Writer) error {
		return f(writer, data)
	}
}
func generateJavaFile(file *os.File, f func(writer io.Writer) error) {
	writer := bufio.NewWriter(file)
	err := f(writer)
	if err != nil {
		panic(err)
	}
	err = writer.Flush()
	if err != nil {
		panic(err)
	}
	operations.Done()
}
