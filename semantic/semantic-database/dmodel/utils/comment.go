package utils

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"strings"
)

func ComputeComment(comment *base.Comment) string {
	if comment == nil {
		return ""
	}

	out := ""
	for _, s := range *comment {
		if out != "" {
			out += "\n"
		}
		if s == "" || s == "\n" {
			continue
		}
		out += s
		out = strings.TrimSuffix(out, "\n")
		out = strings.TrimSuffix(out, "\n")
	}
	return out
}
