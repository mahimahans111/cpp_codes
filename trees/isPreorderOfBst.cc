#include<bits/stdc++.h>
 using namespace std;
 
 // This is a functional problem. You have to complete this function.
 // It takes as input an integer array. It should return true if the array can represent preorder traversal of a BST, else should return false.
 
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
 
 bool helper(vector<int> pre, int s, int e, int min, int max, vector<int> nge){
     
     if(s >= e) return true;
     
     int val = pre[s];
     int ngei = nge[s];
     
     if(val < min || val > max) return false;
     
     bool lf = helper(pre, s+1, (ngei!= -1 && ngei-1 <= e)? ngei-1 : e, min, pre[s], nge);
     bool rf = helper(pre, ngei, e, pre[s], max, nge);
     
     return lf && rf;
 }
 
 bool preOrder(vector<int> &pre) {
     // write your code here.
     int  min = INT_MIN;
     int max = INT_MAX;
     int n = pre.size();
     vector<int> nge = NGE(pre, n);
     bool ans = helper(pre, 0, n-1, min, max, nge);
     return ans;
 }
 
 
 int main(int argc, char** argv){
     int N;
     cin>>N;
     vector<int> arr(N);
     for(int i=0; i<N; i++){
         cin>>arr[i];
     }
     if(preOrder(arr)){
         cout<<"Yes"<<endl;
     } else{
         cout<<"No"<<endl;
     }
 
 }