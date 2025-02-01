#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool helper(std::vector<std::vector<char>> &map, std::string &moves, int i,
            int j) {
  int m = map.size(), n = map[0].size();

  if (i < 0 || j < 0 || i >= m || j >= n || map[i][j] == '#')
    return false;

  if (map[i][j] == 'B')
    return true;

  map[i][j] = '#';

  if (helper(map, moves, i - 1, j)) {
    moves += "U";
    return true;
  }
  if (helper(map, moves, i + 1, j)) {
    moves += "D";
    return true;
  }
  if (helper(map, moves, i, j - 1)) {
    moves += "L";
    return true;
  }
  if (helper(map, moves, i, j + 1)) {
    moves += "R";
    return true;
  }

  return false;
}

int main() {
  int m, n;
  std::cin >> m >> n;

  std::vector<std::vector<char>> map(m, std::vector<char>(n));
  std::pair<int, int> A, B;

  // Taking input and finding A and B
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> map[i][j];
      if (map[i][j] == 'A')
        A = {i, j};
      if (map[i][j] == 'B')
        B = {i, j};
    }
  }

  std::string moves = "";
  if (helper(map, moves, A.first, A.second)) {
    std::cout << "YES\n";
    std::cout << moves.size() << '\n';
    std::reverse(moves.begin(), moves.end());
    std::cout << moves << '\n';
  } else {
    std::cout << "NO\n";
  }

  return 0;
}
