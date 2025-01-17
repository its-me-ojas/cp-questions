#include <vector>
class Solution {
public:
  std::vector<int> decrypt(std::vector<int> &code, int k) {
    if (k == 0) {
      for (int i = 0; i < code.size(); i++) {
        code[i] = 0;
      }
    } else if (k > 0) {
      // sum of next k elements
      for (int i = 0; i < code.size(); i++) {
        int sum = 0;
        for (int j = 1; j <= k; j++) {
          sum += code[(i + j) % code.size()];
        }
        code[i] = sum;
      }
    } else {
      // sum of prev k elements
      for (int i = 0; i < code.size(); i++) {
        int sum = 0;
        for (int j = 1; j <= -k; j++) {
          sum += code[(i - j + code.size()) % code.size()];
        }
        code[i] = sum;
      }
    }
    return code;
  }
};
