#include<iostream>
 #include<vector>
 #include<string>
 #include<unordered_set>
 using namespace std;
 
 // This is a functional problem. You have to complete this function.
 // It takes as input two strings s and t.
 // It should return true if the strings are one edit distance apart,
 // else should return false.
 bool canConstruct(string & rans, string& magzine) {
     // write your code here.
     unordered_set<int> s;
     for(int i = 0; i < magzine.length(); i++){
         s.insert(magzine[i]);
     }
     
     for(int i = 0; i < rans.length(); i++){
         if(s.count(rans[i])){
             s.erase(rans[i]);
         }
         else return false;
     }
     return true;
 }
 
 int main (int argc,char** argv){
     string s,t;
     cin>>s;
     cin>>t;
     bool res=canConstruct(s,t);
     if(res==true){
         cout<<"true";
     }else{
         cout<<"false";
     }
 
 }