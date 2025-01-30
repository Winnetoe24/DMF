package packages

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"testing"
)

func TestPackage_CleanTreeReferences(t *testing.T) {
	e := &EntityElement{
		StructElement: StructElement{},
		EntityIdentifier: EntityIdentifier{
			ModelElement: base.ModelElement{
				Kommentar: nil,
				Node:      &tree_sitter.Node{},
			},
			Variablen: nil,
		},
	}
	enum := &EnumElement{
		PackageElement: base.PackageElement{
			ModelElement: base.ModelElement{
				Kommentar: nil,
				Node:      &tree_sitter.Node{},
			},
			Path: nil,
			Identifier: base.ElementIdentifier{
				ModelElement: base.ModelElement{
					Kommentar: nil,
					Node:      &tree_sitter.Node{},
				},
				Name: "",
			},
			NamedElements: nil,
			Expand:        false,
		},
		Argumente: nil,
		Konstanten: []Konstante{
			{
				ModelElement: base.ModelElement{
					Kommentar: nil,
					Node:      &tree_sitter.Node{},
				},
				Name: base.ElementIdentifier{
					ModelElement: base.ModelElement{
						Kommentar: nil,
						Node:      &tree_sitter.Node{},
					},
					Name: "",
				},
				Values: nil,
			},
		},
	}
	p := Package{
		PackageElement: base.PackageElement{
			ModelElement: base.ModelElement{
				Kommentar: nil,
				Node:      &tree_sitter.Node{},
			},
			Path: nil,
			Identifier: base.ElementIdentifier{
				ModelElement: base.ModelElement{
					Kommentar: nil,
					Node:      &tree_sitter.Node{},
				},
				Name: "",
			},
			NamedElements: nil,
			Expand:        false,
		},
		Elements: []PackageElement{e, enum},
	}
	if p.Node == nil {
		t.Error("p.Node is nil")
	}
	p.CleanTreeReferences()
	if p.Node != nil {
		t.Error("p.Node should be nil")
	}
	if e.EntityIdentifier.Node != nil {
		t.Error("e.EntityIdentifier.Node should be nil")
	}
	if enum.Identifier.Node != nil {
		t.Error("enum.Identifier.Node should be nil")
	}
	if enum.Konstanten[0].Node != nil {
		t.Error("enum.Konstanten[0].Node should be nil")
	}

}
