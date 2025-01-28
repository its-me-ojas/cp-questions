#include <unordered_map>
#include <vector>
class Solution {
public:
  int numberOfSubarrays(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> um;
    int current_sum = 0, count = 0;
    um[0] = 1;
    for (const auto n : nums) {
      current_sum += (n % 2 == 0) ? 0 : 1;

      if (um.find(current_sum - k) != um.end()) {
        count += um[current_sum - k];
      }

      um[current_sum]++;
    }
    return count;
  };
