package main

import "fmt"

func findLongest(str string) int {
    ans := 0
    n := len(str)
    hash := make([]int, 256)
    left, right := 0, 0
    for right < n {
        c := int(str[right] - 'a')
        for hash[c] > 0 {
            lc := int(str[left] - 'a')
            hash[lc]--
            left++
        }
        hash[c]++
        right++
        if right - left > ans {
            ans = right - left
        }
    }
    return ans
}

func main() {
    // var a int
    // fmt.Scan(&a)
    fmt.Println(findLongest("abcabcabc"))
}