package base

import dmf_lang "github.com/Winnetoe24/DMF/grammar/dmf_language"

type PackageElementType int

const (
	PACKAGE PackageElementType = iota
	STRUCT
	ENTITY
	ENUM
	INTERFACE
)

type PrimitivType string

const (
	INT      PrimitivType = dmf_lang.INT
	DOUBLE   PrimitivType = dmf_lang.DOUBLE
	LONG     PrimitivType = dmf_lang.LONG
	BYTE     PrimitivType = dmf_lang.BYTE
	DATETIME PrimitivType = dmf_lang.DATETIME
	DATE     PrimitivType = dmf_lang.DATE
	STRING   PrimitivType = dmf_lang.STRING
	BOOLEAN  PrimitivType = dmf_lang.BOOLEAN
)
