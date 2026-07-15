#include <bits/stdc++.h>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/first-missing-positive
class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    for (auto i = (unsigned long)(0); i < nums.size(); i++) {
      if (nums[i] <= 0) {
        nums[i] = INT_MAX;
      }
    }
    for (auto i = (unsigned long)(0); i < nums.size(); i++) {
      if (abs(nums[i]) <= int(nums.size())) {
        nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
      }
    }
    for (auto i = (unsigned long)(0); i < nums.size(); i++) {
      if (nums[i] > 0) {
        return i + 1;
      }
    }
    return nums.size() + 1;
  }
};

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

TEST_CASE("first-missing-positive") {
  Solution s;
  vector<int> in;
  in = {1, 2, 0};
  CHECK(s.firstMissingPositive(in) == 3);
  in = {3, 4, -1, 1};
  CHECK(s.firstMissingPositive(in) == 2);
  in = {7, 8, 9, 10};
  CHECK(s.firstMissingPositive(in) == 1);
}
