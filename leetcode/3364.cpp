#include <algorithm>
#include <vector>
#include <climits>

class Solution {
public:
  int sumOfSubArray(const std::vector<int>& temp, int i, int window) {
    int sum = 0;
    for (int j = i; j <= window; j++) {
      sum += temp[j];
    }
    return sum;
  }

  int minimumSumSubarray(std::vector<int> &nums, int l, int r) {
    int mini = INT_MAX;
    int n = nums.size();

    for (int i = 0; i <= n - l; i++) {
      for (int window = i + l - 1; window < n && window <= i + r - 1; window++) {
        int sum = sumOfSubArray(nums, i, window);
        if (sum > 0) {
          mini = std::min(sum, mini);
        }
      }
    }

    return (mini == INT_MAX) ? -1 : mini;
  }
};
