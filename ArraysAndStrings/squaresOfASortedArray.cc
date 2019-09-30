#include<iostream>
 #include<vector>
 using namespace std;
 
 // function to display an array.
 void display(vector<int> &arr) {
     for (int i = 0; i < arr.size(); i++) {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
 }
 
 // This is a functional problem. You have to complete this function.
 // It takes as input an integer array. It should return
 // the required array.
 vector<int> sortedSquares(vector<int> &arr) {
    int n = arr.size();
    int i = 0;
    int j = n-1;
    vector<int> ans(n, 0);
    int k = n-1;
    while(k >= 0){
        if(arr[i]*arr[i] >= arr[j]*arr[j]){
            ans[k] =  arr[i]*arr[i];
            i++;
        }
        else{
            ans[k] = arr[j]*arr[j];
            j--;
        }
        k--;
    }
    return ans;
 }
 
 int main(int argc, char** argv){
     int length;
     cin>>length;
     vector<int> arr(length);
 
     // Input for elements of array.
     for (int i = 0; i < arr.size(); i++) {
         cin>>arr[i];
     }
 
     vector<int> result = sortedSquares(arr);
     display(result);
 
 }