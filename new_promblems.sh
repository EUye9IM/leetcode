mkdir $1
cat <<EOF >$1/test.cpp
class Solution {
public:
  bool solute() { return true; };
};

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

TEST_CASE("$1") {
  Solution s;
  CHECK(s.solute());
}
EOF
