#include<iostream>
#include<unordered_map>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 int count(string str) {
     unordered_map<char, int> m;
     int cnt = 0;
     for(int i = 0; i < str.length(); i++){
         if(m.count(str[i])){
             cnt+=m[str[i]];
             m[str[i]]++;
         }
         else{
             m[str[i]] = 1;
         }
     }
     cnt+=str.length();
     return cnt;
     //Write your code here
 }
 
 //Don't write your code here
 int main(int argc, char** argv){
     string str;
     cin>>str;
     int ans = count(str);
     cout<<ans;
 }