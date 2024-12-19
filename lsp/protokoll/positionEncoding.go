package protokoll

import (
	"fmt"
	"unicode/utf16"
)

// PositionEncodingKind describes how positions are encoded
type PositionEncodingKind string

const (
	// PosUTF8 indicates positions are expressed as UTF-8 byte offsets
	// This is the standard encoding and default value
	PosUTF8 PositionEncodingKind = "utf-8"

	// PosUTF16 indicates positions are expressed as UTF-16 code unit offsets
	// This was historically used by some clients/servers
	PosUTF16 PositionEncodingKind = "utf-16"

	// PosUTF32 indicates positions are expressed as UTF-32 code unit offsets
	PosUTF32 PositionEncodingKind = "utf-32"
)

// IsValid checks if the position encoding is one of the known values
func (p PositionEncodingKind) IsValid() bool {
	switch p {
	case PosUTF8, PosUTF16, PosUTF32:
		return true
	default:
		return false
	}
}

// DefaultPositionEncoding returns the default position encoding (UTF-8)
func DefaultPositionEncoding() PositionEncodingKind {
	return PosUTF8
}

// Helper functions for position calculations based on encoding

// CountCodeUnits counts the number of code units in the given text based on the encoding
func CountCodeUnits(text string, encoding PositionEncodingKind) (int, error) {
	switch encoding {
	case PosUTF8:
		return len([]byte(text)), nil
	case PosUTF16:
		return len(utf16.Encode([]rune(text))), nil
	case PosUTF32:
		return len([]rune(text)), nil
	default:
		return 0, fmt.Errorf("unsupported position encoding: %s", encoding)
	}
}
