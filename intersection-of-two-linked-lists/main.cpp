#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
// https://leetcode.cn/problems/intersection-of-two-linked-lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA, *b = headB;
    bool f = true, g = true;
    while (a != nullptr && b != nullptr) {
      if (a == b && f == g) {
        return a;
      }
      a = a->next;
      b = b->next;
      if (a == nullptr) {
        if (f) {
          f = false;
        } else {
          return nullptr;
        }
        a = headB;
      }
      if (b == nullptr) {
        g = false;
        b = headA;
      }
    }
    return nullptr;
  }
};
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

static ListNode *buildList(initializer_list<int> vals) {
  ListNode dummy(0), *p = &dummy;
  for (int v : vals)
    p = p->next = new ListNode(v);
  return dummy.next;
}

TEST_CASE("intersection-of-two-linked-lists") {
  Solution s;

  SUBCASE("示例") {
    // 共同部分: 8 -> 4 -> 5
    ListNode *common = buildList({8, 4, 5});
    // listA: 4 -> 1 -> common
    ListNode *a = new ListNode(4);
    a->next = new ListNode(1);
    a->next->next = common;
    // listB: 5 -> 6 -> 1 -> common
    ListNode *b = new ListNode(5);
    b->next = new ListNode(6);
    b->next->next = new ListNode(1);
    b->next->next->next = common;

    ListNode *result = s.getIntersectionNode(a, b);
    CHECK(result == common);
  }
}
