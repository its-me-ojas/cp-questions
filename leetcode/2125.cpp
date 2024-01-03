// Anti-theft security devices are activated inside a bank. You are given a
// 0-indexed binary string array bank representing the floor plan of the bank,
// which is an m x n 2D matrix. bank[i] represents the ith row, consisting of
// '0's and '1's. '0' means the cell is empty, while'1' means the cell has a
// security device.

// There is one laser beam between any two security devices if both conditions
// are met:

// The two devices are located on two different rows: r1 and r2, where r1 < r2.
// For each row i where r1 < i < r2, there are no security devices in the ith
// row. Laser beams are independent, i.e., one beam does not interfere nor join
// with another.

// Return the total number of laser beams in the bank.

// Explanantion:
// first take a helper array and store the number of 1's in each row
// then iterate over the helper array and multiply the consecutive elements
// and add them to the conn variable

class Solution {
public:
  int numberOfBeams(vector<string> &bank) {
    int conn = 0;
    vector<int> helper;
    for (auto str : bank) {
      int count = 0;
      for (int i = 0; i < str.size(); i++) {
        if (str[i] == '1')
          count++;
      }
      if (count != 0)
        helper.emplace_back(count);
    }
    for (int i = 1; i < helper.size(); i++) {
      conn += helper[i - 1] * helper[i];
    }
    return conn;
  }
};

// can also be done using queue
class Solution {
public:
  int numberOfBeams(vector<string> &bank) {
    queue<int> q;
    int cnt = 0;

    for (auto str : bank) {
      int temp = 0;

      for (auto ch : str) {
        if (ch == '1')
          temp++;
      }
      if (q.size() == 1 && temp != 0) {
        cnt += q.front() * temp;
        q.pop();
        q.push(temp);
      } else if (temp != 0) {
        q.push(temp);
      }
    }

    return cnt;
  }
};
