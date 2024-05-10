package main

import (
	"math/rand"
	"slices"
)

// 理论上不是对的解，但能过

type Solution struct {
	n         int
	blacklist []int

	m      int
	mapped map[int]int
}

func Constructor(n int, blacklist []int) Solution {
	s := Solution{n, blacklist, n - len(blacklist), make(map[int]int)}
	s.init()
	return s
}

func (this *Solution) init() {
	slices.Sort(this.blacklist)

	if this.n < 100000 {
		p := 0
		v := 0
		for i := range this.m {
			for p < len(this.blacklist) && this.blacklist[p] == v {
				p++
				v++
			}
			this.mapped[i] = v
			v++
		}
	}
}

func (this *Solution) isBlack(r int) bool {
	lo, hi := 0, len(this.blacklist)
	for lo+1 < hi {
		mid := (lo + hi) / 2
		if this.blacklist[mid] == r {
			return true
		}
		if this.blacklist[mid] < r {
			hi = mid
		} else {
			lo = mid
		}
	}
	return this.blacklist[lo] == r
}

func (this *Solution) Pick() int {
	if this.n < 100000 {
		return this.mapped[rand.Intn(this.m)]
	} else {
		for {
			r := rand.Intn(this.n)
			if !this.isBlack(r) {
				return r
			}
		}
	}
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(n, blacklist);
 * param_1 := obj.Pick();
 */
