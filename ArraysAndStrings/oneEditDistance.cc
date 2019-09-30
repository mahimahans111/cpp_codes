#include<iostream>
 #include<vector>
 #include<string>
 using namespace std;
 
 // This is a functional problem. You have to complete this function.
 // It takes as input two strings s and t.
 // It should return true if the strings are one edit distance apart,
 // else should return false.
 bool isOneEditDistance(string & s, string& t) {
     if(s.length()==t.length()){
         int flag = 0;
         for(int i = 0; i < s.length(); i++){
             if(flag == 1 && s[i]!=t[i]) return false;
             if(flag == 0 && s[i]!=t[i]){
                 s[i] = t[i];
                 flag = 1;
             }
         }
         if(flag == 0) return false;
     }
     
     else if(s.length()==t.length()+1){
         int flag = 0;
         for(int i = 0; i < t.length(); i++){
             if(s[i]!=t[i]){
                 for(int k = i+1; k < s.length(); k++){
                     s[k-1] = s[k];
                 }
                 flag = 1;
                 break;
             }
         }
         if(flag == 0) return true;
         if(flag == 1){
             for(int i = 0; i < t.length(); i++){
                 if(s[i]!=t[i]) return false;
             }
         }
    }
     
     else if(s.length()==t.length()-1){
         int flag = 0;
         for(int i = 0; i < s.length(); i++){
             if(s[i]!=t[i]){
                 for(int k = i; k < s.length(); k++){
                     s[k+1] = s[k];
                 }
                 s[i] = t[i];
                 flag = 1;
                 break;
             }
         }
         if(flag == 0) return true;
         if(flag == 1){
             for(int i = 0; i < t.length(); i++){
                 if(s[i]!=t[i]) return false;
             }
         }
     }
     else return false;
     // write your code here. 
    return true;
 }
 
 int main (int argc,char** argv){
     string s,t;
     cin>>s;
     cin>>t;
 
     if (isOneEditDistance(s, t)) {
         cout<<"Yes"<<endl;
     } else {
         cout<<"No"<<endl;
     }
 
 }