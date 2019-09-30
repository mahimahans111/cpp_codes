#include<iostream>
 #include<vector>
 #include<string>
 #include<queue>
 using namespace std;
 
 // Function to display a matrix.
 void display(vector<int> &nums) {
     for (int i = 0; i < nums.size(); i++) {
         cout<<nums[i]<<" ";
     }
     cout<<endl;
 }
 
 // This is a functional problem. You have to complete this class.
 class KthLargest {
     priority_queue<int, vector<int>, greater<int> > pq;
     int size;
     public:
     KthLargest(int k, vector<int> nums) {
         // write your code here.
        size = k;
        for(int i = 0; i < k; i++){
            pq.push(nums[i]);
        }
        for(int i = k; i < nums.size(); i++){
            if(nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
         } 
     }
     
     int add(int val) {
         // write your code here.
         if(val>pq.top()){
             pq.pop();
             pq.push(val);
         }
         return pq.top();
  }
 
 };
 
 
 int main(int argc,char** argv){
             // Input for length of first array.
         int N;
         cin>>N;
         vector<int> intialStream (N);
 
         // Input for initial stream elements.
         for (int i = 0; i < intialStream.size(); i++) {
             cin>>intialStream[i];
         }
 
         int K,M;
         cin>>K>>M;
         vector<int> remainingStream(M);
 
         // Input for remaining stream elements.
         for (int i = 0; i < remainingStream.size(); i++) {
             cin>>remainingStream[i];
         }
 
         KthLargest obj(K, intialStream);
 
         for (int i = 0; i < remainingStream.size(); i++) {
             int kthLargest = obj.add(remainingStream[i]);
             cout<<kthLargest<<endl;
         }
 }