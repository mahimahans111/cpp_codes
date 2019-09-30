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
 	 TreeNode* head;
 
     //This is a functional problem. Write your code here.
     pair<TreeNode*, TreeNode*> helper(TreeNode* root){
         
         if(root == NULL){
             TreeNode*l = NULL;
             TreeNode*r = NULL;
             return pair<TreeNode*, TreeNode*>(l, r);
         }
         
         else if(root->left && root->right){
         pair<TreeNode*, TreeNode*> lp = helper(root->left);
         pair<TreeNode*, TreeNode*> rp = helper(root->right);
         
         lp.second->right = root;
         root->left = lp.second;
         
         root->right = rp.first;
         rp.first->left = root;
         return pair<TreeNode*, TreeNode*>(lp.first, rp.second);
         }
         
         else if(root->left){
         pair<TreeNode*, TreeNode*> lp = helper(root->left);

         lp.second->right = root;
         root->left = lp.second; 
         root->right = NULL;
         return pair<TreeNode*, TreeNode*>(lp.first, root);
         }
         
         else if(root->right){
         pair<TreeNode*, TreeNode*> rp = helper(root->right);
         
         root->right = rp.first;
         rp.first->left = root;
         root->left = NULL;
         return pair<TreeNode*, TreeNode*>(root, rp.second);
         }
         
         else if(root && !root->left && !root->right){
             TreeNode*l = root;
             TreeNode*r = root;
             return pair<TreeNode*, TreeNode*>(l, r);
         }
         
     }
     
     
 	 TreeNode* BT2DLL(TreeNode* root) {
 	 	 // Write your code here......
 	 	 pair<TreeNode*, TreeNode*> ans = helper(root);
 	 	 return ans.first;
 	 }
 
     // Don't make any changes here
 	 void printList(TreeNode* head) {
 	 	 TreeNode* prev = head;
 	 	 while (head != NULL) {
 	 	 	 cout<<head->val<<" ";
 	 	 	 prev = head;
 	 	 	 head = head->right;
 	 	 }
 
 	 	 cout<<endl;
 	 	 while (prev != NULL) {
 	 	 	 cout<<prev->val<<" ";
 	 	 	 prev = prev->left;
 	 	 }
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
 	 TreeNode* newRoot = bt.BT2DLL(root);
     bt.printList(newRoot);
 }