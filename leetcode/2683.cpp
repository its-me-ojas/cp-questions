#include <vector>
class Solution {
public:
  bool doesValidArrayExist(std::vector<int> &derived) {
    int sum = 0;
    for (const auto n : derived) {
      sum ^= n;
    }
    return sum == 0 ? true : false;
  }
};
