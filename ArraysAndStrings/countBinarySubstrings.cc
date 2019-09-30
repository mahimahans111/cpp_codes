#include<iostream>
 #include<vector>
 using namespace std;

 int countBinarySubstrings(string& s) {
     string prev = "";
     int ans = 0;
     string cur = "";
     for(int i = 0; i < s.length(); i++){
         if(i == 0){
             cur+=s[0];
         }
         else{
             if(s[i] == s[i-1]){
                 cur+=s[i];
                 if(cur.length()<=prev.length()) ans++;
             }
             else{
                 prev = cur;
                 cur = "";
                 cur+=s[i];
                 if(cur.length()<=prev.length()) ans++;
             }
         }
     }
     return ans;
}
 
 //Don't make any changes here.
 int main (int argc,char**argv){
     string n;
     cin>>n;   
     cout<<countBinarySubstrings(n);
 
 }