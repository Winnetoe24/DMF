package args

import "flag"

var DisableLog bool
var UseStd bool
var CharacterInMarkdown bool

func init() 
func init() {
	disableLog := flag.Bool("disabledLog", false, "Disable logging")
	var useStd = flag.Bool("stdio", true, "useStdio for communication")
	var characterInMarkdown = flag.Bool("characterInMarkdownLinks", false, "activates MarkdownLinks where the Character is transmitted with the schema #L<line>.<character>")

	flag.Parse()

	DisableLog = *disableLog
	UseStd = *useStd
	CharacterInMarkdown = *characterInMarkdown
}
