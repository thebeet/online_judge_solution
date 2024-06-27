package dlx

import "errors"

type Sudoku struct {
	n        int
	dlx      *Matrix
	solution []int
}

func NewSudoku(n int) *Sudoku {
	s := &Sudoku{n: n}
	n2 := n * n
	s.dlx = NewMatrix(n2*n2*n2, n2*n2*4)
	for x := 0; x < n2; x++ {
		for y := 0; y < n2; y++ {
			r := x*n2*n2 + y*n2
			sq := x/n*n + y/n
			for i := 0; i < n2; i++ {
				s.dlx.addCell(r+i, n2*x+y)
				s.dlx.addCell(r+i, n2*n2+x*n2+i)
				s.dlx.addCell(r+i, n2*n2*2+y*n2+i)
				s.dlx.addCell(r+i, n2*n2*3+sq*n2+i)
			}
		}
	}
	return s
}

func (s *Sudoku) AddNumber(x, y int, num int) {
	n2 := s.n * s.n
	row := s.dlx.rowHeads[x*n2*n2+y*n2+num-1]
	for p := row.right; p != row; p = p.right {
		col := s.dlx.colHeads[p.col]
		for p := col.down; p != col; p = p.down {
			hideRow(s.dlx.rowHeads[p.row])
		}
		hideColumn(col)
	}
	s.solution = append(s.solution, x*n2*n2+y*n2+num-1)
}

func (s *Sudoku) Solve() ([][]int, error) {
	solution, result := s.dlx.Solve(s.solution)
	if result {
		n2 := s.n * s.n
		table := make([][]int, n2)
		for i := 0; i < n2; i++ {
			table[i] = make([]int, n2)
		}
		for _, v := range solution {
			x := v / n2 / n2
			y := v / n2 % n2
			num := v % n2
			table[x][y] = num + 1
		}
		return table, nil
	}
	return nil, errors.New("no solution")
}
