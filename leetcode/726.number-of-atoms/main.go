package main

import (
	"fmt"
	"regexp"
	"sort"
	"strconv"
	"strings"
)

type Result map[string]int

func (r Result) Multi(scale int) Result {
	for k := range r {
		r[k] = r[k] * scale
	}
	return r
}

func (r Result) Add(r1 Result) Result {
	for k, v := range r1 {
		r[k] += v
	}
	return r
}

func counts(formula string) Result {
	ans := make(Result, 0)
	n := len(formula)
	if n == 0 {
		return ans
	}
	if formula[0] == '(' {
		p, stack := 0, 1
		for stack > 0 {
			p++
			if formula[p] == '(' {
				stack++
			} else if formula[p] == ')' {
				stack--
			}
		}
		ans = counts(formula[1:p])
		p++
		numP := regexp.MustCompile(`^(\d+)`)
		num := numP.FindString(formula[p:])
		c := 1
		if len(num) > 0 {
			c, _ = strconv.Atoi(num)
			ans.Multi(c)
		}
		ans.Add(counts(formula[p+len(num):]))
	} else {
		atomP := regexp.MustCompile(`^([A-Z][a-z]*)(\d*)`)
		match := atomP.FindStringSubmatch(formula)
		c := 1
		if len(match[2]) > 0 {
			c, _ = strconv.Atoi(match[2])
		}
		ans[match[1]] = c
		ans.Add(counts(formula[len(match[0]):]))
	}
	return ans
}

func countOfAtoms(formula string) string {
	ans := counts(formula)
	keys := make(sort.StringSlice, 0)
	for k := range ans {
		keys = append(keys, k)
	}
	keys.Sort()
	var strbd strings.Builder
	for _, k := range keys {
		strbd.WriteString(k)
		if ans[k] > 1 {
			strbd.WriteString(fmt.Sprintf("%d", ans[k]))
		}
	}
	return strbd.String()
}

func main() {
	fmt.Println(counts("((OH)3G2)8Hss2H"))
}
