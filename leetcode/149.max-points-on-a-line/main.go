package main

type Point []int

func onLine(p1, p2 Point, p Point) bool {
	v1x, v1y := p[0]-p1[0], p[1]-p1[1]
	v2x, v2y := p2[0]-p1[0], p2[1]-p1[1]
	return v1x*v2y-v2x*v1y == 0
}

func maxPoints(points [][]int) int {
	n := len(points)
	ans := 1
	for i := range n {
		for j := i + 1; j < n; j++ {
			sum := 0
			for k := range n {
				if i == k || j == k || onLine(points[i], points[j], points[k]) {
					sum++
				}
			}
			ans = max(ans, sum)
		}
	}
	return ans
}
