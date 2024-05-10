package main

type disjointset struct {
	size   int
	father []int
}

func NewDisJointSet(size int) *disjointset {
	father := make([]int, size)
	for i := range father {
		father[i] = i
	}
	return &disjointset{
		size:   size,
		father: father,
	}
}

func (d *disjointset) Find(x int) int {
	if d.father[x] != x {
		d.father[x] = d.Find(d.father[x])
	}
	return d.father[x]
}

func (d *disjointset) Union(x, y int) {
	x = d.Find(x)
	y = d.Find(y)
	d.father[x] = y
}

func testStr(str1, str2 string) bool {
	m := len(str1)
	same := 0
	for i := range m {
		if str1[i] == str2[i] {
			same++
		}
	}
	return same+2 >= m
}

func numSimilarGroups(strs []string) int {
	n := len(strs)
	d := NewDisJointSet(n)

	for i := range n {
		for j := i + 1; j < n; j++ {
			if testStr(strs[i], strs[j]) {
				d.Union(i, j)
			}
		}
	}

	hash := make(map[int]bool, 0)
	for i := range n {
		hash[d.Find(i)] = true
	}
	return len(hash)
}
