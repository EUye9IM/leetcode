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
