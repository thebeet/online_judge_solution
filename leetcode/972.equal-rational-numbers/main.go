package main

import (
	"fmt"
	"regexp"
	"strconv"
)

type Fraction struct {
	d int64
	n int64
}

func gcd(a, b int64) int64 {
	if a > b {
		return gcd(b, a)
	} else if a > 0 {
		return gcd(b%a, a)
	} else {
		return b
	}
}

func (f *Fraction) Simplification() *Fraction {
	m := gcd(f.d, f.n)
	f.d /= m
	f.n /= m
	return f
}

func NewFraction(d, n int64) *Fraction {
	return &Fraction{d, n}
}

func (f *Fraction) Add(a *Fraction) *Fraction {
	f.d, f.n = f.d*a.n+a.d*f.n, f.n*a.n
	return f.Simplification()
}

func power(x, n int) int {
	r := 1
	for range n {
		r *= x
	}
	return r
}

func parseNumber(s string) *Fraction {
	re, _ := regexp.Compile(`^(\d+)(?:\.(?:(?:(\d*)(?:\((\d+)\))?)))?$`)
	matches := re.FindStringSubmatch(s)
	var i, nrp, rp int
	f := NewFraction(int64(0), int64(1))
	switch len(matches) {
	case 4:
		if len(matches[3]) > 0 {
			rp, _ = strconv.Atoi(matches[3])
			tf := NewFraction(int64(rp), int64(power(10, len(matches[2]))*(power(10, len(matches[3]))-1)))
			f.Add(tf)
		}
		fallthrough
	case 3:
		nrp, _ = strconv.Atoi(matches[2])
		f.Add(NewFraction(int64(nrp), int64(power(10, len(matches[2])))))
		fallthrough
	case 2:
		i, _ = strconv.Atoi(matches[1])
		f.Add(NewFraction(int64(i), int64(1)))
	default:
	}
	return f
}

func isRationalEqual(s string, t string) bool {
	sf, tf := parseNumber(s), parseNumber(t)
	return *sf == *tf
}

func main() {
	fmt.Println(isRationalEqual("1.", "0.(9)"))
}
