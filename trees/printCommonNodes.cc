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
 // It takes as input the root nodes of two BSTs. It should print the common nodes in sorted order.
 void inorder(TreeNode* root, vector<int>& in){
     if(root == NULL) return;
     
     inorder(root->left, in);
     in.push_back(root->val);
     inorder(root->right, in);
 }
 
 void print(vector<int> v1, vector<int> v2){
     for(int i = 0, j = 0; i < v1.size() && j < v2.size(); ){
         if(v1[i]<v2[j]){
             i++;
         }
         else if(v1[i] > v2[j]){
             j++;
         }
         else{
             cout << v1[i] << " ";
             i++; j++;
         }
     }
 }
 
 void printCommon(TreeNode* root1, TreeNode* root2) {
     // write your code here.
     vector<int> in1, in2;
     inorder(root1, in1);
     inorder(root2, in2);
     print(in1, in2);
     
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
     string line1;
     getline(cin, line1);
     TreeNode* root1 = stringToTreeNode(line1);
     string line2;
     getline(cin, line2);
     TreeNode* root2 = stringToTreeNode(line2);
     printCommon(root1, root2);
 }