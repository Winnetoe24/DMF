package javaGenBase

import (
	"github.com/Winnetoe24/DMF/semantic/semantic-parse/smodel/base"
	"strings"
)

func overrideName(name string, override *base.Override) string {
	adapter := JavaOverrideAdapter{}
	if newName := adapter.GetName(override); newName != nil {
		return *newName
	}
	return name
}
func overrideType(typ string, override *base.Override) string {
	adapter := JavaOverrideAdapter{}
	if newType := adapter.GetType(override); newType != nil {
		return *newType
	}
	return typ
}
func overrideJavaDoc(comment *base.Comment, override *base.Override) *base.Comment {
	adapter := JavaOverrideAdapter{}
	if newComment := adapter.GetDoc(override); newComment != nil {
		return newComment
	}
	return comment
}

func overrideClassName(name string, override *base.Override) string {
	adapter := JavaOverrideAdapter{}
	if newName := adapter.GetClass(override); newName != nil {
		return *newName
	}
	return name
}

type JavaOverrideAdapter struct {
}

func (j JavaOverrideAdapter) GetDoc(override *base.Override) *base.Comment {
	if override == nil || override.JavaOverride == nil || override.JavaOverride.JavaDoc == nil {
		return nil
	}
	split := strings.Split(override.JavaOverride.JavaDoc.Value, "\\n")
	for i := range split {
		split[i] = strings.TrimSpace(split[i]) + "\n\n"
	}
	comment := base.Comment(split)
	return &comment
}

func (j JavaOverrideAdapter) GetExtends(override *base.Override) *string {
	if override == nil || override.JavaOverride == nil || override.JavaOverride.Extends == nil {
		return nil
	}
	return &override.JavaOverride.Extends.Value
}

func (j JavaOverrideAdapter) GetImplements(override *base.Override) *string {
	if override == nil || override.JavaOverride == nil || override.JavaOverride.Implements == nil {
		return nil
	}
	return &override.JavaOverride.Implements.Value
}

func (j JavaOverrideAdapter) GetClass(override *base.Override) *string {
	if override == nil || override.JavaOverride == nil || override.JavaOverride.Class == nil {
		return nil
	}
	return &override.JavaOverride.Class.Value
}

func (j JavaOverrideAdapter) GetName(override *base.Override) *string {
	if override == nil || override.JavaOverride == nil || override.JavaOverride.Name == nil {
		return nil
	}
	return &override.JavaOverride.Name.Value
}

func (j JavaOverrideAdapter) GetType(override *base.Override) *string {
	if override == nil || override.JavaOverride == nil || override.JavaOverride.Type == nil {
		return nil
	}
	return &override.JavaOverride.Type.Value
}
