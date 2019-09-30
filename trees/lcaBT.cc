#include<iostream>
  #include<vector>
  #include<bits/stdc++.h>
  using namespace std;
  
  // TreeNode class for a node of a Binary Search Tree
  class TreeNode {
      public:
  	  int val;
  	  TreeNode* left;
  	  TreeNode* right;
  
  	  TreeNode(int x) {
  	  	  val = x;
          left = NULL;
          right = NULL;
  	  }
  };
  
  // utility function to display a binary tree
  void display(TreeNode* node) {
      if (node == NULL) {
          return;
      }
      string str = "";
  
      str += node->left == NULL ? "." : to_string(node->left->val);
      str += " <= " + to_string(node->val) + " => ";
      str += node->right == NULL ? "." : to_string(node->right->val);
  
      cout<<str<<endl;
  
      display(node->left);
      display(node->right);
  }
  
  class BinaryTree {
      public:
      
      bool getPath(TreeNode* root, vector<TreeNode*>& v, int key) {
    if (root == NULL) return false;

    v.push_back(root);
    if (root->val == key) return true;
    if (getPath(root->left, v, key)) return true;
    if (getPath(root->right, v, key)) return true;
    v.pop_back();
    return false;
}
      
  	  TreeNode* lca(TreeNode* root, int x, int y) {
  	  	  // Write your code here.
        vector<TreeNode*> x_path, y_path;
    bool xPresence =  getPath(root, x_path, x);
    bool yPresence =  getPath(root, y_path, y);

    if (!xPresence or !yPresence) return NULL;

    int i = 0, j = 0;
    while (i < x_path.size() && j < y_path.size() && x_path[i] == y_path[j]) {
        ++i;
        ++j;
    }

    return x_path[i - 1];
  	  }
  
  };
  
  TreeNode* child;
  
  int main(int argc, char** argv){
      unordered_map<int, TreeNode*> map;
      int n ;
      cin>>n;
      TreeNode* root = NULL;
      for (int i = 0; i < n; i++) {
          TreeNode* parent = NULL;
          int n1, n2;
          cin>>n1>>n2;
          char c;
          cin>>c;
          if (map.find(n1) == map.end()) {
              parent = new TreeNode(n1);
              map[n1] = parent;
              if (root == NULL)
                  root = parent;
          } else
              parent = map[n1];
  
          child = new TreeNode(n2);
          if (c == 'L')
              parent->left = child;
          else
              parent->right = child;
          map[n2] =  child;
      }
      int firstNode, secondNode;
      cin>>firstNode>>secondNode;
  
      BinaryTree bt;
      TreeNode* lca = bt.lca(root, firstNode, secondNode);
      cout<<lca->val;
  
  }