package main

type node struct {
	id       int
	size     int
	distance int
	result   int
	children []*node
}

func BuildTree(id int, parent int, edges [][]int) *node {
	nd := &node{id: id, size: 1, distance: 0, result: 0, children: make([]*node, 0)}
	for _, e := range edges[id] {
		if e != parent {
			c := BuildTree(e, id, edges)
			nd.children = append(nd.children, c)
			nd.size += c.size
			nd.distance += (c.size + c.distance)
		}
	}
	return nd
}

func sumOfDistancesInTree(n int, edges [][]int) []int {
	edgeList := make([][]int, n)
	for i := range n {
		edgeList[i] = make([]int, 0)
	}
	for _, v := range edges {
		edgeList[v[0]] = append(edgeList[v[0]], v[1])
		edgeList[v[1]] = append(edgeList[v[1]], v[0])
	}
	root := BuildTree(0, -1, edgeList)
	root.result = root.distance
	result := make([]int, n)

	var travel func(nd *node)
	travel = func(nd *node) {
		result[nd.id] = nd.result
		for _, c := range nd.children {
			c.result = nd.result + n - c.size*2
			travel(c)
		}
	}
	travel(root)
	return result
}
