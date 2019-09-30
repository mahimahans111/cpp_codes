#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 int count(vector<vector<int> > &A) {
     //Write your code here
     unordered_map<int, int> m;
 	 vector<int> str = A[0];
 	 for(int i = 0; i < str.size(); i++){
 	     if(m.count(str[i]))m[str[i]]++;
 	     else m[str[i]] = 1;
 	 }
 	 
 	 int ans;
 	 for(int i = 1; i < A.size(); i++){
 	     vector<int> cur = A[i];
 	     unordered_map<int, int> curMap;
 	     for(int i = 0; i < cur.size(); i++){
 	         if(m.count(cur[i])){
 	             if(curMap.count(cur[i])){
 	                 curMap[cur[i]]++;
 	             } 
 	             else curMap[cur[i]] = 1;
 	             m[cur[i]]--;
 	             if(m[cur[i]] == 0)m.erase(cur[i]);
 	         }
 	     }
 	     m.clear();
 	     m= curMap;
 	     ans = curMap.size();
 	     curMap.clear();
 	 }
 	 return ans;
 }
 
 //Don't make any changes here
 
 int main(int argc,char** argv){
 
     int n;
     cin>>n;
     vector<vector<int> > v(n,vector<int>(n));
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             cin>>v[i][j];
         }
     }
     cout<<count(v)<<endl;
 }