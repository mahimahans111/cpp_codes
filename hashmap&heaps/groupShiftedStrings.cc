#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
 // This is a functional problem. You have to complete this function.
 // It takes as input the a string array. It return a list of list of
 // strings of strings with same shifting sequence grouped together.
 
 vector<vector<string> > groupStrings(vector <string>& strs){
          vector<vector<string> > ans;
    unordered_map<string, vector<string> > m;
     for(int i = 0; i < strs.size(); i++){
         if(strs[i].length() == 1){
             if(m.count("**"))m["**"].push_back(strs[i]);
             else {
                vector<string> va;
                va.push_back(strs[i]);
                m["**"] = va;                
             }
         }
         else{
             string cur = "";
             for(int j = 0; j < strs[i].length()-1; j++){
                int diff = strs[i][j+1]-strs[i][j];
                if(diff<0)diff+=26;
                 cur+=char(diff+'0');
                 cur+='*';
             }
             if(m.count(cur)){
                m[cur].push_back(strs[i]);
             }
             else{
                vector<string> va;
                va.push_back(strs[i]);
                m[cur] = va;
             }
         }
     }
     
     for(unordered_map<string, vector<string> > :: iterator it = m.begin(); it != m.end(); it++){
         // cout << it->first << " " << it->second << "-----";
         sort(it->second.begin(), it->second.end());
       ans.push_back(it->second);

     }
     return ans;
 }
 
 void display(vector<vector<string> > &v){
     for(int i=0;i<v.size();i++){
         for(int j=0;j<v[i].size();j++){
             cout<<v[i][j]<<" ";
         }
         cout<<endl;
     }
 }
 //function to sort the lists
 bool sortcol( const vector<string>& l1, 
                const vector<string>& l2 ) { 
  
     if (l1.size() != l2.size()) {
         return l2.size()<l1.size();
     } else {
         if(l1.size()==0){
             return false;
         }else{
             return l1[0]<l2[0];
         }
     }
  
 } 
 int main(int argc,char ** argv){
 
     int n;
     cin>>n;
     vector<string> strs;
     for(int i=0;i<n;i++){
         string a;
         cin>>a;
         strs.push_back(a);
     }
     
     vector<vector<string> > res;
     res=groupStrings(strs);
     for(vector<string> v:res){
         sort(v.begin(),v.end());
     }
     sort(res.begin(),res.end(),sortcol);
     display(res);
 }