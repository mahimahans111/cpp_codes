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
 
 class BSTPair{
  public:
     bool isBST;
     int mini;
     int maxi;
     int lbs;
     TreeNode* lbr;
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
 // It takes as input the root node of the given tree. It should return the number of 
 // nodes in the largest subtree which is a BST.
 
 BSTPair helper(TreeNode* root){
     if(root == NULL){
         BSTPair bp;
         bp.mini = INT_MAX;
         bp.maxi = INT_MIN;
         bp.isBST = true;
         bp.lbs = 0;
         bp.lbr = NULL;
         return bp;
     }
     
     BSTPair lp = helper(root->left);
     BSTPair rp = helper(root->right);
     
     BSTPair mp;
     mp.mini = min(lp.mini, min(rp.mini, root->val));
     mp.maxi = max(lp.maxi, max(rp.maxi, root->val));
     mp.isBST = lp.isBST && rp.isBST && root->val > lp.maxi && root->val < rp.mini;
     if(mp.isBST){
         mp.lbr = root;
         mp.lbs = rp.lbs+lp.lbs+1;
     }
     else{
         if(lp.lbs > rp.lbs){
             mp.lbr = lp.lbr;
             mp.lbs = lp.lbs;
         }
         else{
             mp.lbs = rp.lbs;
             mp.lbr = rp.lbr;
         }
     }
     return mp;
 }
 
 int largestBst(TreeNode* node) {
     // write your code here.
    BSTPair ans = helper(node);
    return ans.lbs;
 }
 
 
 int main(int argc, char** argv){
     
     string line;
     getline(cin, line);
     TreeNode* root = stringToTreeNode(line);
     cout<<largestBst(root)<<endl;
     return 0;
 }