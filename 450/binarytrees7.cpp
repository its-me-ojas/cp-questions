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
  if (root == NULL) {
    return {};
  }
  vector<int> result;
  stack<TreeNode *> s;
  s.push(root);

  stack<int> output;

  while (!s.empty()) {
    TreeNode *curr = s.top();
    s.pop();

    output.push(curr->data);
    if (curr->left) {
      s.push(curr->left);
    }
    if (curr->right) {
      s.push(curr->right);
    }
  }

  while (!output.empty()) {
    result.push_back(output.top());
    output.pop();
  }
  return result;
}
