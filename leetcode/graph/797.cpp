#include <vector>
class Solution {
public:
  void helperFunction(const std::vector<std::vector<int>> &graph,
                      std::vector<std::vector<int>> &res,
                      std::vector<int> &path, int node) {
    path.push_back(node);
    if (node == graph.size() - 1) {
      res.push_back(path);
      path.pop_back();
      return;
    }
    for (auto n : graph[node]) {
      helperFunction(graph, res, path, n);
    }
    path.pop_back();
  }

  std::vector<std::vector<int>>
  allPathsSourceTarget(std::vector<std::vector<int>> &graph) {
    std::vector<std::vector<int>> res;
    std::vector<int> path;
    helperFunction(graph, res, path, 0);
    return res;
  }
};
