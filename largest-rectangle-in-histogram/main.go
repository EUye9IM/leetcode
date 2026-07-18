package main

import (
	"fmt"
	"reflect"
)

// https://leetcode.cn/problems/largest-rectangle-in-histogram
func largestRectangleArea(heights []int) int {
	ret := 0
	stack := []struct {
		idx    int
		height int
	}{
		{-1, -1},
	}
	left := make([]int, len(heights))
	right := make([]int, len(heights))
	for i := range heights {
		for stack[len(stack)-1].height >= heights[i] {
			stack = stack[:len(stack)-1]
		}
		left[i] = stack[len(stack)-1].idx
		stack = append(stack, struct {
			idx    int
			height int
		}{i, heights[i]})
	}
	stack = []struct {
		idx    int
		height int
	}{
		{len(heights), -1},
	}
	for i := len(heights) - 1; i >= 0; i-- {
		for stack[len(stack)-1].height >= heights[i] {
			stack = stack[:len(stack)-1]
		}
		right[i] = stack[len(stack)-1].idx
		stack = append(stack, struct {
			idx    int
			height int
		}{i, heights[i]})
	}
	for i := range heights {
		ret = max(ret, heights[i]*(right[i]-left[i]-1))
	}
	return ret
}

func assertEq(got, expect any) {
	if !reflect.DeepEqual(expect, got) {
		panic(fmt.Sprintf("got:  %v\nwant: %v", got, expect))
	}
}
func main() {
	assertEq(largestRectangleArea([]int{2, 4}), 4)
	assertEq(largestRectangleArea([]int{4, 2}), 4)
	assertEq(largestRectangleArea([]int{2, 1, 5, 6, 2, 3}), 10)
	assertEq(largestRectangleArea([]int{2, 1, 2}), 3)
	fmt.Println("All tests passed")
}
