#include<iostream>
 #include<vector>
 using namespace std;
 
 // This is a functional problem. You have to complete this function.
 // It takes as input the inorder array, preorder array and the length of the arrays.
 // It should print the postorder traversal.
 
 void helper(vector<int> &pre, int psi, int pei, vector<int> &in, int isi, int iei){
     if(isi>iei || psi>pei) return;
     
     int idx = -1;
     for(int i = 0; i <= iei; i++){
         if(in[i] == pre[psi]){
             idx = i;
             break;
         } 
     }
     
     int lhs = idx-isi;
     
     helper(pre, psi+1, psi+lhs, in, isi, idx-1);
     helper(pre, psi+lhs+1, pei, in, idx+1, iei);
     cout << pre[psi] << " ";
 }
 
 void printPostOrder(vector<int> &in, vector<int> &pre, int n) {
     // write your code here.
    helper(pre, 0, n-1, in, 0, n-1);
 }
 
 int main(int argc, char** argv){
     int N;
     cin>>N;
     vector<int> inorder(N);
     for(int i=0; i<N; i++){
         cin>>inorder[i];
     }
 
     vector<int> preorder(N);
     for(int i=0; i<N; i++){
         cin>>preorder[i];
     }
     printPostOrder(inorder, preorder, N);
 
 }