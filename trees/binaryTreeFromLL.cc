#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 #include<queue>
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
 
 // LinkedListNode class for a node of a LinkedList
 class LinkedListNode {
     public:
 	 int data;
 	 LinkedListNode* next;
 
 	 LinkedListNode(int d) {
 	 	 data = d;
 	 	 next = NULL;
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
 
 class BinaryTree {
     public:
 	 TreeNode* convert(LinkedListNode* head, TreeNode* node) {
 	 	 // Write your code here.
 	 	 queue<TreeNode*> q;
 	 	 LinkedListNode*temp = head;
 	 	 TreeNode*root = new TreeNode(temp->data);
 	 	 temp = temp->next;
 	 	 q.push(root);
          while(!q.empty()){
              TreeNode* t = q.front();
              q.pop();
             if(temp){
                 t->left = new TreeNode(temp->data);
                 q.push(t->left);
                 temp = temp->next;
             } else break;
             if(temp){
                 t->right = new TreeNode(temp->data);
                 q.push(t->right);
                 temp = temp->next;
             } else break;
             
             
          }
          return root;
 	 }
 
 };
 
 LinkedListNode* lhead;
 queue<TreeNode*> q;
 
 void levelOrder(TreeNode* root, int n) {
     q.push(root);
     while (q.size() > 0 && n-- > 0) {
         TreeNode* proot = q.front();
         q.pop();
         if (proot->left != NULL) {
             q.push(proot->left);
         }
         if (proot->right != NULL) {
             q.push(proot->right);
         }
         cout<<proot->val<<" ";
     }
 }
 
 void addToTheLast(LinkedListNode* head) {
     if (lhead == NULL)
         lhead = head;
     else {
         LinkedListNode* temp = lhead;
         while (temp->next != NULL)
             temp = temp->next;
         temp->next = head;
     }
 }
 
 //Helper function to display list. Don't change code of helper function.
 void displayList(){
     while(lhead != NULL){
         cout<<lhead->data<<" ";
         lhead = lhead->next;
     }
 }
 
 int main(int argc, char** argv){
     TreeNode* node = NULL;
 	 lhead = NULL;
     LinkedListNode* head = NULL;
     while (q.size() > 0) {
         q.pop();
     }
     int n;
     cin>>n;
     if (n != 0) {
         int a1;
         cin>>a1;
         head = new LinkedListNode(a1);
         addToTheLast(head);
         lhead = head;
         for (int i = 1; i < n; i++) {
             int a;
             cin>>a;
             addToTheLast(new LinkedListNode(a));
         }
     }
     BinaryTree bt;
     TreeNode* root = bt.convert(lhead, node);
     levelOrder(root, n);
 }