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

func main() {
    if !solve() {
        fmt.Println("Test failed")
        os.Exit(1)
    }
    fmt.Println("All tests passed")
}

EOF
    ;;
rs)
    mkdir -p "$1"
    cat <<EOF >"$1/main.rs"
use std::process;

// https://leetcode.cn/problems/$1

fn main() {
    if !solve() {
        eprintln!("Test failed");
        process::exit(1);
    }
    println!("All tests passed");
}

fn solve() -> bool {
    true
}
EOF
    ;;
*)
    echo "Unknown language: $lang (use cpp, go, or rs)"
    exit 1
    ;;
esac

echo "Created $1/main.${lang/pp/pp} (language: $lang)"
