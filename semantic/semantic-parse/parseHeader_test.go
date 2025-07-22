package semantic_parse

import (
	dmf_lang "github.com/Winnetoe24/DMF/grammar/dmf_language"
	"github.com/Winnetoe24/DMF/semantic/data"
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/builder"
	parse_old "github.com/Winnetoe24/DMF/semantic/semantic-parse/parse_util"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"reflect"
	"slices"
	"testing"
)

func TestParser_parseDMF(t *testing.T) {
	type fields struct {
		context           parse_old.ParseContext
		currentPreBuilder *builder.PreBuilder
		currentBuilder    builder.Builder
		builders          *data.Stack[builder.Builder]
	}

	createFields := func(text string) fields {
		language := tree_sitter.NewLanguage(dmf_lang.Language())
		if language == nil {
			t.Errorf("language is nil")
			return fields{}
		}

		parser := tree_sitter.NewParser()
		err := parser.SetLanguage(language)
		if err != nil {
			t.Error(err)
			return fields{}
		}
		tree := parser.Parse([]byte(text), nil)
		walk := tree.Walk()
		walk.GotoFirstChild()
		return fields{
			context: parse_old.ParseContext{
				ErrorElements: nil,
				Text:          []byte(text),
				Cursor:        walk,
				ParseFile:     nil,
				ImportLookUp:  nil,
				UsedFiles:     nil,
			},
			currentPreBuilder: nil,
			currentBuilder:    &builder.ModelBuilder{},
			builders:          nil,
		}
	}
	tests := []struct {
		name      string
		fields    fields
		wantErr   bool
		validator func(result fields)
	}{
		{
			"success test",
			createFields("dmf 2.0.0\nmodel \"smart_city_management\" version 1.0.0"),
			false,
			func(result fields) {
				if slices.Compare(result.currentBuilder.(*builder.ModelBuilder).DMFVersion, []int32{2, 0, 0}) != 0 {
					t.Fail()
				}
			},
		},
		{
			"wrong Version test",
			createFields("dmf 1.0.0\nmodel \"smart_city_management\" version 1.0.0"),
			true,
			func(result fields) {
				if len(result.context.ErrorElements) == 0 {
					t.Fail()
				}
			},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			p := &Parser{
				context:           tt.fields.context,
				currentPreBuilder: tt.fields.currentPreBuilder,
				currentBuilder:    tt.fields.currentBuilder,
				builders:          tt.fields.builders,
			}
			if err := p.parseDMF(); (err != nil) != tt.wantErr {
				t.Errorf("parseDMF() error = %v, wantErr %v, context: %+v", err, tt.wantErr, tt)
			}
		})
	}
}

func TestParser_parseModel(t *testing.T) {
	type fields struct {
		context           parse_old.ParseContext
		currentPreBuilder *builder.PreBuilder
		currentBuilder    builder.Builder
		builders          *data.Stack[builder.Builder]
	}
	createFields := func(text string) fields {
		language := tree_sitter.NewLanguage(dmf_lang.Language())
		if language == nil {
			t.Errorf("language is nil")
			return fields{}
		}

		parser := tree_sitter.NewParser()
		err := parser.SetLanguage(language)
		if err != nil {
			t.Error(err)
			return fields{}
		}
		tree := parser.Parse([]byte(text), nil)
		walk := tree.Walk()
		walk.GotoFirstChild()
		walk.GotoNextSibling()
		return fields{
			context: parse_old.ParseContext{
				ErrorElements: nil,
				Text:          []byte(text),
				Cursor:        walk,
				ParseFile:     nil,
				ImportLookUp:  nil,
				UsedFiles:     nil,
			},
			currentPreBuilder: nil,
			currentBuilder:    &builder.ModelBuilder{},
			builders:          nil,
		}
	}
	tests := []struct {
		name      string
		fields    fields
		wantErr   bool
		validator func(result fields)
	}{
		{
			"success",
			createFields("dmf 2.0.0\nmodel \"smart_city_management\" version 1.0.0"),
			false,
			func(result fields) {
				modelBuilder := result.currentBuilder.(*builder.ModelBuilder)
				if !reflect.DeepEqual(modelBuilder.ModelVersion, []int32{1, 0, 0}) {
					t.Errorf("wrong model version: %v", modelBuilder.ModelVersion)
				}

				if modelBuilder.ModelName.Value != "smart_city_management" {
					t.Errorf("wrong model name: %v", modelBuilder.ModelName)
				}
			},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			p := &Parser{
				context:           tt.fields.context,
				currentPreBuilder: tt.fields.currentPreBuilder,
				currentBuilder:    tt.fields.currentBuilder,
				builders:          tt.fields.builders,
			}
			if err := p.parseModel(); (err != nil) != tt.wantErr {
				t.Errorf("parseModel() error = %v, wantErr %v", err, tt.wantErr)
			}
			tt.validator(tt.fields)
		})
	}
}

func TestParser_parseVersion(t *testing.T) {
	type fields struct {
		context           parse_old.ParseContext
		currentPreBuilder *builder.PreBuilder
		currentBuilder    builder.Builder
		builders          *data.Stack[builder.Builder]
	}

	createFields := func(text string) fields {
		language := tree_sitter.NewLanguage(dmf_lang.Language())
		if language == nil {
			t.Errorf("language is nil")
			return fields{}
		}

		parser := tree_sitter.NewParser()
		err := parser.SetLanguage(language)
		if err != nil {
			t.Error(err)
			return fields{}
		}
		tree := parser.Parse([]byte(text), nil)
		walk := tree.Walk()
		walk.GotoFirstChild()
		walk.GotoFirstChild()
		walk.GotoNextSibling()
		return fields{
			context: parse_old.ParseContext{
				ErrorElements: nil,
				Text:          []byte(text),
				Cursor:        walk,
				ParseFile:     nil,
				ImportLookUp:  nil,
				UsedFiles:     nil,
			},
			currentPreBuilder: nil,
			currentBuilder:    &builder.ModelBuilder{},
			builders:          nil,
		}
	}
	tests := []struct {
		name    string
		fields  fields
		want    []int32
		wantErr bool
	}{
		{
			"success",
			createFields("dmf 1.0.0\n"),
			[]int32{1, 0, 0},
			false,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			p := &Parser{
				context:           tt.fields.context,
				currentPreBuilder: tt.fields.currentPreBuilder,
				currentBuilder:    tt.fields.currentBuilder,
				builders:          tt.fields.builders,
			}
			got, err := p.parseVersion()
			if (err != nil) != tt.wantErr {
				t.Errorf("parseVersion() error = %v, wantErr %v", err, tt.wantErr)
				return
			}
			if !reflect.DeepEqual(got, tt.want) {
				t.Errorf("parseVersion() got = %v, want %v", got, tt.want)
			}
		})
	}
}
