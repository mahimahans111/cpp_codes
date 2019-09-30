#include<iostream>
 #include<vector>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input one array
 // It should return the required output
 
 int maxProfit(vector<int> &arr) {
     //Write your code here
     int n = arr.size();
     int b = 0, s = 0, c = 0;
     b = 0-arr[0];
     for(int i = 1; i < n; i++){
         int x = b;
         if(c-arr[i] > b){
             b = c-arr[i];
         }
         int y = s;
         if(x+arr[i] > s){
             s = x+arr[i];
         }
         c = y;
     }
     return s;
 }
 
 int main(int argc,char** argv){
 
     int n;
     cin>>n;
     vector<int> prices(n);
     for (int i = 0; i < n; i++){
         cin>>prices[i];
     }
     cout<<maxProfit(prices);
 }