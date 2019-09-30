#include<iostream>
 #include<vector>
 #include<unordered_map>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written
 // This function takes as input an array of string
 // It should return name of winning candidate
 
 vector<string> func(vector<string> &arr) {
     // Write your code here
     unordered_map<string, int> m;
     for(int i = 0; i < arr.size(); i++){
         if(m.count(arr[i])){
             m[arr[i]]++;
         }
         else m[arr[i]] = 1;
     }
     string ans;
     int mf = 0;
     for(unordered_map<string, int> :: iterator it = m.begin(); it!=m.end(); it++){
         if(it->second > mf){
             mf = it->second;
             ans = it->first;
         }
         if(it->second == mf && it->first < ans){
             ans = it->first;
         }
    }
    vector<string> v;
    v.push_back(ans);
    return v;
 }
 
 int main(int argc, char** argv){
     int n; cin>>n;
     vector<string> str;
     for (int i = 0; i < n; i++) {
         string s; cin>>s;
         str.push_back(s);
     }
     vector<string> res = func(str);
     cout<<res[0];
 }