#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 
 // This is a functional problem. You have to complete this function.
 // It takes as input two array.
 // It should return list of k lists of pairs with smallest sum.
 vector<int> unionfn(vector<int> arr1, vector<int> arr2) {
     // write your code here.
     vector<int> ans;
     unordered_set<int> s;
     for(int i = 0; i < arr1.size(); i++){
         s.insert(arr1[i]);
     }
     for(int i = 0; i < arr2.size(); i++){
         s.insert(arr2[i]);
     }
     for(unordered_set<int> :: iterator it = s.begin(); it!=s.end(); it++){
         ans.push_back(*it);
     }
     return ans;
 }
 
 // Function to display an array.
 void display(vector<int> arr) {
 
     for (int i = 0; i < arr.size(); i++) {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
 }
 
 int main(int argc, char** argv){
 
     // Input for length of first array.
     int N;
     cin>>N;
     vector<int> arr1;
 
     // Input for array1 elements.
     for (int i = 0; i < N; i++) {
         int val;
         cin>>val;
         arr1.push_back(val);
     }
 
     // Input for length of second array.
     int M;
     cin>>M;
     vector<int> arr2;
 
     // Input for array2 elements.
     for (int i = 0; i < M; i++) {
         int val;
         cin>>val;
         arr2.push_back(val);
     }
 
     vector<int> result = unionfn(arr1, arr2);
 
     sort(result.begin(), result.end());
     display(result);
 
 }