#include <algorithm>
#include <climits>
#include <map>
#include <vector>
class Solution {
public:
  int digitsSum(int n) {
    int sum = 0;
    while (n) {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }
  int maximumSum(std::vector<int> &nums) {
    std::map<int, std::vector<int>> digitSumMap;

    for (int num : nums) {
      int digitSum = digitsSum(num);
      digitSumMap[digitSum].push_back(num);
    }

    int maxSum = -1;
    for (auto &pair : digitSumMap) {
      auto &numbers = pair.second;
      if (numbers.size() >= 2) {
        std::sort(numbers.begin(), numbers.end(), std::greater<int>());
        maxSum = std::max(maxSum, numbers[0] + numbers[1]);
      }
    }

    return maxSum;
  }
};
