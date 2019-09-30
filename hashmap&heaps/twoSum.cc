#include<iostream>
 #include<vector>
 #include<algorithm>
 #include<unordered_map>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 vector<int> twoSum(vector<int> arr, int target) {
     //Write your code here
     int n = arr.size();
     vector<int> ans;
     unordered_map<int, int> m;
     int s = 0;
     int e = n-1;
     for(int i = 0; i < n; i++){
         m[arr[i]] = i;
     }
     
     for(int i = 0; i < n; i++){
         if(m.count(target-arr[i])){
             ans.push_back(i);
             ans.push_back(m[target-arr[i]]);
             return ans;
         }
     }
 }
 
 //Don't make any changes here.
 int main(int argc, char** argv){
     vector<int> nums;
     int n;
     cin>>n;
     for (int i = 0; i < n; i++) {
         int val;
         cin>>val;
         nums.push_back(val);
     }
     int target;
     cin>>target;
     vector<int> res = twoSum(nums, target);
     cout<<"[";
     for(int i=0; i<res.size(); i++){
         cout<<res[i];
         if(i != res.size() - 1){
             cout<<", ";
         }
     }
     cout<<"]";
 }