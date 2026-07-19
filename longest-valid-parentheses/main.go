package main

import (
	"fmt"
	"reflect"
)

// https://leetcode.cn/problems/longest-valid-parentheses
func longestValidParentheses(s string) int {
	ret := 0
	stack := []int{-1}
	for i, ch := range s {
		if ch == '(' {
			stack = append(stack, i)
		} else {
			stack = stack[:len(stack)-1]
			if len(stack) == 0 {
				stack = append(stack, i)
			} else {
				right := stack[len(stack)-1]
				ret = max(ret, i-right)
			}
		}
	}
	return ret
}

func assertEq(got, expect any) {
	if !reflect.DeepEqual(expect, got) {
		panic(fmt.Sprintf("got:  %v\nwant: %v", got, expect))
	}
}
func main() {
	assertEq(longestValidParentheses("(()"), 2)
	assertEq(longestValidParentheses(")()())"), 4)
	assertEq(longestValidParentheses("()(()"), 2)
	fmt.Println("All tests passed")
}
