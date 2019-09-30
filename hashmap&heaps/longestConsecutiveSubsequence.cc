#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 int consecuitveSub(vector<int> &v,int n) {
     //Write your code here  
     unordered_map<int, bool> m;
     for(int i = 0; i < n; i++){
         m[v[i]] = true;
     }
     for(int i = 0; i < n; i++){
         if(m.count(v[i]-1)) m[v[i]] = false;
     }
     int max = 0;
     for(unordered_map<int, bool>:: iterator it = m.begin(); it != m.end(); it++){
         if(it->second == true){
             int ans = 1;
             int n = it->first;
             while(true){
                if(m.count(n+1)){
                    ans++;
                    n++;
                }
                else break;
             }
             if(ans > max) max = ans;
         }
     }
     return max;
 }
     
 int main(int argc,char** argv){
     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     cout<<consecuitveSub(v,n)<<endl;
 }