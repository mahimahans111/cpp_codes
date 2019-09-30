#include<iostream>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 
 // This is a functional problem. You have to complete this function.
 // It takes as input the String s ant t. It should return the different
 // character.
 char findTheDifference(string& s, string& t) {
     // write your code here.
     int ixor = int(s[0]-'0');
     for(int i = 1; i < s.length(); i++){
         ixor = ixor^(s[i]-'0');
     }
     for(int i = 0; i < t.length(); i++){
         ixor = ixor^(t[i]-'0');
     }
     return char(ixor+'0');
 }
 //Don't make any changes here
 
 int main(int argc,char** argv){
 
     string s,t;
     cin>>s;
     cin>>t;
     cout<<findTheDifference(s,t)<<endl;
 }