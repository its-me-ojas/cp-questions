#include <string>
#include <unordered_map>
class Solution {
public:
  bool areAlmostEqual(std::string s1, std::string s2) {
    if (s1 == s2)
      return true;
    if (s1.size() == 2) {
      return s1[0] == s2[1] && s1[1] == s2[0];
    }
    std::unordered_map<char, int> um;
    for (auto c : s1) {
      um[c]++;
    }
    for (auto c : s2) {
      um[c]--;
    }
    for (auto p : um) {
      if (p.second != 0) {
        return false;
      }
    }
    int count = 0;
    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] != s2[i])
        count++;
    }
    return count > 2 ? false : true;
  }
};
