#include<iostream>
 #include<vector>
 using namespace std;
 
 // This is a functional problem. You have to complete this function.
 int arrayNesting(vector<int> &arr) {
     //Write your code here
     int n = arr.size();
     vector<int>visited(n, 0);
     int maxi = 0;
     for(int i = 0; i < n; i++){
         if(!visited[i]){
             int cnt = 0;
             int k = i;
             visited[i] = 1;
             while(true){
                 k = arr[k];
                 cnt++;
                 if(visited[k] == 1){
                     break;
                 }
                 visited[k] = 1;
             }
             if(cnt > maxi) maxi = cnt;
         }
     }
     return maxi;
 }
 
 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> arr(n);
     for (int i = 0; i < arr.size(); i++) {
         cin>>arr[i];
     }
     cout<<arrayNesting(arr);
 }