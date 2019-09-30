#include<iostream>
 #include<vector>
 #include<string>
 #include<unordered_map>
 using namespace std;
 
  // This is a functional problem. You have to complete this function.
 // It takes as input the an array of integers. It should return
 // the number occurring odd number of times.
 
 int solve(vector<int>& arr) {
     // write your code here.
     unordered_map<int, int> m;
     for(int i = 0; i < arr.size(); i++){
         if(m.count(arr[i])) m[arr[i]]++;
         else m[arr[i]] = 1;
     }
     for(unordered_map<int, int> :: iterator it=m.begin(); it!=m.end(); it++){
         if(it->second%2!=0) return it->first;
     }
 }
 
 //Don't make any changes here
 
 int main(int argc,char** argv){
 
     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     int res = solve(v);
     cout<<res<<endl;
 
 }