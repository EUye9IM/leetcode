mkdir $1
cat <<EOF >$1/test.cpp
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/$1
class Solution {
public:
  bool solute() { return true; };
};

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

TEST_CASE("$1") {
  Solution s;
  CHECK(s.solute() == true);
}
EOF
