package main

type pos struct {
	x     int
	y     int
	drill int
}

func shortestPath(grid [][]int, k int) int {
	queue := [][]*pos{
		make([]*pos, 0),
		make([]*pos, 0),
	}
	queue[0] = append(queue[0], &pos{
		x: 0, y: 0, drill: 0,
	})
	n := len(grid)
	m := len(grid[0])

	maxDrill := make([][]int, n)
	for x := range n {
		maxDrill[x] = make([]int, m)
		for y := range m {
			maxDrill[x][y] = k + 1
		}
	}
	maxDrill[0][0] = 0

	dx := []int{1, -1, 0, 0}
	dy := []int{0, 0, 1, -1}

	for i := range n * m {
		pf, pt := i%2, (i+1)%2
		queue[pt] = make([]*pos, 0)
		for _, c := range queue[pf] {
			if c.drill > maxDrill[c.x][c.y] {
				continue
			}
			for mv := range 4 {
				next := &pos{
					x:     c.x + dx[mv],
					y:     c.y + dy[mv],
					drill: c.drill,
				}
				if next.x < 0 || next.y < 0 || next.x >= n || next.y >= m {
					continue
				}
				if grid[next.x][next.y] == 1 {
					next.drill += 1
				}
				if next.drill <= k && next.drill < maxDrill[next.x][next.y] {
					maxDrill[next.x][next.y] = next.drill
					queue[pt] = append(queue[pt], next)
				}
			}
		}
		if maxDrill[n-1][m-1] <= k {
			return i + 1
		}
	}
	return -1
}
