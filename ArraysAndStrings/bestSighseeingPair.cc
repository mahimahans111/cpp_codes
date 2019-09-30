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
 // It takes as input an integer array. It should return the maximum
 // score of a pair.
 int maxScoreSightseeingPair(vector<int> &A) {
     // write your code here.
     int n = A.size();
     int max = A[0];
     int maxi = 0;
     int ans = -1;
     for(int i = 1; i < n; i++){
         if(A[i]+max-(i-maxi) > ans) ans = A[i]+max-(i-maxi);
         
         if(A[i] > max-(i-maxi)){
             max = A[i];
             maxi = i;
         }
         
     }
     return ans;
 }
 
 int main(int argc, char** argv){
     int N;
     cin>>N;
     vector<int> arr(N);
     for (int i = 0; i < arr.size(); i++) {
         cin>>arr[i];
     }
     cout<<maxScoreSightseeingPair(arr);
 }