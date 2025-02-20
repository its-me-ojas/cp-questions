#include <bitset>
#include <cmath>
#include <string>
#include <unordered_map>
#include <vector>
class Solution {
public:
  std::string findDifferentBinaryString(std::vector<std::string> &nums) {
    std::unordered_map<int, int> um;
    int n = nums[0].size();

    for (auto &num : nums) {
      um[std::stoi(num, nullptr, 2)]++;
    }

    for (int i = 0; i < (1 << n); i++) {
      if (um.find(i) == um.end()) {
        return std::bitset<16>(i).to_string().substr(16 - n);
      }
    }

    return "";
  }
};
