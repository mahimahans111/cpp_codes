#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 vector<string> topKFrequent(vector<string> words, int k) {
     //Write your code here	 
     unordered_map<string, int> m;
     for(int i = 0; i < words.size(); i++){
         if(m.count(str[i])) m
     }
 }
 
 //Don't make any changes here
 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<string> arr;
     for (int i = 0; i < n; i++) {
         string val;
         cin>>val;
         arr.push_back(val);
     }
     int k;
     cin>>k;
     vector<string> res = topKFrequent(arr, k);
     sort(res.begin(), res.end());
     cout<<"[";
     for(int i=0; i<res.size(); i++){
         cout<<res[i];
         if(i != res.size() - 1){
             cout<<", ";
         }
     }
     cout<<"]";
 
 }