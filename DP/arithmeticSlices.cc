#include<iostream>
 #include<vector>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input one array
 // It should return the required output
 
 int Arithmetic_Slices(vector<int> &arr) {
     //Write your code here
     int n = arr.size();
     if(n==0||n==1||n==2) return 0;
     int dp[n] = {};
     dp[0] = 0;
     dp[1] = 0;
     int ans = 0;
     for(int i = 2; i < n; i++){
         if(arr[i]-arr[i-1] == arr[i-1]-arr[i-2]){
             dp[i] = dp[i-1]+1;
             ans+=dp[i];
         }
     }
     return ans;
 }
 
 int main(int argc,char** argv){
 
     int n;
     cin>>n;
     vector<int> v(n);
     for (int i = 0; i < n; i++){
         cin>>v[i];
     }
     cout<<Arithmetic_Slices(v)<<endl;
 }