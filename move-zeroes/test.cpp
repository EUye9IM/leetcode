#include <bits/stdc++.h>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/move-zeroes
class Solution {
public:
  bool moveZeroes(vector<int> &nums) {
    unsigned int i = 0;
    for (unsigned int j = 0; j < nums.size(); j++) {
      if (nums[j] != 0) {
        nums[i] = nums[j];
        i++;
      }
    }
    for (; i < nums.size(); i++) {
      nums[i] = 0;
    }
    return true;
  };
};

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

TEST_CASE("move-zeroes") {
  Solution s;
  vector<int> in = {0, 1, 0, 3, 12};
  vector<int> out = {1, 3, 12, 0, 0};
  s.moveZeroes(in);
  CHECK(in == out);
}
