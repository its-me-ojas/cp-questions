// Given an integer array nums, return the length of the longest strictly
// increasing subsequence
// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
// length is 4. Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1

// explanation:
// first we create a vector ans and push the first element of nums in it
// then we iterate over the nums vector and check if the current element is
// greater than the last element of ans if it is then we push it in ans else we
// find the lower bound of the current element in ans and replace it with the
// current element
// we return the size of ans

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    vector<int> ans;
    ans.push_back(nums[0]);

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > ans.back()) {
        ans.push_back(nums[i]);
      } else {
        int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
        ans[index] = nums[i];
      }
    }
    return ans.size();
  }
};
