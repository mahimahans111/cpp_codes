#include<iostream>
#include<map>
#include<queue>
 using namespace std;    
     
      class myComparator{
     public:
   bool operator()(pair<char, int> a, pair<char, int> b){
    //   if(a.second == b.second) return a.first > b.first;
       return a.second < b.second;
   }  
 };
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.    
 string frequencySort(string arr) {
     //Write your code here
     int n = arr.length();
    map<char, int> m;
     for(int i = 0; i < n; i++){
         if(m.count(arr[i])) m[arr[i]]++;
         else m[arr[i]] = 1;
     }
     
     priority_queue <pair<char, int>, vector<pair<char, int> >, myComparator> pq;
     for(map<char, int> :: iterator it = m.begin(); it!=m.end(); it++){
         pq.push(pair<char, int> (it->first, it->second));
     }
     
     while(!pq.empty()){
         for(int i = 0; i < pq.top().second; i++){
         cout << pq.top().first;
         }
         pq.pop();
     }

 }
 
 //Dont make changes here
 int main(int argc, char** argv){
     string s;
     cin>>s;
     //cout<<frequencySort(s);
     frequencySort(s);
 }