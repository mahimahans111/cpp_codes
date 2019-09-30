#include<iostream>
 #include<vector>
 using namespace std;

 int CountWays(int n, int k) {
     //Write your code here
     int s = 0; int d = k;
     for(int i = 2; i <= n; i++){
         int x = s;
         s = d;
         d = (x+d)*(k-1);
     }
     return s+d;
 }
 
 int main(int argc,char** argv){
     int n,k;
     cin>>n>>k;
     cout<<CountWays(n,k)<<endl;
 }