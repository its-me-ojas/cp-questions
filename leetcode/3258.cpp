#include <string>
class Solution {
public:
  int countKConstraintSubstrings(std::string s, int k) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
      int count0 = 0, count1 = 0;
      for (int j = i; j < s.size(); j++) {
        if (s[j] == '0') {
          count0++;
        } else {
          count1++;
        }
        // after this you will get the freq count of the substring
        if (count0 <= k || count1 <= k) {
          count++;
        }
      }
    }
    return count;
  }
};
