#include<iostream>
 #include<vector>
 #include<string>
 #include<queue>
 using namespace std;
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input an array,n length of array and k.
 // It should print required output.
 void solve(int n,vector<int>& arr,int k){
     //Write your code here
     priority_queue<int> pq;
     for(int i = 0; i < n; i++){
         pq.push(arr[i]);
     }
     for(int i = 0; i < k; i++){
         cout << pq.top() << " ";
         pq.pop();
     }
 }
 
 int main(int argc,char** argv){
     int n;
     cin>>n;
     
     vector<int> v(n);
     for(int i=0;i<n;i++)
         cin>>v[i];
     
     int k;
     cin>>k;
     solve(n,v,k);
 }