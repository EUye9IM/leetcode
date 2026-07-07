package main

import (
	"fmt"
	"reflect"
)

// https://leetcode.cn/problems/subarray-sum-equals-k
func subarraySum(nums []int, k int) int {
	sum := 0
	summap := make(map[int]int)
	summap[0] = 1
	cnt := 0
	for _, num := range nums {
		sum = sum + num
		cnt += summap[sum-k]
		summap[sum]++
	}
	return cnt
}

func assertEq(got, expect any) {
	if !reflect.DeepEqual(expect, got) {
		panic(fmt.Sprintf("got:  %v\nwant: %v", got, expect))
	}
}
func main() {
	assertEq(subarraySum([]int{1, 1, 1}, 2), 2)
	assertEq(subarraySum([]int{1, 2, 3}, 3), 2)
	fmt.Println("All tests passed")
}
