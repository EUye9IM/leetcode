#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    vector<char> stack;
    for (char c : s) {
      switch (c) {
      case '(':
      case '[':
      case '{':
        stack.push_back(c);
        break;
      default:
        if (stack.empty()) return false;
        auto p = stack.back();
        stack.pop_back();
        if (!((p == '{' && c == '}') || (p == '(' && c == ')') ||
              (p == '[' && c == ']'))) {
          return false;
        }
      }
    }
    if (stack.size() != 0) {
      return false;
    }
    return true;
  }
};
