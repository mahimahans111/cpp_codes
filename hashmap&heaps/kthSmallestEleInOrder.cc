#include<bits/stdc++.h>
using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input length of array, value of k and array of length n
 // It should print k smallest elements in their original order
 void print_k_smallest_elements_in_their_original_order(int n,int k, vector<int> arr){
     priority_queue<pair<int, int> >pq; 
     for(int i = 0; i < k; i++){
         pq.push(pair<int, int>(arr[i], i));
     }
     for(int i = k; i < n; i++){
         if(arr[i] < pq.top().first){
             pq.pop();
             pq.push(pair<int, int>(arr[i], i));
         }
     }
    //  cout << pq.top().first;
     for(int i = 0; i < n; i++){
         if(arr[i] < pq.top().first){
             cout << arr[i] << " ";
         }
         else if(arr[i] == pq.top().first){
             cout << arr[i] << " ";
             pq.pop();
         }
     }
 }
 // -----------------------------------------------------
 
 int main(int argc, char** argv) {
 
     int n, k;
     cin>>n>>k;
 
     vector<int> arr;
     
     for (int i = 0; i < n; i++) {
         int a;
         cin>>a;
         arr.push_back(a);
     }
     print_k_smallest_elements_in_their_original_order(n, k, arr);
 }