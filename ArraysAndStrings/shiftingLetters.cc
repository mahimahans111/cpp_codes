#include<iostream>
 #include<vector>
 using namespace std;
 
   // This is a functional problem. You have to complete this function.
 // It takes as input a String S and an integer array shifts.
 // It should return the final string after all the shifts are applied.
 string shiftingLetters(string &S, vector<long long int> &shifts) {
     // write your code here. 
     long long int ss = 0;
     long long int n = S.length();
     for(long long int i = n-1; i >= 0; i--){
         ss+=shifts[i];
         char c = S[i];
         c = ((c-'a'+ss)%26)+'a';
         S[i] = c;
     }
     return S;
 }
 
 int main(){
     string s;
     cin>>s;
     long long int N;
     cin>>N;
 
     vector<long long int> shifts(N);
 
     for (long long int i = 0; i < N; i++) {
         cin>>shifts[i];
     }
 
     cout<<shiftingLetters(s, shifts);
 }