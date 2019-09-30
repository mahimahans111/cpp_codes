#include<bits/stdc++.h>
 using namespace std;
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 bool containsDuplicate(vector<int> &nums) {
     //write your code here
     unordered_set<int> m;
     for(int i = 0; i < nums.size(); i++){
         if(m.count(nums[i]))return true;
         else m.insert(nums[i]);
     }
     return false;
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
     
     bool res=containsDuplicate(v);
     string ans=res==true?"true":"false";
     cout<<ans<<endl;
 }