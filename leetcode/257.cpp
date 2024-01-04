// Given the root of a binary tree, return all root-to-leaf paths in any order.

// A leaf is a node with no children.

//

// Example 1:

// Input: root = [1,2,3,null,5]
// Output: ["1->2->5","1->3"]
// Example 2:

// Input: root = [1]
// Output: ["1"]
//
// explanation:
// 1.we use recursion to traverse the tree.
// 2.while traversing we keep on adding the node value to the string.
// 3.when we reach the leaf node we add the string to the vector.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  TreeNode *helper(TreeNode *root, string str, vector<string> &ans) {
    if (root == NULL) {
      return NULL;
    }
    str += "->" + std::to_string(root->val);
    TreeNode *leftSide = helper(root->left, str, ans);
    TreeNode *rightSide = helper(root->right, str, ans);

    if (leftSide == NULL && rightSide == NULL) {
      ans.push_back(str);
    }
    return root;
  }

public:
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> ans;
    if (root == NULL) {
      return ans;
    } else if (root->left == NULL && root->right == NULL) {
      ans.push_back(std::to_string(root->val));
      return ans;
    }
    string str = "";
    str += std::to_string(root->val);
    helper(root->left, str, ans);
    helper(root->right, str, ans);
    return ans;
  }
};
