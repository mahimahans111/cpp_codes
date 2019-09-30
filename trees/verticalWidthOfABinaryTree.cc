#include<iostream>
 #include<vector>
 #include<queue>
 #include<bits/stdc++.h>
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
 
     void span(TreeNode* root, int &mini, int& maxi, int l){
         if(root == NULL) return;
         
         mini = min(l, mini);
         maxi = max(l, maxi);
         
         span(root->left, mini, maxi, l-1);
         span(root->right, mini, maxi, l+1);
     }
 
     int verticalWidth(TreeNode* root) {
 	     //Write your code here.	 	 
        int mini = INT_MAX;
        int maxi = INT_MIN;
        span(root, mini, maxi, 0);
        return maxi-mini+1;
 	 }
 
 
 	 
 };
 
 void insert(TreeNode* root, int a, int a1, char lr) {
     if (root == NULL) {
         return;
     }
     if (root->data == a) {
         switch (lr) {
         case 'L':
             root->left = new TreeNode(a1);
             break;
         case 'R':
             root->right = new TreeNode(a1);
             break;
         }
         return;
     }
     insert(root->left, a, a1, lr);
     insert(root->right, a, a1, lr);
 }
 
 // utility function to display a binary tree
 void display(TreeNode* node) {
     if (node == NULL) {
         return;
     }
     string str = "";
 
     str += node->left == NULL ? "." : to_string(node->left->data);
     str += " <= " + to_string(node->data) + " => ";
     str += node->right == NULL ? "." : to_string(node->right->data);
 
     cout<<str<<endl;
 
     display(node->left);
     display(node->right);
 }
 
 int main(int argc,char** argv) {
     int n ;
     cin>>n;
     TreeNode* root = NULL;
   
     if (n == 0) {
         cout<<0<<endl;
         
     }
          for (int i = 0; i < n; i++) {
             int a ;
             cin>>a;
             int a1;
             cin>>a1;
 
             char lr ;
             cin>>lr; 
             if (i == 0) {
 
                 root = new TreeNode(a);
 
                 switch (lr) {
                 case 'L':
                     root->left = new TreeNode(a1);
                     break;
                 case 'R':
                     root->right = new TreeNode(a1);
                     break;
                 }
             } else {
                 insert(root, a, a1, lr);
             }
         }
     BinaryTree tree ;
 
     cout<<tree.verticalWidth(root)<<endl;
 
 }