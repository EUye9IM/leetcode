#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/minimum-window-substring
class Solution {
public:
  string minWindow(string s, string t) {
    int l = 0;
    unordered_map<char, int> t_cnt;
    unordered_map<char, int> s_cnt;
    string ret;
    for (auto c : t) {
      auto cnt = t_cnt.find(c);
      if (cnt == t_cnt.end()) {
        t_cnt.insert({c, 1});
      } else {
        cnt->second++;
      }
    }
    int bad_ch = t_cnt.size();
    for (int r = 0; r < int(s.length()); r++) {
      auto tnum = t_cnt.find(s[r]);
      if (tnum == t_cnt.end())
        continue;
      auto cnt = s_cnt.find(s[r]);
      if (cnt == s_cnt.end()) {
        auto [cnt2, _] = s_cnt.insert({s[r], 1});
        cnt = cnt2;
      } else {
        cnt->second++;
      }
      if (tnum->second == cnt->second) {
        bad_ch--;
      }
      if (bad_ch == 0) {
        for (; l <= r; l++) { // 缩小直到刚好不满足
          auto tnum = t_cnt.find(s[l]);
          if (tnum == t_cnt.end()) {
            continue;
          }
          auto cnt = s_cnt.find(s[l]);
          if (cnt->second == tnum->second)
            break;
          cnt->second--;
        }
        if (ret.empty() || (r - l + 1) < int(ret.length())) {
          ret = s.substr(l, r - l + 1);
        }
      }
    }
    return ret;
  }
};

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

TEST_CASE("minimum-window-substring") {
  Solution s;
  CHECK(s.minWindow("ADOBECODEBANC", "ABC") == "BANC");
  CHECK(s.minWindow("A", "A") == "A");
  CHECK(s.minWindow("A", "AA") == "");
}
