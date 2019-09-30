#include<iostream>
 #include<vector>
 #include<string>
 #include<queue>
 using namespace std;
 
 // Function to display a matrix.
 void display(vector<vector<int> >&mat) {
 
     for (int i = 0; i < mat.size(); i++) {
         for (int j = 0; j < mat[0].size(); j++) {
             cout<<mat[i][j]<<" ";
         }
         cout<<endl;
     }
 }
 
 // This is a functional problem. You have to complete this function.
 // It takes as input a matrix and K.
 // It should return the Kth smallest element from the matrix.
 int findKthSmallest(vector<vector<int> >& nums, int k) {
     // write your code here.
     priority_queue<int> pq;
     int cnt = 0;
     for(int i = 0; i < nums.size(); i++){
         for(int j = 0; j < nums[i].size(); j++){
             if(cnt < k){
                 pq.push(nums[i][j]);
                 cnt++;
             }
             else{
                 if(nums[i][j] < pq.top()){
                     pq.pop();
                     pq.push(nums[i][j]);
                 }
             }
         }
     }
     return pq.top();
 }
 
 int main(int argc,char** argv){
     
      // Input for length of first array.
         int N;
         cin>>N;
 
         vector<vector<int> > mat(N,vector<int>(N) );
 
         // Input for matrix elements.
         for (int i = 0; i < mat.size(); i++) {
             for (int j = 0; j < mat[0].size(); j++) {
                 cin>>mat[i][j];
             }
         }
 
         int K;
         cin>>K;
         int result = findKthSmallest(mat, K);
 
         cout<<result<<endl;
 }