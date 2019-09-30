#include<iostream>
 #include<string>
 #include<map>
 using namespace std;
 
 // This is a functional problem. You have to complete this function.
 // It takes as input the String s representing the number. It should return
 // the most occurring digit in s.
 int solve(string& s) {
     // write your code here.
     map<char, int> m;
     for(int i = 0; i < s.length(); i++){
         if(m.count(s[i])) m[s[i]]++;
         else m[s[i]] = 1;
     }
     int max = 0;
     char ans;
     for(map<char, int> :: iterator it = m.begin(); it!=m.end(); it++){
         if(it->second >= max) {
             max = it->second;
             ans = it->first;
         }
     }
     return int(ans-'0');
 }
 //Don't make any changes here
 
 int main(int argc,char** argv){
     string s;
     cin>>s;
     cout<<solve(s)<<endl;
 }