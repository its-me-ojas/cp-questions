#include <algorithm>
#include <vector>
class Solution {
public:
  int maxFishFromThisCell(std::vector<std::vector<int>> &grid, int i, int j,
                          int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
      return 0;
    }

    int fish = grid[i][j];
    grid[i][j] = 0;

    int upFish = maxFishFromThisCell(grid, i - 1, j, m, n);
    int downFish = maxFishFromThisCell(grid, i + 1, j, m, n);
    int leftFish = maxFishFromThisCell(grid, i, j - 1, m, n);
    int rightFish = maxFishFromThisCell(grid, i, j + 1, m, n);

    // grid[i][j] = fish;

    return fish + upFish + downFish + leftFish + rightFish;
  }

  int findMaxFish(std::vector<std::vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int maxFish = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] != 0) {
          int fishFromThisCell = maxFishFromThisCell(grid, i, j, m, n);
          maxFish = std::max(maxFish, fishFromThisCell);
        }
      }
    }
    return maxFish;
  }
};
