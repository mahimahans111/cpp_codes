#include<iostream>
 #include<vector>
 #include<unordered_map>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 int subArraysDivByK(vector<int> arr, int n, int k) {
     // write your code here
     unordered_map<int, int> m;
     m[0] = 1;
     int ps = 0;
     int ans = 0;
     for(int i = 0; i < n; i++){
         ps+=arr[i];
         if(ps<0){
            ps = (k+ps%k)%k;
         }
         if(m.count(ps%k)){
            //  cout << ps%k << " " << m[ps%k] << "!!!!!";
             ans+=m[ps%k];
         }
         if(m.count(ps%k)){
             m[ps%k]++;
         }
         else m[ps%k] = 1;
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
     cout<<subArraysDivByK(arr, n, sum);
 }