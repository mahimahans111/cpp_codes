#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written
 // This function takes as input an array
 // It should return required output
 
 int maxChunksToSorted(vector<int> &arr) {
     // Write your code here
     int n = arr.size();
     int maxl[n];
     int minr[n];
     minr[n-1] = arr[n-1];
     for(int i = n-2; i >= 0; i--){
         minr[i] = min(arr[i], minr[i+1]);
     }
     maxl[0] = INT_MIN;
     for(int i = 1; i < n; i++){
         maxl[i] = max(maxl[i-1], arr[i-1]);
     }
     
    //  for(int i = 0; i < n; i++) cout << minr[i]<< " ";
    //  cout << endl;
    //  for(int i = 0; i < n; i++) cout << maxl[i] << " ";
    //  cout << endl;
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(maxl[i] <= minr[i]) ans++;
    }
     return ans;
 }
 
 int main(int argc, char** argv){
     int n; cin>>n;
     vector<int> a(n);
     for(int i=0; i<n; i++){
         cin>>a[i];
     }
     cout<<maxChunksToSorted(a);
 }