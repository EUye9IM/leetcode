package main

import (
	"fmt"
	"os"
)

// https://leetcode.cn/problems/longest-consecutive-sequence
func longestConsecutive(nums []int) int {
	m := map[int]struct{}{}
	for _, n := range nums {
		m[n] = struct{}{}
	}
	ret := 0
	for n := range m {
		if _, ok := m[n-1]; ok {
			continue
		}
		for i := n + 1; ; i++ {
			if _, ok := m[i]; !ok {
				ret = max(ret, i-n)
				break
			}
		}
	}
	return ret
}

func main() {
	if longestConsecutive([]int{100, 4, 200, 1, 3, 2}) != 4 {
		fmt.Println("Test failed")
		os.Exit(1)
	}
	if longestConsecutive([]int{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}) != 9 {
		fmt.Println("Test failed")
		os.Exit(1)
	}
	if longestConsecutive([]int{1, 0, 1, 2}) != 3 {
		fmt.Println("Test failed")
		os.Exit(1)
	}
	fmt.Println("All tests passed")
}
