
// Explanation
// 1. Create a frequency array
// 2. Iterate over the array and push the element to the frequency index
// 3. If the frequency is greater than the size of the result array, push an
// empty vector to the result array
// 4. Push the element to the frequency index of the result array
// 5. Increment the frequency of the element
// 6. Return the result array

class Solution {
public:
  vector<vector<int>> findMatrix(vector<int> &nums) {
    vector<int> frequency(nums.size() + 1);

    vector<vector<int>> result;
    for (int num : nums) {
      if (frequency[num] >= result.size()) {
        result.push_back({});
      }

      result[frequency[num]].push_back(num);
      frequency[num]++;
    }

    return result;
  }
};
