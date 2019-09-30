#include<iostream>
#include<unordered_map>
 using namespace std;
 
 // This is a functional problem. You have to complete this function.
 // It takes as input the String s ant t. It should return true if t is
 // and anagram of s, else should return false.
 bool isAnagram(string s, string t) {
     unordered_map<char, int> m;
     for(int i = 0; i < s.length(); i++){
         if(m.count(s[i]))m[s[i]]++;
         else m[s[i]] = 1;
     }
     for(int i = 0; i < t.length(); i++){
         if(!m.count(t[i])) return false;
         else{
             if(m[t[i]] == 1)m.erase(t[i]);
             else m[t[i]]--;
         }
     }
     return m.size() == 0;
     // write your code here.
 }
 
 int main(int argc, char** argv){
     string s, t;
     cin>>s>>t;
 
     if (isAnagram(s, t)) {
         cout<<"Yes";
     } else {
         cout<<"No";
     }
 }