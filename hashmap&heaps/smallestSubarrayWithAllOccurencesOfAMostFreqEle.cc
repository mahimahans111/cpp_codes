#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 void subarrAllOcc(vector<int> arr) {
     //Write your code here
     unordered_map<int, int> m, fm;
     int s = 0, e = 0;
     
     int bs = 0, be = arr.size()-1;
     int mf = 0;
     for(int i = 0; i < arr.size(); i++){
         if(m.count(arr[i])){
             fm[arr[i]]++;
             if(fm[arr[i]] > mf){
                 mf = fm[arr[i]];
                 be = i; bs = m[arr[i]];
             }
         }
         else {
             m[arr[i]] = i;
             fm[arr[i]] = 1;
             if(fm[arr[i]] > mf){
                 mf = fm[arr[i]];
                 be = i; bs = m[arr[i]];
             }
         }
     }
     
     for(int i = bs; i <= be; i++){
         cout << arr[i] << " ";
     }
 }
 
 //Dont make changes here
 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> arr;
     for(int i=0;i<n;i++){
         int val;
         cin>>val;
         arr.push_back(val);
     }
     subarrAllOcc(arr);
 }