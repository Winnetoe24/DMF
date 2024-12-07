package semantic_parse

import (
	tree_sitter_dmf "github.com/Winnetoe24/DMF/grammar/dmf_language"
	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	"os"
	"testing"
)

// 27546 ns  - Package Parse
// 34136 ns  - Start Struct Parse
// 48293 ns  - Funktion Parse
// 88255 ns  - Interface Parse
// 109233 ns  - Full Parse
// 96190 ns  - Full Parse mit assErt ohne Node Kind
//
//	101517 ns - Full Parse mit Bugfix for ModelPath (copy)
//
// 1581174 ns - Full Parse mit Bugfix for ModelPath (copy)
// 92380 ns - New Context Calling
// 91700 ns - Errors in Context
// 119418 ns - Error rendering after Parse
func BenchmarkParse(b *testing.B) {
	b.StopTimer()

	file, err := os.ReadFile("../example-file")
	if err != nil {
		return
	}
	text := string(file)

	language := tree_sitter.NewLanguage(tree_sitter_dmf.Language())
	parser := tree_sitter.NewParser()
	err = parser.SetLanguage(language)
	if err != nil {
		return
	}

	parse := parser.Parse(file, nil)

	b.Run("Parse", func(b *testing.B) {
		for i := 0; i < b.N; i++ {
			Parse([]byte(text), parse)
		}
	})
	//for i := 0; i < b.N; i++ {
	//	b.StartTimer()
	//
	//	b.StopTimer()
	//}
}

// 113953 ns  - Start Arg Parse
// 179460 ns  - Interface Parse
// 274759 ns  - Full Parse

func BenchmarkParseFull(b *testing.B) {
	b.StopTimer()

	file, err := os.ReadFile("../example-file")
	if err != nil {
		return
	}
	text := string(file)

	language := tree_sitter.NewLanguage(tree_sitter_dmf.Language())
	parser := tree_sitter.NewParser()
	err = parser.SetLanguage(language)
	if err != nil {
		return
	}

	for i := 0; i < b.N; i++ {
		b.StartTimer()
		parse := parser.Parse(file, nil)
		Parse([]byte(text), parse)
		b.StopTimer()
	}
}
