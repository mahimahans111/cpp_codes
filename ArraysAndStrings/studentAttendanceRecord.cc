#include<iostream>
 using namespace std;
 
 // This is a functional problem. You have to complete this function.
 // It takes as input a String S. It should return true if the student could
 // be rewarded, else should return false.
 bool checkRecord(string &s) {
     int a = 0;
     int n = s.length();
     for(int i = 0; i < s.length(); i++){
         if(s[i] == 'A'){
             a++;
         }
        else if(i+2 < n && s[i] == 'L' && s[i+1] == 'L' && s[i+2] == 'L') return false;
     }
     if(a > 1) return false;
     return true;
 }
 
 int main(int argc, char** argv){
     string S;
     cin>>S;
 
     if (checkRecord(S)) {
         cout<<"Yes";
     } else {
         cout<<"No";
     }
 }