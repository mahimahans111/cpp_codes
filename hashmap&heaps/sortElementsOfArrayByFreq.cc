#include<iostream>
 #include<vector>
 #include<unordered_map>
 #include<queue>
 using namespace std;
 
 
 class myComparator{
     public:
   bool operator()(pair<int, int> a, pair<int, int> b){
       if(a.second == b.second) return a.first > b.first;
       return a.second < b.second;
   }  
 };
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 void sortByFreq(vector<int> arr, int n) {
     unordered_map<int, int> m;
     for(int i = 0; i < n; i++){
         if(m.count(arr[i])) m[arr[i]]++;
         else m[arr[i]] = 1;
     }
     
     priority_queue <pair<int, int>, vector<pair<int, int> >, myComparator> pq;
     for(unordered_map<int, int> :: iterator it = m.begin(); it!=m.end(); it++){
         pq.push(pair<int, int> (it->first, it->second));
     }
     
     while(!pq.empty()){
         for(int i = 0; i < pq.top().second; i++){
         cout << pq.top().first << " ";
         }
         pq.pop();
     }
     // Write your code here
 }
 
 //Dont make changes here
 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> arr;
     for(int i=0;i<n;i++){
         int val;
         cin>>val;
         arr.push_back(val);
     }
     sortByFreq(arr, n);
 }