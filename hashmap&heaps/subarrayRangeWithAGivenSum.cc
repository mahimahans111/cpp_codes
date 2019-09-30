#include<iostream>
 #include<vector>
 #include<unordered_map>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 int subArraySum(vector<int> arr, int n, int sum) {
     // write your code here
     unordered_map<int, int> m;
     m[0] = 1;
     int ps = 0;
     int ans = 0;
     for(int i = 0; i < n; i++){
         ps+=arr[i];
         if(m.count(ps-sum)){
             ans+=m[ps-sum];
         }
         if(m.count(ps)){
             m[ps]++;
         }
         else m[ps] = 1;
     }
     return ans;
 }
 // -----------------------------------------------------
 
 int main(int argc, char** argv){
     int n, sum;
     cin>>n>>sum;
     vector<int> arr;
     for (int z = 0; z < n; z++) {
         int val;
         cin>>val;
         arr.push_back(val);
     }
     cout<<subArraySum(arr, n, sum);
 }