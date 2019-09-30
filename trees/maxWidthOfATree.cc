#include<iostream>
 #include<vector>
 #include<queue>
 #include<bits/stdc++.h>
 using namespace std;
 
 // TreeNode class for a node of a Binary Search Tree
 class Node {
     public:
 	 int data;
 	 Node* left;
 	 Node* right;
 
 	 Node(int x) {
 	 	 data = x;
         left = NULL;
         right = NULL;
 	 }
 };
 
 
 class BinaryTree {
 
     public:
    int ans = 0;
     int getMaxWidth(Node* node) {
 	 //Write your code here.
      queue<Node*> q;
      q.push(node);
      while(q.size()>0){
          int cnt = q.size();
          if(cnt > ans) ans = cnt;
          while(cnt--){
              Node*t = q.front();
              q.pop();
              
              if(t->left)q.push(t->left);
              if(t->right)q.push(t->right);
          }
      }
      return ans;
 
 	 }
 
 
 
 	 
 };
 
 void insert(Node* root, int a, int a1, char lr) {
     if (root == NULL) {
         return;
     }
     if (root->data == a) {
         switch (lr) {
         case 'L':
             root->left = new Node(a1);
             break;
         case 'R':
             root->right = new Node(a1);
             break;
         }
         return;
     }
     insert(root->left, a, a1, lr);
     insert(root->right, a, a1, lr);
 }
 
 // utility function to display a binary tree
 void display(Node* node) {
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
     if (n == 0) {
         cout<<0<<endl;
         
     }
     Node* root = NULL;
     for (int i = 0; i < n; i++) {
 
         int a ;
         cin>>a;
         int a1;
         cin>>a1;
 
         char lr ;
         cin>>lr; 
         if (i == 0) {
 
             root = new Node(a);
 
             switch (lr) {
             case 'L':
                 root->left = new Node(a1);
                 break;
             case 'R':
                 root->right = new Node(a1);
                 break;
             }
         } else {
             insert(root, a, a1, lr);
         }
     }
     BinaryTree g ;
     cout<<g.getMaxWidth(root)<<endl;
 
 }