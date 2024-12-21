package fileService

import (
	"github.com/Winnetoe24/DMF/lsp/protokoll"
	"github.com/Winnetoe24/DMF/lsp/protokoll/textEdit"
	"strings"
	"testing"
)

func TestDMFSchemaEdits(t *testing.T) {
	initialContent := `dmf 1.0.0
model "modelname" version 0.0.1

// import de.alex.lib from "lib.dmf" (model "lib")

// iadsasaj asdiniasd
// oasdjiasd
expand package de.alex.brand {


    // asd
    package other {

        //Tets
        expand struct Test extends ..Bla implements ..Blo, Blup {
            // integer
            arg int i;
            arg date beispieldate;
            func boolean hi(boolean param, o objekt);

        }

        enum Ort {
            arg int i;
            arg boolean b;
            arg string s;
            arg date d;
            arg datetime dt;
            arg long l;

            VOR_HAUS(_, 1, true, 'd', D2012-12-12, D2012-01-01T00:00:00, 123L);
        }

        //Kommentar über Entität Person
        entity Person {
            ref ..Ort o;
            arg date beispieldate;
            arg int me;

            identifier(i, me);
        }

        //Kommentar über Interface
        interface Inte implements Blo, Blup {
            //Kommentar über Funktion
            func void hi(boolean param, o objekt);
        }

    }
}`

	tests := []struct {
		name           string
		initialVersion int32
		changes        textEdit.DidChangeTextDocumentParams
		want           InputEditResult
		wantError      bool
	}{
		{
			name:           "add new enum value",
			initialVersion: 1,
			changes: textEdit.DidChangeTextDocumentParams{
				TextDocument: protokoll.VersionedTextDocumentIdentifier{Version: 2},
				ContentChanges: []textEdit.TextDocumentContentChangeEvent{
					{
						Range: &protokoll.Range{
							Start: protokoll.Position{Line: 30, Character: 79},
							End:   protokoll.Position{Line: 30, Character: 79},
						},
						Text: "\n            HINTER_HAUS(_, 2, false, 'h', D2012-12-13, D2012-01-02T00:00:00, 124L);",
					},
				},
			},
			want: InputEditResult{
				NewContent: `dmf 1.0.0
model "modelname" version 0.0.1

// import de.alex.lib from "lib.dmf" (model "lib")

// iadsasaj asdiniasd
// oasdjiasd
expand package de.alex.brand {


    // asd
    package other {

        //Tets
        expand struct Test extends ..Bla implements ..Blo, Blup {
            // integer
            arg int i;
            arg date beispieldate;
            func boolean hi(boolean param, o objekt);

        }

        enum Ort {
            arg int i;
            arg boolean b;
            arg string s;
            arg date d;
            arg datetime dt;
            arg long l;

            VOR_HAUS(_, 1, true, 'd', D2012-12-12, D2012-01-01T00:00:00, 123L);
            HINTER_HAUS(_, 2, false, 'h', D2012-12-13, D2012-01-02T00:00:00, 124L);
        }

        //Kommentar über Entität Person
        entity Person {
            ref ..Ort o;
            arg date beispieldate;
            arg int me;

            identifier(i, me);
        }

        //Kommentar über Interface
        interface Inte implements Blo, Blup {
            //Kommentar über Funktion
            func void hi(boolean param, o objekt);
        }

    }
}`,
			},
		},
		{
			name:           "modify entity identifier",
			initialVersion: 1,
			changes: textEdit.DidChangeTextDocumentParams{
				TextDocument: protokoll.VersionedTextDocumentIdentifier{Version: 2},
				ContentChanges: []textEdit.TextDocumentContentChangeEvent{
					{
						Range: &protokoll.Range{
							Start: protokoll.Position{Line: 39, Character: 23},
							End:   protokoll.Position{Line: 39, Character: 28},
						},
						Text: "i, me, o",
					},
				},
			},
			want: InputEditResult{
				NewContent: initialContent[:strings.Index(initialContent, "i, me")] + "i, me, o" + initialContent[strings.Index(initialContent, "i, me")+5:],
			},
		},
		{
			name:           "add new argument to struct",
			initialVersion: 1,
			changes: textEdit.DidChangeTextDocumentParams{
				TextDocument: protokoll.VersionedTextDocumentIdentifier{Version: 2},
				ContentChanges: []textEdit.TextDocumentContentChangeEvent{
					{
						Range: &protokoll.Range{
							Start: protokoll.Position{Line: 18, Character: 0},
							End:   protokoll.Position{Line: 18, Character: 0},
						},
						Text: "            arg string name;\n",
					},
				},
			},
			want: InputEditResult{
				NewContent: strings.Replace(
					initialContent,
					"            func boolean",
					"            arg string name;\n            func boolean",
					1,
				),
			},
		},
		{
			name:           "change model version",
			initialVersion: 1,
			changes: textEdit.DidChangeTextDocumentParams{
				TextDocument: protokoll.VersionedTextDocumentIdentifier{Version: 2},
				ContentChanges: []textEdit.TextDocumentContentChangeEvent{
					{
						Range: &protokoll.Range{
							Start: protokoll.Position{Line: 1, Character: 26},
							End:   protokoll.Position{Line: 1, Character: 31},
						},
						Text: "0.0.2",
					},
				},
			},
			want: InputEditResult{
				NewContent: strings.Replace(initialContent, "0.0.1", "0.0.2", 1),
			},
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			doc := &fileHandle{
				FileContent: initialContent,
				Version:     tt.initialVersion,
			}

			got := doc.applyChanges(&tt.changes)

			if tt.wantError {
				if got.Error == nil {
					t.Error("expected error, got nil")
				}
				return
			}

			if got.Error != nil {
				t.Errorf("unexpected error: %v", got.Error)
				return
			}

			if got.NewContent != tt.want.NewContent {
				t.Errorf("\ngot content:\n%s\nwant content:\n%s", got.NewContent, tt.want.NewContent)
			}

			// Verify that the new content is still valid DMF schema
			if !isValidDMFSchema(got.NewContent) {
				t.Error("resulting content is not a valid DMF schema")
			}
		})
	}
}

// Helper function to validate DMF schema structure
func isValidDMFSchema(content string) bool {
	// Basic validation checks
	if !strings.HasPrefix(content, "dmf ") {
		return false
	}

	if !strings.Contains(content, "model") {
		return false
	}

	// Check for matching braces
	braceCount := 0
	for _, ch := range content {
		if ch == '{' {
			braceCount++
		} else if ch == '}' {
			braceCount--
			if braceCount < 0 {
				return false
			}
		}
	}
	return braceCount == 0
}
