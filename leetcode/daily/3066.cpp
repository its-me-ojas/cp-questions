#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
class Solution {
public:
  int minOperations(std::vector<int> &nums, int k) {
    std::priority_queue<long long, std::vector<long long>,
                        std::greater<long long>>
        minHeap;

    for (auto n : nums) {
      minHeap.push(static_cast<long long>(n));
    }

    int count = 0;
    while (minHeap.size() >= 3 && minHeap.top() < k) {
      int a = minHeap.top();
      minHeap.pop();
      int b = minHeap.top();
      minHeap.pop();
      minHeap.push(std::min(a, b) * 2LL + std::max(a, b));
      count++;
    }
    return minHeap.top() >= k ? count : -1;
  }
};

int main() {
  std::vector<int> nums = {2, 11, 10, 1, 3};
  int k = 10;
  Solution sol;
  int res = sol.minOperations(nums, k);
  std::cout << res << std::endl;
  return 0;
}
