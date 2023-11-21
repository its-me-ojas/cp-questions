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
vector<int> preOrder(TreeNode *root) {
  vector<int> result;
  stack<TreeNode *> stack;
  TreeNode *curr = root;

  while (!stack.empty() || curr != NULL) {
    if (curr != NULL) {
      result.push_back(curr->data);
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

vector<int> inOrder(TreeNode *root) {
  vector<int> result;
  stack<TreeNode *> stack;
  TreeNode *curr = root;

  while (!stack.empty() || curr != NULL) {
    if (curr != NULL) {
      stack.push(curr);
      curr = curr->left;
    } else {
      curr = stack.top();
      stack.pop();
      result.push_back(curr->data);
      curr = curr->right;
    }
  }
  return result;
}

vector<int> postOrder(TreeNode *root) {
  if (root == NULL) {
    return {};
  }
  vector<int> result;
  stack<TreeNode *> s;
  s.push(root);

  stack<int> out;

  while (!s.empty()) {
    TreeNode *curr = s.top();
    s.pop();

    out.push(curr->data);

    if (curr->left) {
      s.push(curr->left);
    }

    if (curr->right) {
      s.push(curr->right);
    }
  }

  while (!out.empty()) {
    result.push_back(out.top());
    out.pop();
  }
  return result;
}

vector<vector<int>> getTreeTraversal(TreeNode *root) {
  // Write your code here.
  vector<int> INORDER = inOrder(root);
  vector<int> PREORDER = preOrder(root);
  vector<int> POSTORDER = postOrder(root);

  vector<vector<int>> result;
  result.push_back(INORDER);
  result.push_back(PREORDER);
  result.push_back(POSTORDER);

  return result;
}
