#include <algorithm>
#include <stack>
#include <string>
class Solution {
public:
  std::string removeOccurrences(std::string s, std::string part) {
    std::stack<char> stk;
    for (int i = 0; i < s.size(); i++) {
      stk.push(s[i]);
      if (stk.size() >= part.size()) {
        std::string temp;
        for (int j = 0; j < part.size(); j++) {
          temp += stk.top();
          stk.pop();
        }
        std::reverse(temp.begin(), temp.end());
        if (temp != part) {
          for (int j = 0; j < temp.size(); j++) {
            stk.push(temp[j]);
          }
        }
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

// #include <string>
// class Solution {
// public:
//   std::string removeOccurrences(std::string s, std::string part) {
//     std::string stk;
//     int n = part.size();
//     char endChar = part.back();
//     for (auto c : s) {
//       stk.push_back(c);
//       if (stk.size() >= n && stk.back() == endChar) {
//         if (stk.substr(stk.size() - n) == part) {
//           stk.resize(stk.size() - n);
//         }
//       }
//     }
//     return stk;
//   }
// };
