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
 // It takes as input the root node of the given tree. It should return true 
 // if all the leaf nodes are at the same level, else should return false.
 int l = -1;
 bool helper(TreeNode*root, int level){
     if(root == NULL) return true;
    else if(root && !root->left && !root->right){
        if(l == -1) l = level;
        else {
            if(level!=l) return false;
        }
    }
    
    bool l = helper(root->left, level+1);
    bool r = helper(root->right, level+1);
    return l && r;
 }
 
 bool check(TreeNode* root) {
     // write your code here.
    return helper(root, 0);
 }
 
 
 int main(int argc, char** argv){
     
     string line;
     getline(cin, line);
     TreeNode* root = stringToTreeNode(line);
     if(check(root)){
         cout<<"Yes"<<endl;
     } else {
         cout<<"No"<<endl;
     }
     return 0;
 }