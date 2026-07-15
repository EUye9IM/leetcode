package main

import (
	"fmt"
	"reflect"
	"strings"
)

// https://leetcode.cn/problems/n-queens
func solveNQueens(n int) [][]string {
	var ans [][]string
	curans := make([]int, n)

	var dfs func(i int, mask, maskl, maskr uint)
	dfs = func(i int, mask, maskl, maskr uint) {
		if i == n {
			newans := make([]string, n)
			for j, v := range curans {
				line := []byte(strings.Repeat(".", n))
				line[v] = 'Q'
				newans[j] = string(line)
			}
			ans = append(ans, newans)
			return
		}
		for q := range n {
			maskq := uint(1) << q
			if maskq&(mask|maskl|maskr) == 0 {
				curans[i] = q
				dfs(i+1, mask|maskq, (maskl|maskq)<<1, (maskr|maskq)>>1)
			}
		}
	}
	dfs(0, 0, 0, 0)
	return ans
}

func assertEq(got, expect any) {
	if !reflect.DeepEqual(expect, got) {
		panic(fmt.Sprintf("got:  %v\nwant: %v", got, expect))
	}
}
func main() {
	assertEq(solveNQueens(1), [][]string{{"Q"}})
	fmt.Println("All tests passed")
}
