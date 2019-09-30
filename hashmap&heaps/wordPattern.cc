#include<bits/stdc++.h>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input 2 strings
 // It should return a boolean value
 
 bool wordPattern(string &pattern, vector<string> &str) { 
     unordered_map<char, string> m;
     unordered_map<string, char> m1;
     for(int i = 0; i < pattern.length(); i++){
         if(!m.count(pattern[i])){
             m[pattern[i]] = str[i];
         }
         else{
             if(m[pattern[i]]!=str[i]) return false;
         }
         if(!m1.count(str[i])){
             m1[str[i]] = pattern[i];
         }
         else{
             if(m1[str[i]]!=pattern[i]) return false;
         }
     }
     return true;
     //Write your code here
 }
 
 
 int main(int argc, char** argv){
     string pattern;
     cin >> pattern;
     vector<string> str;
     int n = pattern.length();
     string s;
     for(int i = 0; i < n; i++){
         cin >> s;
         str.push_back(s);
     }
     if(wordPattern(pattern,str)){
         cout<<"true";
     }else{
         cout<<"false";
     }
 }