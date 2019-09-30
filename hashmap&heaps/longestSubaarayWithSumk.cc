#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 void print (vector<int> &arr,int k,int n) {
     //Write your code here 
     unordered_map<int, int> m;
     m[0] = -1;
     int ps = 0;
     int ans = 0;
     for(int i = 0; i < n; i++){
         ps+=arr[i];
        //  cout << ps << " ";
         if(m.count(ps-k)){
             if(i-m[ps-k] > ans){
                 ans = i-m[ps-k];
             }
         }
         else {
             if(!m.count(ps))
             m[ps] = i;
         }
     }
     cout << ans;
 }
     
 int main(int argc,char** argv){
     int n;
     cin>>n;
     int k;
     cin>>k;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     print(v,k,n);
 }