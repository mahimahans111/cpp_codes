#include<bits/stdc++.h>
 using namespace std;
 
 // This is a functional problem. Only this function has to be written.
 // This function takes as input a string and an integer k.
 // It should return required integer value.
 int countOfSubstringWithKOnes(string s, int K) 
 { 
     unordered_map<int, int> m;
     //Write your code here
     int ps = 0;
     int ans = 0;
     m[0] = 1;
     for(int i = 0; i < s.length(); i++){
         if(s[i] == '1')ps+=1;
         if(m.count(ps-K)){
             ans+=m[ps-K];
         }
         if(m.count(ps)) m[ps]++;
         else m[ps] = 1;
     }
     return ans;
 } 
 // -----------------------------------------------------
 
 int main(int argc, char** argv){
     string s;
     cin>>s; 
     int K;
     cin>>K; 
         
     cout<<countOfSubstringWithKOnes(s, K);
 }