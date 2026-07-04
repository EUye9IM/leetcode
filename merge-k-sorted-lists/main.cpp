#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/merge-k-sorted-lists
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> & /*lists*/) { return nullptr; }
};

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

TEST_CASE("merge-k-sorted-lists") {
  Solution s;
  vector<ListNode *> empty;
  CHECK(s.mergeKLists(empty) == nullptr);
}
