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
 
 
 class BST {
     public:
     
     bool check(TreeNode* root, int n1){
        if(root == NULL) return false;
        if(root->val < n1) return check(root->right, n1);
        if(root->val > n1) return check(root->left, n1);
        if(root->val == n1) return true;
     }
     
 	 TreeNode* LCA(TreeNode* root, int n1, int n2) {
 	 	 // Write your code here.
 	 	 if(root == NULL) return NULL;
        else if(n1 < root->val && n2< root->val){
            return LCA(root->left, n1, n2);
        }
        else if(n1 > root->val && n2 > root->val){
            return LCA(root->right, n1, n2);
        }
        
            if(check(root, n1) && check(root, n2)) return root;
            else return NULL;

        return NULL;
 	 }
 
 };
 
 TreeNode* root;
 
 void insert(TreeNode* root, int key) {
     if (key < root->val) {
         if (root->left != NULL)
             insert(root->left, key);
         else {
             root->left = new TreeNode(key);
         }
     } else if (key > root->val) {
         if (root->right != NULL)
             insert(root->right, key);
         else {
             root->right = new TreeNode(key);
         }
     }
 }
 
 int main(int argc, char** argv){
     int n, a1;
     cin>>n;
 	 cin>>a1;
     TreeNode* root = new TreeNode(a1);
 
     for (int i = 1; i < n; i++) {
         int a;
         cin>>a;
         insert(root, a);
     }
 
     int n1, n2;
     cin>>n1>>n2;
     BST bst;
     TreeNode* lca = bst.LCA(root, n1, n2);
     cout<<lca->val<<endl;
 
 }