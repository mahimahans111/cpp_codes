#include<iostream>
  #include<vector>
  #include<string>
  #include<bits/stdc++.h>
  using namespace std;
  
   // -----------------------------------------------------
  // This is a functional problem. Only this function has to be written.
  // This function takes as input a String s
  // Return index of first unique character, if none present, return -1
  int firstUniqChar(string& s) {
      // write your code here.
      unordered_map<char, int> m;
      for(int i = 0; i < s.length(); i++){
          if(m.count(s[i]))m[s[i]]++;
          else m[s[i]] = 1;
      }
      
      for(int i = 0; i < s.length(); i++){
          if(m[s[i]] == 1) return i;
      }
     return -1;
  }
  
  int main(int argc,char** argv) {
  
      string str;
      cin>>str;
      cout<<firstUniqChar(str);
  
  }