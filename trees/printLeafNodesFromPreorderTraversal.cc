#include<bits/stdc++.h>
 using namespace std;
 
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input an array
 // It should print the required output
 
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
     if(s == e) cout << pre[s] << " ";
     
     if(nge[s]!=-1 && nge[s] <= e){
         helper(pre, s+1, nge[s]-1, nge);
         helper(pre, nge[s], e, nge);
     }
     else{
         helper(pre, s+1, e, nge);
     }

 }
 
 void print(vector<int>& pre) {
    int n = pre.size();
     vector<int> nge = NGE(pre, n);
     helper(pre, 0, n-1, nge);
     //Write your code here
 }
 
 int main(int argc,char** argv) {
     int n ;
     cin>>n;
     vector<int> a;
     for (int i = 0; i <n; i++) {
         int x;
         cin>>x;
         a.push_back(x);
     }
     print(a);
 }