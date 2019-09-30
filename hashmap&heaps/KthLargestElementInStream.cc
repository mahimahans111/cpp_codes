#include<iostream>
 #include<string>
 #include<vector>
 #include<queue>
 using namespace std;
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 void KthLargestEleInStream(vector<int> A, int K) {
     priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i < K-1 && i < A.size(); i++){
        cout << -1 << " ";
        pq.push(A[i]);
    } 
    pq.push(A[K-1]); cout << pq.top() << " ";
    for(int i = K; i < A.size(); i++){
        if(A[i] > pq.top()){
            pq.pop();
            pq.push(A[i]);
        }
        cout << pq.top() << " ";
    }
    
 }
 
 
 int main(int argc,char** argv){
 
     int n,k;
     cin>>n>>k;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
 
   KthLargestEleInStream(v,k);
 }