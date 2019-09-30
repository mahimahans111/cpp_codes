#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input a deck of cards
 // It should return the answer deck
 vector<int> deckRevealedIncreasing(vector<int>& nums) {
 //Write your code here	
    sort(nums.begin(), nums.end());
    vector<int> indexes;
    
    queue<int> q;
    for(int i = 0; i < nums.size(); i++){
        q.push(i);
    }
    
    while(!q.empty()){
        indexes.push_back(q.front());
        q.pop();
        if(!q.empty()){
            int k = q.front();
            q.pop();
            q.push(k);
        }
    }
    
    vector<int> ans(nums.size(), 0);
    for(int i = 0; i < nums.size(); i++){
        ans[indexes[i]] = nums[i];
    }
    
    return ans;
 }
 
 //Don't make any changes here.
 int main(int argc,char** argv){
     int n;
     cin>>n;
     
     vector<int>Input;
     int x;
     for(int i = 0; i < n; i++){
         cin >> x;
         Input.push_back(x);
     }
     vector<int> ans = deckRevealedIncreasing(Input);
     for (int i : ans) {
         cout<<i<<" ";
     }
 
 }