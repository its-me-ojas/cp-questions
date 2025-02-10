#include <algorithm>
#include <stack>
#include <string>
class Solution {
public:
  std::string clearDigits(std::string s) {
    std::stack<char> stk;
    for (auto c : s) {
      if (isdigit(c)) {
        if (!stk.empty() && !isdigit(stk.top())) {
          stk.pop();
        }
      } else {
        stk.push(c);
      }
    }
    std::string res;
    while (!stk.empty()) {
      res += stk.top();
      stk.pop();
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};
