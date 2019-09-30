#include<iostream>
 #include<vector>
 #include<string>
 #include<unordered_map>
 using namespace std;
 void solve(vector<int> &v) {
     //Write your code here
     unordered_map<int, int> m;
     int f = 0;
     m[f] = 0;
     int g = 1;
     m[f] = 1;
     for(int i = 0; f <= 1000; i++){
         int x = f;
         f = f+g;
         g = x;
         m[f] = 1;
     }
     
     for(int i = 0; i < v.size(); i++){
         if(m.count(v[i])) cout << v[i] << " ";
     }
 }
     
 int main(int argc,char** argv){
     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     solve(v);
 }