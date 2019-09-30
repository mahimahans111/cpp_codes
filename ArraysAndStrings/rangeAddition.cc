#include<iostream>
 #include<vector>
 #include<string>
 using namespace std;
 // This is a functional problem. You have to complete this function.
 // It takes as input a length and a 2D array of update operations.
 // It should return the modified array.
 vector<int> getModifiedArray(int length, vector<vector<int> >& updates) {
     // write your code here. 
     int k = updates.size();
     int n = length;
     vector<int> arr(n, 0);
     for(int i = 0; i < n; i++) arr[i] = 0;
     
     for(int i = 0; i < k; i++){
         int fidx = updates[i][0];
         int lidx = updates[i][1];
         int inc = updates[i][2];
         arr[fidx]+=inc;
         if(lidx+1 < n){
             arr[lidx+1]-=inc;
         }
     }
     
     for(int i = 1; i < n; i++){
        arr[i] += arr[i-1];    
     }
     return arr;
 }
 // function to display an array.
 void display(vector<int> & arr) {
 
     for (int i = 0; i < arr.size(); i++) {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
 }
 
 int main(int argc,char** argv){
     
     // Input for length of first array.
     int length ;
     cin>>length;
 
     int K;
     cin>>K;
 
     vector<vector<int> > updates(K,vector<int>(3));
 
     for (int i = 0; i < updates.size(); i++) {
         for (int j = 0; j < updates[i].size(); j++) {
             cin>>updates[i][j];
         }
     }
 
     vector<int> res= getModifiedArray(length, updates);
     display(res);
 }