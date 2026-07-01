#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(const vector<int> &prices) {
    int buy = 10000;
    int gain = 0;
    for (auto p : prices) {
      gain = max(gain, p - buy);
      buy = min(buy, p);
    }
    return gain;
  }
};

TEST_CASE("best-time-to-buy-and-sell-stock") {
  Solution s;
  CHECK(s.maxProfit({7, 1, 5, 3, 6, 4}) == 5);
  CHECK(s.maxProfit({7, 6, 4, 3, 1}) == 0);
}
