// Given the roots of two binary trees p and q, write a function to check if
// they are the same or not.

// Two binary trees are considered the same if they are structurally identical,
// and the nodes have the same value.

//

// Example 1:

// Input: p = [1,2,3], q = [1,2,3]
// Output: true
// Example 2:

// Input: p = [1,2], q = [1,null,2]
// Output: false
// Example 3:

// Input: p = [1,2,1], q = [1,1,2]
// Output: false
//

// Constraints:

// The number of nodes in both trees is in the range [0, 100].
// -104 <= Node.val <= 104

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
class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    // if (!p && !q): This checks if both p and q are NULL (or nullptr in C++).
    // If both trees are empty at the current level, it means they are the same,
    // so the function returns true.

    // if (!p || !q): This checks if either p or q is NULL. If only one of them
    // is NULL while the other is not, it means the trees are different, so the
    // function returns false.
    if (!p && !q) {
      return true;
    }
    if (!p || !q) {
      return false;
    }

    if (p->val != q->val) {
      return false;
    }

    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);

    return left && right;
  }
};
