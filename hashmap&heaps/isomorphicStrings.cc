#include<iostream>
 #include<string>
 #include<unordered_map>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input 2 strings.
 // It should return a boolean value.
 bool isIsomorphic(string& s, string& t) {
     unordered_map<char, char> m;
     if(s.length()!=t.length()) return false;
     for(int i = 0; i < s.length(); i++){
         if(m.count(s[i])){
             if(m[s[i]]!=t[i]) return false;
         }
         else m[s[i]] = t[i];
     }
     return true;
     //Write your code here
 }
 int main(int argc,char** argv){
     string A,B;
     cin>>A;
     cin>>B;
     bool res=isIsomorphic(A, B);
     if(res==0){
         cout<<"false";
     }else{
         cout<<"true";
     }
 }