#include<iostream>
 #include<vector>
 #include<unordered_map>
 #include<string>
 using namespace std;
 vector<int> anagramMappings(vector<int>& num1,vector<int> &num2){
     vector<int> p;
     unordered_map<int, int> m;
     for(int i = 0; i < num2.size(); i++){
         m[num2[i]] = i;
     }
     for(int i = 0; i < num1.size(); i++){
         p.push_back(m[num1[i]]);
     }
    return p; 
 }
 
 void display(vector<int> &v){
     for(int i=0;i<v.size();i++){
         cout<<v[i]<<" ";
     }
 }
 int main(int argc,char ** argv){
 
     int n;
     cin>>n;
     vector<int> num1;
     vector<int> num2;
     for(int i=0;i<n;i++){
         int a;
         cin>>a;
         num1.push_back(a);
     }
     for(int i=0;i<n;i++){
         int a;
         cin>>a;
         num2.push_back(a);
     }
     vector<int> res;
     res=anagramMappings(num1,num2);
     display(res);
 
 }