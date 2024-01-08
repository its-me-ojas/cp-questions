// Given the root node of a binary search tree and two integers low and high,
// return the sum of values of all nodes with a value in the inclusive range
// [low, high].
// Example 1:
// Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
// Output: 32
// Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
// Example 2:
// Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
// Output: 23
// Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// explanation:
// we will traverse the tree and check if the node value is in the range or not.
// if it is in the range then we will add it to the count.
// if the node value is equal to the high value then we will traverse the left
// subtree. if the node value is equal to the low value then we will traverse
// the right subtree. if the node value is not equal to either high or low then
// we will traverse both the subtrees.

class Solution {
public:
  void helper(TreeNode *root, int low, int high, int &count) {
    if (root == NULL) {
      return;
    }
    if (root->val >= low && root->val <= high) {
      count += root->val;
    }

    if (root->val == high) {
      helper(root->left, low, high, count);
    } else if (root->val == low) {
      helper(root->right, low, high, count);
    } else {
      helper(root->left, low, high, count);
      helper(root->right, low, high, count);
    }
  }
  int rangeSumBST(TreeNode *root, int low, int high) {
    int count = 0;
    helper(root, low, high, count);
    return count;
  }
};
