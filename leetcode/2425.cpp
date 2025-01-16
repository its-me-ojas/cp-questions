#include <vector>
class Solution {
public:
  int xorAllNums(std::vector<int> &nums1, std::vector<int> &nums2) {
    int xor1 = 0;
    int xor2 = 0;
    // first xor
    for (int i = 0; i < nums1.size(); i++) {
      xor1 ^= nums1[i];
    }
    // second xor
    for (int i = 0; i < nums2.size(); i++) {
      xor2 ^= nums2[i];
    }
    int result = 0;
    for (int i = 0; i < nums2.size(); i++) {
      result ^= xor1;
    }
    for (int i = 0; i < nums1.size(); i++) {
      result ^= xor2;
    }

    return result;
  };
};
