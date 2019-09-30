#include<iostream>
 #include<string>
 #include<vector>
 #include<unordered_set>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input two arrays and their lengths 
 // Print required output
 void solve(vector<int>& a, vector<int>& b,int n, int m)  
 {  
     //Write your code here
     unordered_set<int> s;
     for(int i = 0; i < a.size(); i++){
         s.insert(a[i]);
     }
     
     int ans = 0;
     for(int i = 0; i < b.size(); i++){
         if(s.count(b[i])){
             ans++;
             s.erase(b[i]);
         }
     }
     cout << ans;
 }
 
 
 int main(int argc,char** argv){
     int n ;
     cin>>n;
     vector<int> num(n);
     for (int i = 0; i < n; i++) {
         
         cin>>num[i];
     }
     int m;
     cin>>m;
     vector <int> num2(m);
     for (int i = 0; i < m; i++) {
         cin>>num2[i];
     }
     solve(num, num2, n, m);
 }