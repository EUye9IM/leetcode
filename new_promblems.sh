#!/bin/bash
# Usage: bash new_promblems.sh <problem-name> [cpp|go|rs]
#   cpp - C++20 with doctest (default)
#   go  - Go with hand-written assertions
#   rs  - Rust with hand-written assertions

lang=${2:-cpp}

case $lang in
cpp)
    mkdir -p "$1"
    cat <<EOF >"$1/main.cpp"
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/$1
class Solution {
public:
  auto solve() { return true; }
};

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

TEST_CASE("$1") {
  Solution s;
  CHECK(s.solve() == true);
}
EOF
    ;;
go)
    mkdir -p "$1"
    cat <<EOF >"$1/main.go"
package main

import (
    "fmt"
    "os"
)

// https://leetcode.cn/problems/$1
func solve() bool {
    return true
}

func assertEq(got, expect any) {
	if !reflect.DeepEqual(expect, got) {
		panic(fmt.Sprintf("got:  %v\nwant: %v", got, expect))
	}
}
func main() {
    assertEq(solve(), true)
    fmt.Println("All tests passed")
}

EOF
    ;;
rs)
    mkdir -p "$1"
    cat <<EOF >"$1/main.rs"
// https://leetcode.cn/problems/$1
impl Solution {
    pub fn solve() -> bool {
        true
    }
}

struct Solution {}
fn main() {
    assert!(Solution::solve());
    println!("All tests passed");
}

EOF
    cat <<EOF >"$1/Cargo.toml"
[package]
name = "lc-$1"
version = "0.1.0"
edition = "2021"

[[bin]]
name = "lc-$1"
path = "main.rs"
EOF
    if [ -f Cargo.toml ]; then
        sed -i "s/^members = \[/members = [\"$1\", /" Cargo.toml
    fi
    ;;
*)
    echo "Unknown language: $lang (use cpp, go, or rs)"
    exit 1
    ;;
esac

echo "Created $1/main.${lang/pp/pp} (language: $lang)"
