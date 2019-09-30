#include<iostream>
 #include<vector>
 #include<unordered_set>
 using namespace std;
 
 // function to display an array.
 void display(vector<int> &arr) {
     for (int i = 0; i < arr.size(); i++) {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
 }
 
 // function to verify the result. just ignore it.
 bool verify(vector<int> &arr, int N, int K) {
     if (arr.size() < N) {
         return false;
     }
     vector<bool> a(N+1);
     unordered_set<int> set;
     for (int i = 0; i < arr.size(); i++) {
         if (a[arr[i]]) {
             return false;
         } else {
             a[arr[i]] = true;
         }
         if (i == N - 1) {
             break;
         } else {
             if (set.find(abs(arr[i] - arr[i + 1])) == set.end()) {
                 set.insert(abs(arr[i] - arr[i + 1]));
             }
         }
     }
     if (set.size() != K) {
         return false;
     }
     return true;
 }
 
 // This is a functional problem. You have to complete this function.
 // It takes as input n and k. It should return the resultant array.
 vector<int> constructArray(int n, int k) {
     // write your code here.
     vector<int> ans;
     int e = k+1;
     int s = 1;
     int flag = 0;
     for(int i = 1; i <= k+1; i++){
         if(flag == 0){
             ans.push_back(s);
             s++;
         }
         else{
             ans.push_back(e);
             e--;
         }
         flag = 1-flag;
     }
     for(int i = k+2; i <= n; i++){
         ans.push_back(i);
     }
     return ans;
 }
 
 int main(int argc, char** argv){
     int N, K;
     cin>>N>>K;
 
     vector<int> result = constructArray(N, K);
     if (verify(result, N, K)) {
         cout<<"Nice Arrangement";
     } else {
         cout<<"Try Harder";
     }
 }