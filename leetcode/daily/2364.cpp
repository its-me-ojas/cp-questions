#include <unordered_map>
#include <vector>
class Solution {
public:
  long long countBadPairs(std::vector<int> &nums) {
    long long badPairs = 0;
    std::unordered_map<int, int> um;
    for (int i = 0; i < nums.size(); i++) {
      um[i] = nums[i] - i;
    }
    for (int i = 0; i < nums.size(); i++) {
      um[i] = nums[i] - i;
    }
    return badPairs;
  }
};
