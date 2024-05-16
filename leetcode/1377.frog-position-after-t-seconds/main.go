package main

func frogPosition(n int, edges [][]int, t int, target int) float64 {
	nodeEdges := make([][]int, n)
	for i := range n {
		nodeEdges[i] = make([]int, 0)
	}
	nodeEdges[0] = append(nodeEdges[0], 0)
	for _, e := range edges {
		nodeEdges[e[0]-1] = append(nodeEdges[e[0]-1], e[1]-1)
		nodeEdges[e[1]-1] = append(nodeEdges[e[1]-1], e[0]-1)
	}

	result := make([]float64, n)
	visit := make([]bool, n)
	result[0] = 1
	queue := [][]int{
		make([]int, 1),
		make([]int, 0),
	}
	queue[0][0] = 0

	for i := range t {
		pf, pt := i%2, (i+1)%2
		for _, c := range queue[pf] {
			visit[c] = true
			if len(nodeEdges[c]) > 1 {
				p := result[c] / float64(len(nodeEdges[c])-1.0)
				result[c] = 0
				for _, v := range nodeEdges[c] {
					if !visit[v] {
						result[v] = p
						queue[pt] = append(queue[pt], v)
					}
				}
			}
		}
	}
	return result[target-1]
}
