
// Explanation:
// first sort the two array
// then use two pointer to traverse the two array
// if the value of s[index] >= g[cnt] then cnt++
// else index++
// return cnt
// Time complexity: O(nlogn)
// Space complexity: O(1)

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    if (g.size() == 0 || s.size() == 0)
      return 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int index = 0, cnt = 0;
    while (index < s.size() && cnt < g.size()) {
      if (s[index] >= g[cnt])
        cnt++;
      index++;
    }
    return cnt;
  }
};
