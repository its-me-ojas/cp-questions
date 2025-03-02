#include <vector>
class Solution {
public:
  std::vector<int> applyOperations(std::vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      if (nums[i] == nums[i + 1]) {
        nums[i] = 2 * nums[i];
        nums[i + 1] = 0;
      }
    }
    std::vector<int> res;
    int c = 0;
    for (auto n : nums) {
      if (n != 0) {
        c++;
        res.push_back(n);
      }
    }
    c = n - c;
    while (c != 0) {
      res.push_back(0);
      c--;
    }
    return res;
  }
};
