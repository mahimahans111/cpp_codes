#include<iostream>
 #include<vector>
 using namespace std;
 
 int majorityElement(vector<int>& arr) {
     //Write your code here
     int max = arr[0];
     int maxf = 1;
     int n = arr.size();
     for(int i = 1; i < n; i++){
         if(arr[i] == max){
             maxf++;
         }
         else{
             if(maxf > 1){
                 maxf--;
             }
             else{
                 max = arr[i];
                 maxf = 1;
             }
         }
     }
     
     int f = 0;
     for(int i = 0; i < n; i++){
         if(arr[i] == max)f++;
     }
     if(f > n/2) return max;
     return -1;
 }
 
 
 int main(int argc,char**argv){
 
     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }   
     int res=majorityElement(v);
     cout<<res<<endl;
 }