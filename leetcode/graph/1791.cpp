#include <unordered_map>
#include <vector>
class Solution {
public:
  int findCenter(std::vector<std::vector<int>> &edges) {
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
      return edges[0][0];
    }
    return edges[0][1];
  };
};

// previous attempt - 04:02
// #include <unordered_map>
// #include <vector>
// class Solution {
// public:
//   int findCenter(std::vector<std::vector<int>> &edges) {
//     std::unordered_map<int, int> um;
//     for (int i = 0; i < edges.size(); i++) {
//       for (int j = 0; j < edges[i].size(); j++) {
//         um[edges[i][j]]++;
//       }
//     }
//     int n = um.size();
//     for (auto p : um) {
//       if (p.second == n - 1) {
//         return p.first;
//       }
//     }
//     return -1;
//   }
// };
