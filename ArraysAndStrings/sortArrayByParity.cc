#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 
 // function to display an array.
 void display(vector<int> &arr) {
     for (int i = 0; i < arr.size(); i++) {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
 }
 
 
 // utility function, don't change the code of it.
 vector<int> sortResultEvenOdd(vector<int> &arr) {
     int i = 0;
 
     while (i < arr.size()) {
         if (arr[i] % 2 != 0) {
             sort(arr.begin(), arr.begin() + i);
             sort(arr.begin() + i, arr.end());
             return arr;
         }
         i++;
     }
 
     sort(arr.begin(), arr.end());
     return arr;
 
 }
 
 // This is a functional problem. You have to complete this function.
 // It takes as input an integer array. It should return
 // the required array.
 vector<int> sortArrayByParity(vector<int> &a) {
     // write your code here.
     int i = 0;
     int j = 0;
     int n = a.size();
     for(int j = 0; j < n; j++){
         if(a[j]%2 == 0){
             swap(a[j], a[i]);
             i++;
         }
     }
     return a;
 }
 
 int main(int argc, char** argv){
     int length;
     cin>>length;
     vector<int> arr(length);
 
     // Input for elements of array.
     for (int i = 0; i < arr.size(); i++) {
         cin>>arr[i];
     }
 
     vector<int> result = sortArrayByParity(arr);
     vector<int> sortedResult = sortResultEvenOdd(result);
     display(sortedResult);
 }