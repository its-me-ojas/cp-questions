#include <bits/stdc++.h>
/*
Following is the structure of Tree Node

class TreeNode
{
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
*/

vector<int> preorderTraversal(TreeNode *root) {
  // Write your code here
  vector<int> result;
  stack<TreeNode *> stack;
  TreeNode *curr = root;

  while (!stack.empty() || curr != NULL) {
    if (curr != NULL) {
      result.push_back(curr->val);
      stack.push(curr);
      curr = curr->left;
    } else {
      curr = stack.top();
      stack.pop();
      curr = curr->right;
    }
  }
  return result;
}
