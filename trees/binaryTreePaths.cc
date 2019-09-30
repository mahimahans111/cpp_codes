#include<iostream>
  #include<vector>
  #include<string>
  #include<bits/stdc++.h>
  #include<deque>
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
  
  //Don't change code of utility function.
  TreeNode* stringToTreeNode(string input) {
      int first = input.find_first_not_of(' ');
      int last = input.find_last_not_of(' ');
      input = input.substr(first, (last - first + 1));
      if (!input.size()) {
          return nullptr;
      }
  
      string item;
      stringstream ss;
      ss.str(input);
  
      getline(ss, item, ' ');
      TreeNode* root = new TreeNode(stoi(item));
      queue<TreeNode*> nodeQueue;
      nodeQueue.push(root);
  
      while (true) {
          TreeNode* node = nodeQueue.front();
          nodeQueue.pop();
          if (!getline(ss, item, ' ')) {
              break;
          }
  
          if (item != "null") {
              int leftNumber = stoi(item);
              node->left = new TreeNode(leftNumber);
              nodeQueue.push(node->left);
          }
  
          if (!getline(ss, item, ' ')) {
              break;
          }
  
          if (item != "null") {
              int rightNumber = stoi(item);
              node->right = new TreeNode(rightNumber);
              nodeQueue.push(node->right);
          
          }
      }
      return root;
  }
  
  // This is a functional problem. You have to complete this function.
  // It takes as input the root node of a binary tree. It should return 
  // an arraylist containing all root-to-leaf paths in any order.
  
  void bPaths(TreeNode*root, vector<string> &ans, vector<int> &vol){
     if(root && root->left == NULL && root->right == NULL){
          string a = "";
          for(int k = 0; k < vol.size(); k++){
              string temp = to_string(vol[k]);
              a+=temp;
              a+='-';
              a+='>';
          }
          a+=to_string(root->val);
          ans.push_back(a);
     }
      
      vol.push_back(root->val);
      if(root->left)bPaths(root->left, ans, vol);
      if(root->right)bPaths(root->right, ans, vol);
      vol.pop_back();
  }
  
  vector<string> binaryTreePaths(TreeNode* root) {
      // write your code here.
      vector<string> ans;
      vector<int> vol;
      bPaths(root, ans, vol);
      return ans;
  }
  
  int main(int argc, char** argv){
      string line;
      getline(cin, line);
      TreeNode* root = stringToTreeNode(line);
      vector<string> result = binaryTreePaths(root);
  	  sort(result.begin(), result.end());
  	  for(string s: result){
  	  	  cout<<s<<endl;
  	  }
      return 0;
  }