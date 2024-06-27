package dlx

type Cell struct {
	row, col              int
	left, right, up, down *Cell
}

func NewCell() *Cell {
	c := &Cell{}
	c.left = c
	c.right = c
	c.up = c
	c.down = c
	return c
}

func hideRow(row *Cell) {
	for pointer := row.right; pointer != row; pointer = pointer.right {
		pointer.up.down = pointer.down
		pointer.down.up = pointer.up
	}
}

func showRow(row *Cell) {
	for pointer := row.right; pointer != row; pointer = pointer.right {
		pointer.up.down = pointer
		pointer.down.up = pointer
	}
}

func hideColumn(col *Cell) {
	col.left.right = col.right
	col.right.left = col.left
}

func showColumn(col *Cell) {
	col.left.right = col
	col.right.left = col
}

type Matrix struct {
	root               *Cell
	rowSize, colSize   int
	rowHeads, colHeads []*Cell
}

func NewMatrix(row, col int) *Matrix {
	m := &Matrix{}
	m.root = NewCell()
	m.rowSize = row
	m.colSize = col
	m.colHeads = make([]*Cell, 0)
	m.rowHeads = make([]*Cell, 0)

	for i := 0; i < col; i++ {
		colHead := NewCell()
		colHead.left = m.root.left
		colHead.right = m.root
		m.root.left.right = colHead
		m.root.left = colHead
		m.colHeads = append(m.colHeads, colHead)
	}

	for i := 0; i < row; i++ {
		rowHead := NewCell()
		rowHead.up = m.root.up
		rowHead.down = m.root
		m.root.up.down = rowHead
		m.root.up = rowHead
		m.rowHeads = append(m.rowHeads, rowHead)
	}
	return m
}

func (m *Matrix) addCell(x, y int) {
	c := NewCell()
	c.row = x
	c.col = y
	row := m.rowHeads[x]
	col := m.colHeads[y]

	c.left = row.left
	c.right = row
	row.left.right = c
	row.left = c

	c.up = col.up
	c.down = col
	col.up.down = c
	col.up = c
}

func (m *Matrix) Solve(solution []int) ([]int, bool) {
	if m.root.right != m.root {
		col := m.root.right
		for p := col.down; p != col; p = p.down {
			solution = append(solution, p.row)
			row := m.rowHeads[p.row]
			hideRows := make([]*Cell, 0)
			for p := row.right; p != row; p = p.right {
				col := m.colHeads[p.col]
				for p := col.down; p != col; p = p.down {
					r := m.rowHeads[p.row]
					hideRow(r)
					hideRows = append(hideRows, r)
				}
				hideColumn(col)
			}
			ts, flag := m.Solve(solution)
			if flag {
				return ts, true
			}
			solution = solution[:len(solution)-1]
			for p := row.left; p != row; p = p.left {
				showColumn(m.colHeads[p.col])
			}
			for i := len(hideRows) - 1; i >= 0; i-- {
				showRow(hideRows[i])
			}
		}
		return nil, false
	}
	return solution, true
}
