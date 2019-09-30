#include<iostream>
 #include<vector>
 #include<string>
 #include<unordered_map>
 using namespace std;
 int maxlen(vector<int> &arr,int n) {
     //Write your code here  
     int sum = 0;
     unordered_map<int, int> m;
     m[0] = -1;
     int ps = 0;
     int ans = 0;
     for(int i = 0; i < n; i++){
         ps+=arr[i];
         if(m.count(ps-sum)){
             if(i-m[ps] > ans) ans = i-m[ps];
         }
        else m[ps] = i;
     }
     return ans;
 }
     
 int main(int argc,char** argv){
     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     cout<<maxlen(v,n)<<endl;
 }