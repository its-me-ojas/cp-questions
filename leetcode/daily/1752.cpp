#include <cstdlib>
#include <vector>
class Solution {
public:
  bool check(std::vector<int> &nums) {
    int rotationPoint = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i + 1] < nums[i]) {
        rotationPoint++;
      }
    }
    if (rotationPoint > 1)
      return false;
    if (rotationPoint == 1)
      return nums[nums.size() - 1] <= nums[0];
    return true;
  };
};
