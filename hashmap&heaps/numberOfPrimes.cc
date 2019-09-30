#include<bits/stdc++.h>
 using namespace std;
 // This is a functional problem. You have to complete this function.
 // It takes as input N. It should return the count of prime numbers less
 // than N.
 int countPrimes(int n) {
     int ans = 0;
     unordered_map<int, int> m;
     for(int i = 0; i < n; i++){
         m[i] = 1;
     }
     
     for(int i = 2; i <= sqrt(n); i++){
         int k = 1;
         for(int j = 2*i; j < n; j = j+=i){
             m.erase(j);
         }
     }
     
     
     // write your code here.
    return m.size()-2;
 }
 
 int main(int argc,char** argv){
     
     // Input for length of array.
     int N ;
     cin>>N;   
     cout<<countPrimes(N)<<endl;
 }