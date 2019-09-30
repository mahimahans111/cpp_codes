#include<bits/stdc++.h>
 using namespace std;
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 void findDifference(vector<int> &nums) {
     //write your code here
     unordered_map<int, int> m;
     for(int i = 0; i < nums.size(); i++){
         if(m.count(nums[i])){
             m[nums[i]]++;
         }
         else m[nums[i]] = 1;
     }
     
     int mini = INT_MAX;
     int maxi = INT_MIN;
     
     for(unordered_map<int, int> :: iterator it = m.begin(); it!=m.end(); it++){
         if(it->second > maxi) maxi = it->second;
         if(it->second < mini) mini = it->second;
     }
     cout << maxi-mini;
 }
 // -----------------------------------------------------
 
 
  
 int main(int argc,char** argv){
     
     // Input for length of array.
     int N ;
     cin>>N;
 
     vector<int> v;
 
     // Input for array elements.
     for (int i = 0; i < N; i++) {
         int a;
         cin>>a;
         v.push_back(a);
     }
     
     findDifference(v);
 }