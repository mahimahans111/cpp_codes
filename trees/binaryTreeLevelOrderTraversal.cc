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
 
 class BinaryTree {
     public:
 	 vector<vector<int> > zigzagLevelOrder(TreeNode* node) {
 	 	 // Write your code here..
 	 	     vector< vector<int> > ans;
      queue<TreeNode*> q;
      q.push(node);
      while(q.size()>0){
          vector<int> v;
          int cnt = q.size();
          while(cnt--){
              TreeNode*t = q.front();
              v.push_back(t->val);
              q.pop();
              
              if(t->left)q.push(t->left);
              if(t->right)q.push(t->right);
          }
          ans.push_back(v);
      }
      for(int i = 1; i < ans.size(); i++){
          if(i%2 != 0){
              for(int j = 0; j < ans[i].size()/2; j++){
                  swap(ans[i][j], ans[i][ans[i].size()-j-1]);
              }
          }
      }
      
      return ans;
 	 }
 
 	 // Don't make any changes here
 	 void inOrder(TreeNode* node) {
 	 	 if (node == NULL) {
 	 	 	 return;
 	 	 }
 
 	 	 inOrder(node->left);
 	 	 cout<<node->val<<" ";
 	 	 inOrder(node->right);
 	 }
 };
 
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
 
 int main(int argc, char** argv){
     string line;
     getline(cin, line);
     TreeNode* root = stringToTreeNode(line);
 	 BinaryTree bt;
 	 vector<vector<int> > res = bt.zigzagLevelOrder(root);
     cout<<"[";
 	 for(int i=0; i<res.size(); i++){
         cout<<"[";
         for(int j=0; j<res[i].size(); j++){
             cout<<res[i][j];
             if(j != res[i].size() - 1){
                 cout<<", ";
             }
         }
         cout<<"]";
         if(i != res.size() - 1){
             cout<<", ";
         }
     }
     cout<<"]";
 }