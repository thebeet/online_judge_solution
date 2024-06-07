package main

import "fmt"

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

func prime(n int) []int {
	p := make([]bool, n)
	result := make([]int, 0)
	for i := 2; i < n; i++ {
		if !p[i] {
			result = append(result, i)
			for j := i * i; j < n; j += i {
				p[j] = true
			}
		}
	}
	return result
}

func largestComponentSize(nums []int) int {
	hash := make([]int, 100001)
	primes := prime(100001)
	for i, v := range nums {
		hash[v] = i + 1
	}

	ds := NewDisJointSet(len(nums))

	for _, v := range primes {
		f := -1
		for j := v; j <= 100000; j += v {
			if hash[j] > 0 {
				if f == -1 {
					f = hash[j] - 1
				} else {
					ds.Union(f, hash[j]-1)
				}
			}
		}
	}

	mx := 0
	counts := make(map[int]int)
	for i := range nums {
		f := ds.Find(i)
		counts[f]++
		if counts[f] > mx {
			mx = counts[f]
		}
	}
	return mx
}

func main() {
	fmt.Println(largestComponentSize([]int{2, 3, 6, 7, 4, 12, 21, 39}))
}
