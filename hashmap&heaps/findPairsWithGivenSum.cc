#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 
 // This is a functional problem. You have to complete this function.
 // It takes as input an array of integers.
 // It should return 1 or -1.
 
 int solve(vector<int>& arr) {
     // write your code here.
     map<int, int> m;
     for(int i = 0; i < arr.size(); i++){
         for(int j = i+1; j < arr.size(); j++){
             if(m.count(arr[i]*arr[j])) return 1;
             else m[arr[i]*arr[j]] = 1;
         }
     }
     return -1;
 }
 
 //Don't make any changes here
 
 int main(int argc,char** argv){
 
     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     int res = solve(v);
 
     if (res == 1) {
         cout<<"Found"<<endl;;
     } else if (res == -1) {
         cout<<"Not Found"<<endl;
     }
 
 
 }