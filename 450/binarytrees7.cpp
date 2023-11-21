// postorderTraversal
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left),
   right(right) {}
    };
*/
vector<int> postorderTraversal(TreeNode *root) {
  // Write your code here.
  vector<int> result;
  stack<TreeNode *> stack;
  stack.push(root);

  stack<TreeNode *> output;

  while (!stack.empty()) {
    TreeNode *curr = stack.top();
    stack.pop();

    output.push(curr->data);
    if (curr->left) {
      stack.push(curr->left);
    }
    if (curr->right) {
      stack.push(curr->right);
    }
  }

  while (!output.empty()) {
    result.push_back(output.top());
    output.pop();
  }
  return result;
}
