package dlx_test

import (
	"testing"

	"github.com/stretchr/testify/assert"
	"github.com/thebeet/sudoku-solver/solver/dlx"
)

func TestSudoku(t *testing.T) {
	s := dlx.NewSudoku(3)
	board := []string{
		"53..7....",
		"6..195...",
		".98....6.",
		"8...6...3",
		"4..8.3..1",
		"7...2...6",
		".6....28.",
		"...419..5",
		"....8..79",
	}
	for y, line := range board {
		for x, c := range line {
			if c != '.' {
				n := int(c - '0')
				s.AddNumber(x, y, n)
			}
		}
	}
	table, _ := s.Solve()

	assert.Equal(t, []int{5, 6, 1, 8, 4, 7, 9, 2, 3}, table[0])
	assert.Equal(t, []int{3, 7, 9, 5, 2, 1, 6, 8, 4}, table[1])
	assert.Equal(t, []int{4, 2, 8, 9, 6, 3, 1, 7, 5}, table[2])
	assert.Equal(t, []int{6, 1, 3, 7, 8, 9, 5, 4, 2}, table[3])
	assert.Equal(t, []int{7, 9, 4, 6, 5, 2, 3, 1, 8}, table[4])
	assert.Equal(t, []int{8, 5, 2, 1, 3, 4, 7, 9, 6}, table[5])
	assert.Equal(t, []int{9, 3, 5, 4, 7, 8, 2, 6, 1}, table[6])
	assert.Equal(t, []int{1, 4, 6, 2, 9, 5, 8, 3, 7}, table[7])
	assert.Equal(t, []int{2, 8, 7, 3, 1, 6, 4, 5, 9}, table[8])
}
