package main

import "fmt"

const P = PGroup(1000000007)

type PGroup int64

func Add(a, b PGroup) PGroup {
	return (a + b) % P
}

func Multi(a, b PGroup) PGroup {
	return (a * b) % P
}

func Power(x PGroup, y int) PGroup {
	res := PGroup(1)
	for ; y > 0; y >>= 1 {
		if y&1 == 1 {
			res = Multi(res, x)
		}
		x = Multi(x, x)
	}
	return res
}

func Divid(a, b PGroup) PGroup {
	return Multi(a, Power(b, 1000000005))
}

var ccache map[int]PGroup

func c(a, n int) PGroup {
	key := a + n*256
	if v, ok := ccache[key]; ok {
		return v
	}
	sum := PGroup(1)
	for i, k := PGroup(n), PGroup(1); k <= PGroup(a); i, k = i-1, k+1 {
		sum = Multi(sum, i)
		sum = Divid(sum, k)
	}
	ccache[key] = sum
	return sum
}

func numPermsDISequence(s string) int {
	ccache = make(map[int]PGroup)
	dp := make(map[int]PGroup)
	var calc func(ori string, f, t int) PGroup
	calc = func(ori string, f, t int) PGroup {
		k := f*256 + t
		if v, ok := dp[k]; ok {
			return v
		}
		s := ori[f:t]
		n := len(s)
		if n == 0 {
			return 1
		}
		sum := PGroup(0)
		if s[0] == 'I' {
			sum = Add(sum, calc(ori, f+1, t))
		}

		for i := 0; i < n-1; i++ {
			if s[i] == 'D' && s[i+1] == 'I' {
				sum = Add(
					sum,
					Multi(
						Multi(calc(ori, f, f+i), calc(ori, f+i+2, t)),
						c(i+1, n)))
			}
		}

		if s[n-1] == 'D' {
			sum = Add(sum, calc(ori, f, t-1))
		}
		dp[k] = sum
		return sum
	}
	return int(calc(s, 0, len(s)))
}

func main() {
	fmt.Println(numPermsDISequence("IIDDIIDDDIIIDIDIDIDDIIDDDDIDDIIDIIIDIIDDDDDDIDIDIDIDDIIDIIDIDIIIDDDIDDDIIDDIIDDDDDIDIIIIDDIDDDDIIDIDIDDIDIIIDDDIIDIIDIIIIDIDIDIDDIDIDDIDDDDIIIIIDDDIIDIIIDDIIDIIDIDIIIIDIIDIIIIIIDDIIIIIIDIIDIIDIDIIDDDI"))
}
