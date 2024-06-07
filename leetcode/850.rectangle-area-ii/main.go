package main

import "sort"

func mapDown(values []int) (map[int]int, []int) {
	dup := make(map[int]int)
	for _, v := range values {
		dup[v] = 1
	}
	a := make(sort.IntSlice, 0)
	for v := range dup {
		a = append(a, v)
	}
	a.Sort()
	ans := make(map[int]int)
	for i, v := range a {
		ans[v] = i
	}
	return ans, a
}

func rectangleArea(rectangles [][]int) int {
	n := len(rectangles)
	xx := make([]int, n*2)
	yy := make([]int, n*2)
	for i, v := range rectangles {
		xx[i*2] = v[0]
		yy[i*2] = v[1]
		xx[i*2+1] = v[2]
		yy[i*2+1] = v[3]
	}
	xmap, xarr := mapDown(xx)
	ymap, yarr := mapDown(yy)
	xn := len(xmap)
	yn := len(ymap)

	board := make([][]bool, xn)
	for x := range xn {
		board[x] = make([]bool, yn)
	}

	for _, v := range rectangles {
		for x := xmap[v[0]]; x < xmap[v[2]]; x++ {
			for y := ymap[v[1]]; y < ymap[v[3]]; y++ {
				board[x][y] = true
			}
		}
	}

	ans := int64(0)
	for x := range xn {
		for y := range yn {
			if board[x][y] {
				ans += int64(xarr[x+1]-xarr[x]) * int64(yarr[y+1]-yarr[y])
			}
		}
	}
	return int(ans % int64(1000000007))
}
