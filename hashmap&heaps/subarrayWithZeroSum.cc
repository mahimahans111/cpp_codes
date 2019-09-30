#include<iostream>
 #include<vector>
 #include<unordered_map>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input an array
 // Print required output
 void zerosumarr(vector<long> arr){
     //Write your code here
     int sum = 0;
      unordered_map<int, int> m;
      int n = arr.size();
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
     cout << ans;
 }
 
 //Don't make any changes here.
 int main(int argc, char** argv){
     int size; 
     cin>>size;
     vector<long> a;
     for (int z = 0; z < size; z++) {
         long val;
         cin>>val;
         a.push_back(val);
     }
     zerosumarr(a);
 }
 
 
 
