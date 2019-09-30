#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input an array and n length of array.
 // It should return a boolean value.
 bool findTriplets(vector<int>&arr , int n)
 {
     //Write your code here
     sort(arr.begin(), arr.end());
     for(int i = 0; i < n-2; i++){
         int s = i+1; int e = n-1;
         while(s < e){
             if(arr[i]+arr[s]+arr[e] == 0) return true;
             if(arr[i]+arr[s]+arr[e] < 0){
                 s++;
             }
             else if(arr[i]+arr[s]+arr[e] > 0){
                 e--;
             }
         }
         
     }
     return false;
 }
 //Don't make any changes here
 
 int main(int argc,char** argv){
 
     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     bool res = findTriplets(v,n);
     string ans=res==1?"true":"false";
     cout<<ans;
 
 }