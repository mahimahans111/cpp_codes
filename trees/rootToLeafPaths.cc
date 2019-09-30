#include<iostream>
  #include<vector>
  #include<string>
  #include<bits/stdc++.h>
  #include<unordered_map>
  using namespace std;
  
  // TreeNode class for a node of a Binary Search Tree
  class TreeNode {
      public:
  	  int data;
  	  TreeNode* left;
  	  TreeNode* right;
  
  	  TreeNode(int x) {
  	  	  data = x;
          left = NULL;
          right = NULL;
  	  }
  };
  
  class BinaryTree {
      public:
      
      void helper(TreeNode*root, vector<int> &ans){
          
          if(root && !root->left && !root->right){
              ans.push_back(root->data);
              for(int i = 0; i < ans.size(); i++){
                  cout << ans[i] << " ";
              }
              cout << "#";
              ans.pop_back();
              return;
          }
          
          ans.push_back(root->data);
          helper(root->left, ans);
          helper(root->right, ans);
          ans.pop_back();
      }
      
      void printPaths(TreeNode* node) {
  	  //Write your code here.
  	  vector<int> ans;
        helper(node, ans);
  
  	  	  
  	  }
  
  	  void printInorder(TreeNode* node) {
  	  	  if (node == NULL) {
  	  	  	  return;
  	  	  }
  	  	  printInorder(node->left);
  	  	  cout<<node->data<<" ";
  	  	  printInorder(node->right);
  	  }
  	  
  };
  
  int height(TreeNode* node) {
      if (node == NULL)
          return 0;
      int l = 1 + height(node->left);
      int r = 1 + height(node->right);
      if (l > r)
          return l;
      else
          return r;
  }
  
  int main(int argc,char**argv){
  
      unordered_map<int, TreeNode*> map ;
      int n ;
      cin>>n;
      TreeNode* root = NULL;
      while (n > 0) {
  
          int n1 ;
          cin>>n1;
          int n2 ;
          cin>>n2;
          char lr ;
          cin>>lr;
          TreeNode* parent =NULL;
          if(map.find(n1)==map.end()){
              parent = new TreeNode(n1);
              map[n1]= parent;
              if (root == NULL)
                  root = parent;
  
          }else{
              parent=map[n1];
          }
  
          TreeNode* child = new TreeNode(n2);
          if (lr == 'L')
              parent->left = child;
          else
              parent->right = child;
          map[n2]=child;
          n--;
      }
  
      BinaryTree bt;
      bt.printPaths(root);
      
  }