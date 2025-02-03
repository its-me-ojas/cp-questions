#include <algorithm>
#include <cstdlib>
#include <vector>
class Solution {
public:
  int longestMonotonicSubarray(std::vector<int> &nums) {
    int increasing = 0;
    int decreasing = 0;
    int maxIncreasing = 0;
    int maxDecreasing = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      increasing = 0;
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[j] > nums[j - 1]) {
          increasing++;
        } else {
          break;
        }
      }
      maxIncreasing = std::max(maxIncreasing, increasing);
    }
    for (int i = 0; i < nums.size() - 1; i++) {
      decreasing = 0;
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[j] < nums[j - 1]) {
          decreasing++;
        } else {
          break;
        }
      }
      maxDecreasing = std::max(maxDecreasing, decreasing);
    }
    return std::max(maxIncreasing, maxDecreasing) + 1;
  }
};
