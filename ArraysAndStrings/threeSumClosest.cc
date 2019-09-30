#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input an array and an integer 
 // It should return an integer value.
 
 int threeSumClosest(vector<int>& arr, int target) {
     //Write your code here
      sort(arr.begin(), arr.end());
         int n = arr.size();
         int maxsum;
         int diffmin = INT_MAX;
     for(int i = 0; i < n-2;){
         int s = i+1; int e = n-1;
         while(s < e){
             if(arr[i]+arr[s]+arr[e] == target){
                    diffmin = 0;
                    maxsum = target;
               s++;
                e--;
             }
             else if(arr[i]+arr[s]+arr[e] < target){
                 if(abs(arr[i]+arr[s]+arr[e]-target) < diffmin){
                     diffmin = abs(arr[i]+arr[s]+arr[e]-target);
                     maxsum = arr[i]+arr[s]+arr[e];
                 }
               s++;
             }
             else if(arr[i]+arr[s]+arr[e] > target){
                 if(abs(arr[i]+arr[s]+arr[e]-target) < diffmin){
                     diffmin = abs(arr[i]+arr[s]+arr[e]-target);
                     maxsum = arr[i]+arr[s]+arr[e];
                 }
                e--;
             }
         }
         i++;

     }
     return maxsum;
 }
 
 int main(int argc,char** argv){
 
     int n;
     cin>>n;
     vector<int> nums(n);
     for(int i=0;i<n;i++){
         cin>>nums[i];
     }
     int k;
     cin>>k;
     int res=threeSumClosest(nums,k);
     cout<<res;
 
 }