package semantic_rules

import (
	"math/rand"
	"testing"
)

func BenchmarkCast(t *testing.B) {
	elements := func() []element {
		var e []element
		for i := 0; i < 2000; i++ {
			intn := rand.Intn(3)
			if intn == 0 {
				e = append(e, sElement{})
			} else if intn == 1 {
				e = append(e, pElement{})
			} else {
				e = append(e, tElement{})
			}
		}
		return e
	}()
	t.Run("cast", func(t *testing.B) {
		var s, p, tE = 0, 0, 0
		for _, e := range elements {
			_, ok := e.(sElement)
			if ok {
				s++
			} else {
				_, ok := e.(pElement)
				if ok {
					p++
				} else {
					tE++
				}
			}

		}
	})
	t.Run("function", func(t *testing.B) {
		var s, p, tE = 0, 0, 0
		for _, e := range elements {
			switch e.getType() {
			case "sElement":
				s++
			case "pElement":
				p++
			case "tElement":
				tE++
			}
		}
	})
}

type (
	element interface {
		getType() string
	}

	sElement struct {
	}

	pElement struct {
	}
	tElement struct {
	}
)

func (t tElement) getType() string {
	return "tElement"
}

func (s sElement) getType() string {
	return "sElement"
}

func (s pElement) getType() string {
	return "pElement"
}
