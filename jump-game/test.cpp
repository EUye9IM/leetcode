#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    unsigned long loc = 0;
    for (unsigned long i = 0; i < nums.size(); i++) {
      if (loc < i) {
        return false;
      }
      loc = max(loc, i + nums[i]);
      if (loc >= nums.size()) {
        return true;
      }
    }
    return true;
  }
};
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

TEST_CASE("jump-game") {
  Solution s;
  vector<int> in = {2, 3, 1, 1, 4};
  CHECK(s.canJump(in) == true);
  in = {3, 2, 1, 0, 4};
  CHECK(s.canJump(in) == false);
}
