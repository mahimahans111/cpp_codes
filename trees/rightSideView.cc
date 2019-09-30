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
  // It takes as input the root node of the given tree. It should return the required arraylist. 

  
  vector<int> rightSideView(TreeNode* node) {
      // write your code here.
      vector<int> ans;
       queue<TreeNode*> q;
      q.push(node);
      while(q.size()>0){
          int cnt = q.size();
          while(cnt--){
              TreeNode*t = q.front();
              if(cnt == 0)ans.push_back(t->val);
              q.pop();
              
              if(t->left)q.push(t->left);
              if(t->right)q.push(t->right);
          }
      }
      return ans;
  }
  
  int main(int argc, char** argv){
      string line;
      getline(cin, line);
      TreeNode* root = stringToTreeNode(line);
      vector<int> result = rightSideView(root);
  	  for(int i: result){
  	  	  cout<<i<<" ";
  	  }
      cout<<endl;
      return 0;
  }