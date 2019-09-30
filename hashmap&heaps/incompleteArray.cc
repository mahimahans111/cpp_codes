#include<iostream>
 #include<string>
 #include<unordered_set>
 #include<vector>
 
 using namespace std;
 int incomplete(vector<int> v) {
     int min = INT8_MAX;
     int max = INT8_MIN;
     unordered_set<int> s;
     for(int i = 0; i < v.size(); i++){
         if(v[i] > max) max = v[i];
         if(v[i] < min) min = v[i];
             s.insert(v[i]);
     }
     int ans = max-min+1-s.size();
     return ans;
 //write your code here
 }
 
 
 int main(int argc,char** argv){
     int n;
     cin>>n;
     vector<int > v;
     for(int i=0;i<n;i++){
         int a;
         cin>>a;
         v.push_back(a);
     }
     cout<<incomplete(v)<<endl;
 }