#include <iostream>
#include <vector>
class Solution {
public:
  bool backtrack(std::vector<int> &res, std::vector<bool> &used, int pos,
                 int n) {
    if (pos >= res.size())
      return true;
    if (res[pos] != 0)
      return backtrack(res, used, pos + 1, n);
    for (int i = n; i > 0; i--) {
      if (!used[i]) {
        if (i == 1) {
          res[pos] = i;
          used[i] = true;
          if (backtrack(res, used, pos + 1, n))
            return true;
          res[pos] = 0;
          used[i] = false;
        } else if (pos + i < res.size() && res[pos + i] == 0) {
          res[pos] = i;
          res[pos + i] = i;
          used[i] = true;
          if (backtrack(res, used, pos + 1, n))
            return true;
          res[pos] = 0;
          res[pos + i] = 0;
          used[i] = false;
        }
      }
    }
    return false;
  }

  std::vector<int> constructDistancedSequence(int n) {
    std::vector<int> res(2 * n - 1, 0);
    std::vector<bool> used(n + 1, false);
    backtrack(res, used, 0, n);

    return res;
  }
};

int main() {
  Solution sol;
  std::vector<int> res = sol.constructDistancedSequence(5);
  for (int i = 0; i < res.size(); i++) {
    std::cout << res[i] << " ";
  }
  return 0;
}
