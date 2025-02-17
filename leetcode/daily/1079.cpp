#include <string>
#include <unordered_set>
#include <vector>
class Solution {
public:
  void generateSequences(std::string tiles,
                         std::unordered_set<std::string> &sequences,
                         std::vector<bool> &used, std::string current) {
    sequences.insert(current);

    for (int pos = 0; pos < tiles.length(); pos++) {
      if (!used[pos]) {
        used[pos] = true;
        generateSequences(tiles, sequences, used, current + tiles[pos]);
        used[pos] = false;
      }
    }
  }
  int numTilePossibilities(std::string tiles) {
    std::unordered_set<std::string> sequences;
    std::vector<bool> used(tiles.size(), false);

    generateSequences(tiles, sequences, used, "");

    return sequences.size() - 1;
  }
};
