// The diameter of a tree (sometimes called the width) is the number of nodes on
// the longest path between two end nodes. The diagram below shows two trees
// each with diameter nine, the leaves that form the ends of the longest path
// are shaded (note that there is more than one path in each tree of length
// nine, but no path longer than nine nodes).

// Example 1:

// Input:
//        1
//      /  \
//     2    3
// Output: 3
// Example 2:

// Input:
//          10
//         /   \
//       20    30
//     /   \ 
//    40   60
// Output: 4
// Your Task:
// You need to complete the function diameter() that takes root as parameter and
// returns the diameter.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 1 <= Number of nodes <= 10000
// 1 <= Data of a node <= 1000
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};
Node *newNode(int val) {
  Node *temp = new Node;
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}
Node *buildTree(string str) {
  // Corner Case
  if (str.length() == 0 || str[0] == 'N')
    return NULL;

  // Creating vector of strings from input
  // string after spliting by space
  vector<string> ip;

  istringstream iss(str);
  for (string str; iss >> str;)
    ip.push_back(str);

  // Create the root of the tree
  Node *root = newNode(stoi(ip[0]));

  // Push the root to the queue
  queue<Node *> queue;
  queue.push(root);

  // Starting from the second element
  int i = 1;
  while (!queue.empty() && i < ip.size()) {

    // Get and remove the front of the queue
    Node *currNode = queue.front();
    queue.pop();

    // Get the current node's value from the string
    string currVal = ip[i];

    // If the left child is not null
    if (currVal != "N") {

      // Create the left child for the current node
      currNode->left = newNode(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->left);
    }

    // For the right child
    i++;
    if (i >= ip.size())
      break;
    currVal = ip[i];

    // If the right child is not null
    if (currVal != "N") {

      // Create the right child for the current node
      currNode->right = newNode(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->right);
    }
    i++;
  }

  return root;
}

// } Driver Code Ends
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// APPROACH
// This is an optimized version of finding the diameter of a binary tree, here
// instead of taking the height and calling another function we are passing both
// height and diamter in one go using pairs
//
class Solution {
public:
  // Function to return the diameter of a Binary Tree.
  pair<int, int> diameterFast(Node *root) {
    if (root == NULL) {
      pair<int, int> p = {0, 0};
      return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int leftDiameter = left.first;
    int rightDiameter = right.first;
    int height = left.second + 1 + right.second;

    pair<int, int> ans = {max(leftDiameter, max(rightDiameter, height)),
                          max(left.second, right.second) + 1};

    return ans;
  }
  int diameter(Node *root) {
    // Your code here
    return diameterFast(root).first;
  }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
  int t;
  scanf("%d\n", &t);
  while (t--) {
    string s;
    getline(cin, s);
    Node *root = buildTree(s);
    Solution ob;
    cout << ob.diameter(root) << endl;
  }
  return 0;
}

// } Driver Code Ends
