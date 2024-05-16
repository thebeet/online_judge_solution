package main

import "fmt"

type boundBox struct {
	xmin, ymin, xmax, ymax int
}

func intersect(box1, box2 *boundBox) (bool, *boundBox) {
	xmin := max(box1.xmin, box2.xmin)
	ymin := max(box1.ymin, box2.ymin)
	xmax := min(box1.xmax, box2.xmax)
	ymax := min(box1.ymax, box2.ymax)
	if xmin > xmax || ymin > ymax {
		return false, nil
	} else {
		return true, &boundBox{
			xmin, ymin, xmax, ymax,
		}
	}
}

func isPrintable(targetGrid [][]int) bool {
	n := len(targetGrid)
	m := len(targetGrid[0])
	k := 64
	boundBoxes := make([]boundBox, k)
	for i := range k {
		boundBoxes[i].xmin = n + 1
		boundBoxes[i].ymin = m + 1
		boundBoxes[i].xmax = -1
		boundBoxes[i].ymax = -1
	}
	for x := range n {
		for y := range m {
			c := targetGrid[x][y]
			boundBoxes[c].xmin = min(boundBoxes[c].xmin, x)
			boundBoxes[c].ymin = min(boundBoxes[c].ymin, y)
			boundBoxes[c].xmax = max(boundBoxes[c].xmax, x)
			boundBoxes[c].ymax = max(boundBoxes[c].ymax, y)
		}
	}

	edgeCount := make([]int, k)
	edges := make([][]int, k)
	for i := range k {
		edges[i] = make([]int, 0)
		edgeCount[i] = 0
	}

	for i := range k {
		for j := i + 1; j < k; j++ {
			if isIntersect, box := intersect(&boundBoxes[i], &boundBoxes[j]); isIntersect {
				hasI, hasJ := false, false
				for x := box.xmin; x <= box.xmax; x++ {
					for y := box.ymin; y <= box.ymax; y++ {
						if targetGrid[x][y] == i {
							hasI = true
						}
						if targetGrid[x][y] == j {
							hasJ = true
						}
					}
				}
				if hasI {
					edges[i] = append(edges[i], j)
					edgeCount[j]++
				}
				if hasJ {
					edges[j] = append(edges[j], i)
					edgeCount[i]++
				}
			}
		}
	}

	queue := make([]int, 0)
	for i := range k {
		if edgeCount[i] == 0 {
			queue = append(queue, i)
		}
	}
	c := 0
	for len(queue) > 0 {
		c++
		i := queue[0]
		queue = queue[1:]
		for _, j := range edges[i] {
			edgeCount[j]--
			if edgeCount[j] == 0 {
				queue = append(queue, j)
			}
		}
	}
	return c == k
}

func main() {
	fmt.Println(isPrintable([][]int{
		[]int{5, 1, 5, 3, 5},
		[]int{4, 4, 4, 3, 4},
		[]int{5, 1, 5, 3, 5},
		[]int{2, 1, 2, 2, 2},
		[]int{5, 1, 5, 3, 5},
	}))
}
