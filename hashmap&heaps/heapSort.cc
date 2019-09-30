#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 
 void printArray(vector<int> &arr) {
     int n = arr.size();
     for (int i = 0; i < n; ++i)
         cout<<arr[i]<<" ";
     cout<<endl;
 }
 
 // -----------------------------------------------------
 // This is a functional problem. Only these functions have to be written.
 // This function takes as input an array.
 
  void heapify(vector<int> &arr, int n, int i) {
     //Write your code here
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
  
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        heapify(arr, n, largest); 
    } 
 }
 
 void sort(vector<int> &arr) {
   int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    for (int i=n-1; i>=0; i--) 
    { 
        swap(arr[0], arr[i]); 
  
        heapify(arr, i, 0); 
    } 
 }
 

 
 // -----------------------------------------------------
 
 int main(int argc, char** argv){
     int n; 
     cin>>n;
     vector<int> arr;
     for(int i=0;i<n;i++){
         int val; cin>>val;
         arr.push_back(val);
     }
     sort(arr);  
     printArray(arr); 
 }