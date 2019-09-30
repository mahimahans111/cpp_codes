#include<iostream>
#include<unordered_set>
 using namespace std;
 
 int decimal(string s){
     int ans = 0;
     for(int i = 0; i < s.length(); i++){
         ans=2*ans+(s[i]-'0');
     }
     
     return ans;
 }
 
 // This is a functional problem. You have to complete this function.
 bool queryString(string &S, int N) {
 	 //Write your code here	 
 	 int n = S.length();
     unordered_set<int> set;
     for(int i = N/2+1; i <= N; i++){
         set.insert(i);
     }
     int s = 0;
     int e = 0;
     while(e < S.length() && s <= e){
         if(set.count(decimal(S.substr(s, e-s)))) set.erase(decimal(S.substr(s, e-s)));
         if(set.empty()) return true;
         while(e < S.length() && decimal(S.substr(s, e-s)) <= N){
             if(set.count(decimal(S.substr(s, e-s)))) set.erase(decimal(S.substr(s, e-s)));
             if(set.empty()) return true;
             e++;
         }
         while( decimal(S.substr(s, e-s)) > N){
             if(set.count(decimal(S.substr(s, e-s)))) set.erase(decimal(S.substr(s, e-s)));
             if(set.empty()) return true;
             s++;
         }
         if(set.count(decimal(S.substr(s, e-s)))) set.erase(decimal(S.substr(s, e-s)));
             if(set.empty()) return true;
     }
     
     while(s < e){
         if(set.count(decimal(S.substr(s, e-s)))) set.erase(decimal(S.substr(s, e-s)));
             if(set.empty()) return true;
             s++;
     }

     return false;
 }
 
 //Don't make any changes here.
 int main(int argc, char** argv){
     int n;
     cin>>n;
     string str;
     cin>>str;
     if(queryString(str, n)){
         cout<<"true";
     }else{
         cout<<"false";
     }
 }