#include<iostream>
 #include<vector>
 using namespace std;
 
 class TreeNode{
     public:
     int data;
     TreeNode*left;
     TreeNode*right;
     
     TreeNode(int d){
         data = d;
         left = NULL;
         right = NULL;
     }
 };
 
 void printPreorder(TreeNode*root){
     if(root == NULL) return;
     cout << root->data << " ";     
     printPreorder(root->left);
     printPreorder(root->right);
 }
 
 TreeNode* BSTFormation(vector<int> &arr, int i, int j) {
     //write your code here
     if(i > j) return NULL;
     
     int mid = (i+j)/2;
     TreeNode*root = new TreeNode(arr[mid]);
     root->left = BSTFormation(arr, i, mid-1);
     root->right = BSTFormation(arr, mid+1, j);
     return root;
 }
 
 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> arr(n);
     for (int i = 0; i < arr.size(); i++) {
         cin>>arr[i];
     }
     TreeNode* root = BSTFormation(arr, 0, arr.size() - 1);
     printPreorder(root);
 }