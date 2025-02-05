#include <unordered_map>
#include <unordered_set>
#include <vector>
class Solution {
public:
  std::vector<int>
  findSmallestSetOfVertices(int n, std::vector<std::vector<int>> &edges) {
    std::unordered_set<int> us;
    for (int i = 0; i < edges.size(); i++) {
      us.insert(edges[i][1]);
    }
    std::vector<int> res;
    for (int i = 0; i < n; i++) {
      if (us.find(i) == us.end())
        res.push_back(i);
    }
    return res;
  }
};
