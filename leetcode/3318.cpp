#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
class Solution {
public:
  int xSum(std::unordered_map<int, int> freq, int x) {
    // making a max heap
    std::priority_queue<std::pair<int, int>> mh;
    for (auto const p : freq) {
      mh.push({p.second, p.first});
    }
    auto sum = 0;
    while (!mh.empty() && x) {
      auto p = mh.top();
      mh.pop();
      sum += p.first * p.second;
      x--;
    }
    return sum;
  }
  std::vector<int> findXSum(std::vector<int> &nums, int k, int x) {
    std::vector<int> ans;
    std::unordered_map<int, int> um;
    for (int z = 0; z < k; z++) {
      um[nums[z]]++;
    }
    ans.push_back(xSum(um, x));
    for (int i = 1; i + k <= nums.size(); i++) {
      um[nums[i - 1]]--;
      um[nums[i + k - 1]]++;
      ans.push_back(xSum(um, x));
    }
    return ans;
  }
};
