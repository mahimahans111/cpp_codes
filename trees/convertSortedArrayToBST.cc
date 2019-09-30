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
 
 class Pair {
     public:
     int height;
     bool isBST;
     bool isBalanced;
     Pair(){
         this->height = 0;
         this->isBST = true;
         this->isBalanced = true;
     }
 };
 
 Pair isBalancedBST(TreeNode* node, int minv, int maxv, Pair p){
     if (node == NULL) {
         Pair bp;
         return bp;
     } 
 
     if (node->val < minv || node->val > maxv){
         p.isBST = false;
         return p;
     } 
 
     Pair l = isBalancedBST(node->left, minv, node->val - 1, p);
     Pair r = isBalancedBST(node->right, node->val + 1, maxv, p);
 
     p.height = max(l.height, r.height) + 1;
     p.isBST = l.isBST && r.isBST;
     p.isBalanced = abs(l.height - r.height) > 1 ? false : true;
 
     return p;
 }
 
 // This is a functional problem. You have to complete this function.
 // It takes as input a sorted array. It should create and return root of the balanced BST.
 TreeNode* helper(vector<int> &nums, int s, int e){
     if(s > e) return NULL;
     
     int mid = (s+e)/2;
     TreeNode* root = new TreeNode(nums[mid]);
     root->left = helper(nums, s, mid-1);
     root->right = helper(nums, mid+1, e);
     return root;
 }
 
 TreeNode* sortedArrayToBST(vector<int> &nums) {
     // write your code here.
     TreeNode* root = helper(nums, 0, nums.size()-1);
     return root;
 }
 
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
 
 int main(int argc, char** argv){
     int N;
     cin>>N;
 	 vector<int> sortedArr(N);
     for(int i=0; i<N; i++){
         cin>>sortedArr[i];
     }
 
     TreeNode* root = sortedArrayToBST(sortedArr);
     Pair p;
     Pair res = isBalancedBST(root, INT_MIN, INT_MAX, p);
 
     if(res.isBST && res.isBalanced){
         cout<<"Correct"<<endl;
     } else{
         cout<<"Incorrect"<<endl;
     }
 }