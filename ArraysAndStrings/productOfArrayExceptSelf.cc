#include<iostream>
 #include<vector>
 #include<string>
 using namespace std;
 vector<int> productExceptSelf(vector<int>& nums) {
 //Write your code here	 
    int n = nums.size();
    int pp[n];
    int sp[n];
    pp[0] = 1;
    for(int i = 1; i < n; i++){
        pp[i] = pp[i-1]*nums[i-1];
    }
    sp[n-1] = 1;
    for(int i = n-2; i >= 0; i--){
        sp[i] = sp[i+1]*nums[i+1];
    }
    
    vector<int> ans;
    for(int i = 0; i < n; i++){
        ans.push_back(pp[i]*sp[i]);
    }
    return ans;
 }
 
 //Don't make any changes here.
 int main(int argc,char** argv){
     int n;
     cin>>n;
     vector<int> Input(n);
     for(int i=0;i<n;i++){
         cin>>Input[i];
     }
     vector<int> ans = productExceptSelf(Input);
     for (int i : ans) {
         cout<<i<<" ";
     }
 
 }