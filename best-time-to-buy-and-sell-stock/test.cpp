#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "solution.cpp"

TEST_CASE("maxProfit") {
  Solution s;
  CHECK(s.maxProfit({7, 1, 5, 3, 6, 4}) == 5);
  CHECK(s.maxProfit({7, 6, 4, 3, 1}) == 0);
}
