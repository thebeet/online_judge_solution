package disjointset

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
