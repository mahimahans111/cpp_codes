#include<iostream>
 #include<vector>
 #include<stack>
 using namespace std;
 
 // This is a functional problem. You have to complete this function.
 // It takes as input an integer array representing the preorder traversal of a BST.
 // It should print the postorder traversal.
 vector<int> NGE(vector<int> &pre, int n){
     vector<int> nge(n, -1);
     stack<int> s;
     nge[n-1] = -1;
     s.push(n-1);
     for(int i = n-2; i >= 0; i--){
         while(s.size()>0 && pre[s.top()] <= pre[i]){
             s.pop();
         }
         nge[i] = s.empty() ? -1 : s.top();
         s.push(i);
     }
     return nge;
 }
 
 void helper(vector<int> &pre, int s, int e, vector<int> nge){
     if(s > e) return;
     
     if(nge[s]!=-1 && nge[s] <= e){
         helper(pre, s+1, nge[s]-1, nge);
         helper(pre, nge[s], e, nge);
     }
     else{
         helper(pre, s+1, e, nge);
     }
    cout << pre[s] << " ";
     
 }
 
 void postfrompre(vector<int> &pre) {
     // write your code here.
     int n = pre.size();
     vector<int> nge = NGE(pre, n);
     helper(pre, 0, n-1, nge);
 }
 
 int main(int argc, char** argv){
     int N;
     cin>>N;
     vector<int> preorder(N);
     for(int i=0; i<N; i++){
         cin>>preorder[i];
     }
     postfrompre(preorder);
 
 }