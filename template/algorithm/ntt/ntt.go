package main

import (
	"fmt"
	"math/big"
	"strconv"
	"strings"
)

const P int64 = 998244353

func qpow(x, y int64) int64 {
	res := int64(1)
	for ; y > 0; y >>= 1 {
		if y&1 == 1 {
			res = res * x % P
		}
		x = x * x % P
	}
	return res
}

// 位逆序置换
func makeReverse(lim int) []int {
	r := make([]int, lim)
	for i := 0; i < lim; i++ {
		r[i] = (i&1)*(lim>>1) + (r[i>>1] >> 1)
	}
	return r
}

// ntt 对输入数组进行NTT（快速傅里叶变换）算法计算
func ntt(num []int64, lim int, op int64) []int64 {
	r := makeReverse(lim)
	for i := 0; i < lim; i++ {
		if r[i] < i {
			num[i], num[r[i]] = num[r[i]], num[i]
		}
	}
	for m := 2; m <= lim; m <<= 1 {
		k := m >> 1
		gn := qpow(3, (P-1)/int64(m))
		for i := 0; i < lim; i += m {
			g := int64(1)
			for j := 0; j < k; j++ {
				tmp := num[i+j+k] * g % P
				num[i+j+k] = (num[i+j] - tmp + P) % P
				num[i+j] = (num[i+j] + tmp) % P
				g = g * gn % P
			}
		}
	}
	if op == -1 {
		for i := 1; i < lim-i; i++ {
			num[i], num[lim-i] = num[lim-i], num[i]
		}
		inv := qpow(int64(lim), P-2)
		for i := 0; i < lim; i++ {
			num[i] = num[i] * inv % P
		}
	}
	return num
}

func mul(a, b string) string {
	lim := 1
	for lim < len(a) || lim < len(b) {
		lim <<= 1
	}
	lim <<= 1
	numA := make([]int64, lim)
	numB := make([]int64, lim)
	for i := 0; i < len(a); i++ {
		numA[i] = int64(a[len(a)-i-1]) - '0'
	}
	for i := 0; i < len(b); i++ {
		numB[i] = int64(b[len(b)-i-1]) - '0'
	}
	ntt(numA, lim, 1)
	ntt(numB, lim, 1)
	for i := 0; i < lim; i++ {
		numA[i] = numA[i] * numB[i] % P
	}
	ntt(numA, lim, -1)
	for i := 0; i < lim-1; i++ {
		if numA[i] >= 10 {
			numA[i+1] += numA[i] / 10
			numA[i] = numA[i] % 10
		}
	}
	var out strings.Builder
	var flag = false
	for i := lim - 1; i >= 0; i-- {
		if !flag && (numA[i] > 0) {
			flag = true
		}
		if flag {
			out.WriteString(strconv.FormatInt(numA[i], 10))
		}
	}
	if !flag {
		out.WriteString("0")
	}
	return out.String()
}

func main() {
	// 输入两个大整数
	num1 := "1213213211212313213"
	num2 := "123123132413163714124"

	// 创建 big.int 对象
	num1Big, _ := new(big.Int).SetString(num1, 10)
	num2Big, _ := new(big.Int).SetString(num2, 10)

	// 进行乘法运算
	result := new(big.Int).Mul(num1Big, num2Big)

	fmt.Printf("%s * %s = ", num1, num2)
	// 输出结果
	fmt.Println("Result:", result.String())

	fmt.Printf("%s\n", mul(num1, num2))
}
