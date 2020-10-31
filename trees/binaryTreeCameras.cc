#include<iostream>
 #include<vector>
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
 
 // creation of tree from array by level order, -1 says there is no node
 TreeNode* levelOrder(vector<int> &arr) {
     
     vector<TreeNode*> nodes(arr.size());
     for (int i = 0; i < nodes.size(); i++) {
         if (arr[i] != -1) {
             TreeNode* t = new TreeNode(arr[i]);
             nodes[i] = t;
 
             if (i > 0) {
                 int pi = (i - 1) / 2;
                 if (i == 2 * pi + 1) {
                     nodes[pi]->left = nodes[i];
                 } else {
                     nodes[pi]->right = nodes[i];
                 }
             }
         }
     }
     TreeNode* root = nodes[0];
     return root;
 }
 
 // This is a functional problem. You have to complete this function.
 // It takes as input the root of the given tree. It should return the minimum number of cameras required.
 int minCameraCover(TreeNode* root) {
     // write your code here 
     if(root == NULL) return 0;
     
     int a = root->left ? minCameraCover(root->left->left) : 0;
     int b = root->left ? minCameraCover(root->left->right) : 0;
     int c = root->right ? minCameraCover(root->right->left) :0;
     int d = root->right ? minCameraCover(root->right->right):0;
     
     int f1 = 1+a+b+c+d;
     
     int a1 = (root->left && root->left->left)?minCameraCover(root->left->left->left):0;
     int b1 = (root->left && root->left->left)?minCameraCover(root->left->left->right):0;
     int c1 = (root->left && root->left->right)? minCameraCover(root->left->right->left):0;
     int d1 = (root->left && root->left->right)?minCameraCover(root->left->right->right):0;
     int e1 = minCameraCover(root->right);
     
     int f2 = 1+a1+b1+c1+d1+e1;
     
      int a2 = (root->right && root->right->left)?minCameraCover(root->right->left->left):0;
     int b2 = (root->right && root->right->left)?minCameraCover(root->right->left->right):0;
     int c2 = (root->right && root->right->right)? minCameraCover(root->right->right->left):0;
     int d2 = (root->right && root->right->right)?minCameraCover(root->right->right->right):0;
     int e2 = minCameraCover(root->left);
     
     int f3 = 1+a2+b2+c2+d2+e2;
     return min(f1, min(f2, f3));
 }
 
 	 
 int main(int argc, char** argv){
     // length of array representing the tree
     int len;
     cin>>len;
 
     vector<int> arr(len);
     for (int i = 0; i < len; i++) {
         cin>>arr[i];
     }
     TreeNode* root = levelOrder(arr);
     cout<<minCameraCover(root);
 }