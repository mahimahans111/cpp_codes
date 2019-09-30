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
 
 // This is a functional problem. You have to complete this function.
 // It takes as input the root node of the given tree. It should return true
 // if the given tree is a Sum Tree, else should return false.
 class Pair{
     public:
     int sum;
     bool isSum;
     Pair(){
         
     }
     Pair(int a, bool b){
         sum = a;
         isSum = b;
     }
 };
 
 Pair helper(TreeNode* root){
     if(root == NULL) return Pair(0, true);
     if(root && !root->left && !root->right) return Pair(root->val, true);
     
     Pair lp = helper(root->left);
     Pair rp = helper(root->right);
     
     Pair mp;
     mp.sum = lp.sum+rp.sum+root->val;
     mp.isSum = (root->val == lp.sum+rp.sum) && lp.isSum && rp.isSum;
     return mp;
 }
 
 bool isSumTree(TreeNode* node) {
     // write your code here.
     Pair ans = helper(node);
     return ans.isSum;
     
 }
 
 //Don't change code of utility function.
 TreeNode* stringToTreeNode(string &input) {
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
     if(isSumTree(root)){
         cout<<"Yes"<<endl;
     } else {
         cout<<"No"<<endl;
     }
 }