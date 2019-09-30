#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 void print (vector<char> &v) {
     //Write your code here   
     int max = 0;
     unordered_map<int, int> m;
     m[0] = -1;
     int ps = 0;
     int ans = 0;
     for(int i = 0; i < v.size(); i++){
         if(v[i] == '1') ps+=1;
         else ps-=1;
         if(m.count(ps)){
             if(i-m[ps] > max) max = i-m[ps];
         }
        else{
            m[ps] = i;
        }
     }
     cout << max;
 }
     
 int main(int argc,char** argv){
     string s;
     cin>>s;
     vector<char> v(s.length());
     for(int i=0;i<s.length();i++){
         v[i]=s[i];
     }
     print(v);
 }