#include <algorithm>
#include <vector>

class Solution {
public:
  int maxAscendingSum(std::vector<int> &nums) {
    int maxSum = nums[0];

    for (int i = 0; i < nums.size(); i++) {
      int sum = nums[i];
      int j = i;
      while (j + 1 < nums.size() && nums[j + 1] > nums[j]) {
        sum += nums[j + 1];
        j++;
      }
      maxSum = std::max(maxSum, sum);
      i = j;
    }

    return maxSum;
  }
};
