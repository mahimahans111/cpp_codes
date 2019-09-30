#include<iostream>
 #include<string>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 
  // This is a functional problem. You have to complete this function.
 // It takes as input two matrices and k.
 // It should return the count of pairs with sum k.
 int solve(vector<vector<int> > & mat1,vector<vector<int> >& mat2,int k) {
     // write your code here
     int n = mat1.size();
     unordered_map<int, int> m;
     for(int i = 0; i < n; i++){
         for(int j = 0; j < n; j++){
             if(m.count(mat2[i][j])){
                 m[mat2[i][j]]++;
             }
             else m[mat2[i][j]] = 1;
         }
     }
     int ans = 0;
     for(int i = 0; i < n; i++){
         for(int j = 0; j < n; j++){
             if(m.count(k-mat1[i][j])){
                 ans+=m[k-mat1[i][j]];
             }
         }
     }
     return ans;
 }
 
 
 int main(int argc,char** argv){
 
     int n;
     cin>>n;
     vector< vector<int> > mat1(n,vector<int> (n));
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             cin>>mat1[i][j];
         }
     }
     vector< vector<int> > mat2(n,vector<int> (n));
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             cin>>mat2[i][j];
         }
     }
     int k;
     cin>>k;
     cout<<solve(mat1,mat2,k)<<endl;
 }