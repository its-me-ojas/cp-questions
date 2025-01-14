#include <iostream>
#include <unordered_map>
#include <vector>
class Solution {
public:
  std::vector<int> findThePrefixCommonArray(std::vector<int> &A,
                                            std::vector<int> &B) {
    std::vector<int> ans;
    std::unordered_map<int, int> um;
    int common = 0;
    for (int i = 0; i < A.size(); i++) {
      um[A[i]]++;
      um[B[i]]++;
      if (A[i] == B[i]) {
        common++;
      } else {
        if (um[A[i]] == 2) {
          common++;
        }
        if (um[B[i]] == 2) {
          common++;
        }
      }

      ans.push_back(common);
    }
    return ans;
  }
};

int main() {
  Solution s;
  std::vector<int> A = {1, 3, 2, 4};
  std::vector<int> B = {3, 1, 2, 4};
  std::vector<int> ans = s.findThePrefixCommonArray(A, B);
  for (auto n : ans) {
    std::cout << n << " ";
  }
}
