// #include <map>
// #include <vector>
// using namespace std;

// class Solution {
// public:
//   vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,
//                                   vector<vector<int>> &nums2) {
//     map<int, int> um;
//     int maxId = 0;
//     for (auto v : nums1) {
//       um[v[0]] += v[1];
//     }
//     for (auto v : nums2) {
//       um[v[0]] += v[1];
//     }
//     vector<vector<int>> res;
//     // for (int i = 1; i <= maxId; i++) {
//     //   if (um.find(i) != um.end())
//     //     res.push_back({i, um[i]});
//     // }
//     for (auto p : um) {
//       res.push_back({p.first, p.second});
//     }
//     return res;
//   };
// };
#include <vector>
class Solution {
public:
  std::vector<std::vector<int>>
  mergeArrays(std::vector<std::vector<int>> &nums1,
              std::vector<std::vector<int>> &nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int temp1 = 0, temp2 = 0;
    std::vector<std::vector<int>> res;

    while (temp1 < n1 && temp2 < n2) {
      if (nums1[temp1][0] == nums2[temp2][0]) {
        res.push_back({nums1[temp1][0], nums1[temp1][1] + nums2[temp2][1]});
        temp1++;
        temp2++;
      } else if (nums1[temp1][0] < nums2[temp2][0]) {
        res.push_back({nums1[temp1][0], nums1[temp1][1]});
        temp1++;
      } else {
        res.push_back({nums2[temp2][0], nums2[temp2][1]});
        temp2++;
      }
    }
    while (temp1 < n1) {
      res.push_back({nums1[temp1][0], nums1[temp1][1]});
      temp1++;
    }
    while (temp2 < n2) {
      res.push_back({nums2[temp2][0], nums2[temp2][1]});
      temp2++;
    }
    return res;
  }
};
