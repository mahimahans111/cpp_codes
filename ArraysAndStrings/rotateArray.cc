#include<iostream>
 #include<vector>
 using namespace std;
 
 //This is a functional problem, complete this function only.
 void rotate(vector<int> &a, int k) {
     // Write your code here
     int n = a.size();
     vector<int>extra;
     for(int i = 0; i < n-k; i++){
         extra.push_back(a[i]);
     }
     for(int i = 0; i < k; i++){
         a[i] = a[i+n-k];
     }
     int ind = 0;
     for(int i = k; i < n; i++){
         a[i] = extra[ind];
         ind++;
     }
     
     
 }
 
 // Don't make any changes here
 int main(int argc, char** argv){
     int n, k;
     cin>>n>>k;
     vector<int> arr(n);
     for (int i = 0; i < n; i++) {
         cin>>arr[i];
     }
     rotate(arr, k);
     for (int v : arr)
         cout<<v<<" ";
 }