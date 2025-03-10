package args

import (
	"flag"
	"strconv"
)

var DisableLog bool
var UseStd bool
var Port string
var CharacterInMarkdown bool
var DisableSingleLineCommentsFolding bool

func ParseArgs() {
	disableLog := flag.Bool("disabledLog", false, "Disable logging")
	var port = flag.Int("port", -1, "switches communication to specified tcp port")
	var disableSingleLineCommentsFolding = flag.Bool("disableSingleLineCommentsFolding", false, "do not generate folding ranges for single line comments")
	var characterInMarkdown = flag.Bool("characterInMarkdownLinks", false, "activates MarkdownLinks where the Character is transmitted with the schema #L<line>.<character>")

	flag.Parse()

	DisableLog = *disableLog
	UseStd = port == nil || *port == -1
	if port != nil && *port != -1 {
		port := *port
		if port < 1024 || port > 49151 {
			panic("port must be between 1024 and 49151")
		}
		Port = ":" + strconv.Itoa(port)
	}
	CharacterInMarkdown = *characterInMarkdown
	DisableSingleLineCommentsFolding = *disableSingleLineCommentsFolding
}
