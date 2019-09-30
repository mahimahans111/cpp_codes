#include<iostream>
 #include<string>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input an N.
 // It should return an integer value.
 
 int solve(int N) {
     int x = 0;
     while((1<<x) < N+1) x++;
     
     return x-1;
     //Write your code here
 }
 
 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
 
     cout<<solve(n)<<endl;
 }