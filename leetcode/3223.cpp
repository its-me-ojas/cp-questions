#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
class Solution {
public:
  int minimumLength(std::string s) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::unordered_map<char, int> um;
    for (int i = 0; i < s.size(); i++) {
      um[s[i]]++;
    }
    for (auto p : um) {
      std::cout << p.first << " " << p.second << std::endl;
    }
    int sum = 0;
    for (auto it = um.begin(); it != um.end(); it++) {
      if (it->second <= 2) {
        sum += it->second;
      } else if (it->second % 2 == 0) {
        sum += 2;
      } else {
        sum += 1;
      }
    }
    return sum;
  };
};

int main() {
  Solution s;
  std::string str = "ucvbutgkohgbcobqeyqwppbxqoynxeuuzouyvmydfhrprdbuzwqebwuiej"
                    "oxsxdhbmuaiscalnteocghnlisxxawxgcjloevrdcj";
  std::cout << s.minimumLength(str) << std::endl;
  return 0;
}
