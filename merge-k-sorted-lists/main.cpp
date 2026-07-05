#include <bits/stdc++.h>
#include <queue>
#include <vector>
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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto cmp = [](const ListNode *a, const ListNode *b) {
      return a->val > b->val;
    };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> queue(cmp);
    for (auto *list : lists) {
      if (list != nullptr) queue.push(list);
    }

    ListNode *ret = nullptr, *next = nullptr;
    while (!queue.empty()) {
      auto l = queue.top();
      if (ret == nullptr) {
        ret = new ListNode(l->val);
        next = ret;
      } else {
        next->next = new ListNode(l->val);
        next = next->next;
      }
      queue.pop();
      if (l->next!=nullptr){
          queue.push(l->next);
      }
    }
    return ret;
  }
};

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

// 辅助函数：从 vector 构建链表
ListNode *buildList(const vector<int> &vals) {
  ListNode dummy(0), *tail = &dummy;
  for (int v : vals) {
    tail->next = new ListNode(v);
    tail = tail->next;
  }
  return dummy.next;
}

// 辅助函数：将链表转成 vector，方便比较
vector<int> listToVector(ListNode *head) {
  vector<int> result;
  while (head) {
    result.push_back(head->val);
    head = head->next;
  }
  return result;
}
TEST_CASE("merge-k-sorted-lists") {
  Solution s;
  // 示例 1
  SUBCASE("example 1") {
    vector<ListNode *> lists = {
        buildList({1, 4, 5}),
        buildList({1, 3, 4}),
        buildList({2, 6}),
    };
    auto *result = s.mergeKLists(lists);
    CHECK(listToVector(result) == vector<int>({1, 1, 2, 3, 4, 4, 5, 6}));
  }

  // 示例 2：空数组
  SUBCASE("example 2 - empty lists") {
    vector<ListNode *> lists;
    CHECK(s.mergeKLists(lists) == nullptr);
  }

  // 示例 3：数组里有一个空链表
  SUBCASE("example 3 - list with nullptr") {
    vector<ListNode *> lists = {nullptr};
    CHECK(s.mergeKLists(lists) == nullptr);
  }

  // 额外：单链表
  SUBCASE("single list") {
    vector<ListNode *> lists = {buildList({1, 2, 3})};
    auto *result = s.mergeKLists(lists);
    CHECK(listToVector(result) == vector<int>({1, 2, 3}));
  }

  // 额外：全空
  SUBCASE("all nullptrs") {
    vector<ListNode *> lists = {nullptr, nullptr, nullptr};
    CHECK(s.mergeKLists(lists) == nullptr);
  }
}
