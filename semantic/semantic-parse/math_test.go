package semantic_parse

import (
	"math"
	"testing"
)

func TestDouble(t *testing.T) {

	f := float64(5)
	for i := 0.0; i < 100; i++ {
		pow := math.Pow(10, i)
		if f/pow <= 0 {
			f2 := float64(2) + (f / pow)
			if f2 != 2.5 {
				t.Errorf("%f != 2.5", f2)
			}
		}
	}
}
