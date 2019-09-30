#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 
 
 //this is a functional problem
 vector<char> commonChars(vector<string>& A){
 	 //write your code here
 	 vector<char> ans;
 	 
 	 unordered_map<char, int> m;
 	 string str = A[0];
 	 for(int i = 0; i < str.length(); i++){
 	     if(m.count(str[i]))m[str[i]]++;
 	     else m[str[i]] = 1;
 	 }
 	 
 	 for(int i = 1; i < A.size(); i++){
 	     string cur = A[i];
 	     unordered_map<char, int> curMap;
 	     for(int i = 0; i < cur.length(); i++){
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
 	     curMap.clear();
 	 }
 	 
 	 for(unordered_map<char, int> :: iterator it = m.begin(); it!=m.end(); it++){
 	     for(int j = 0; j < it->second; j++){
 	         ans.push_back(it->first);
 	     }
 	 }
 	 return ans;
 }
 
 void display(vector<char> &ans){
     cout<<"[";
         for(int j=0;j<ans.size();j++){
             cout<<ans[j];
             if(j!=ans.size()-1){
                 cout<<", ";
             }            
         }
     cout<<"]"<<endl;
 }
 int main(int argc,char ** argv){
 
     int n;
     cin>>n;
     vector<string> A;
     for(int i=0;i<n;i++){
         string a;
         cin>>a;
         A.push_back(a);
     }
     vector<char> res;
     res=commonChars(A);
     sort(res.begin(),res.end());
     display(res);
 
 }