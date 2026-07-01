#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "solution.cpp"

TEST_CASE("isValid normal cases") {
  Solution s;
  CHECK(s.isValid("()") == true);
  CHECK(s.isValid("()[]{}") == true);
  CHECK(s.isValid("(]") == false);
  CHECK(s.isValid("{{}}{{}}()()[][]") == true);
  CHECK(s.isValid("{{[[]}}") == false);
}

TEST_CASE("isValid edge cases") {
  Solution s;
  CHECK(s.isValid("") == true);
  CHECK(s.isValid(")") == false);
  CHECK(s.isValid("}") == false);
  CHECK(s.isValid("]") == false);
  CHECK(s.isValid("(") == false);
  CHECK(s.isValid("[") == false);
  CHECK(s.isValid("{") == false);
}
