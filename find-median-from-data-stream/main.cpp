#include <bits/stdc++.h>
#include <queue>
using namespace std;

// https://leetcode.cn/problems/find-median-from-data-stream
class MedianFinder {
private:
  std::priority_queue<int> small;
  std::priority_queue<int, vector<int>, std::greater<int>> big;

public:
  MedianFinder() {}

  void addNum(int num) {
    auto mid = this->findMedian();
    if (num > mid) {
      this->big.push(num);
      if (this->big.size() > this->small.size() + 1) {
        this->small.push(this->big.top());
        this->big.pop();
      }
    } else {
      this->small.push(num);
      if (this->small.size() > this->big.size()) {
        this->big.push(this->small.top());
        this->small.pop();
      }
    }
  }

  double findMedian() {
    if (this->big.size() == this->small.size()) {
      if (this->big.empty()) {
        return 0;
      }
      return double(this->big.top() + this->small.top()) / 2;
    }
    return this->big.top();
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

TEST_CASE("find-median-from-data-stream") {
  MedianFinder s;
  s.addNum(1);
  s.addNum(2);
  CHECK(s.findMedian() == 1.5);
  s.addNum(3);
  CHECK(s.findMedian() == 2.0);
}
