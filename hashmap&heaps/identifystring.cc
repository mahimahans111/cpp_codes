#include<bits/stdc++.h>
using namespace std;
 
 class myComparator{
     public:
   bool operator()(pair<int, char>a, pair<int, char> b){
       if(a.first == b.first) return a.second > b.second;
       return a.first < b.first;
   }  
 };
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 string reorganizeString(string str) {
     unordered_map<char, int> m;
     int n = str.length();
     for(int i = 0; i < str.length(); i++){
         if(m.count(str[i]))m[str[i]]++;
         else m[str[i]] = 1;
     }
     string anst = "";
         priority_queue<pair<int, char> , vector<pair<int, char> >, myComparator > pq;
     for(unordered_map<char, int> :: iterator it = m.begin(); it!=m.end(); it++){
         if(it->second > (n+1)/2) return anst;
         pq.push(pair<int, char>(it->second, it->first));
     }
     
     int cnt = 0;
     string ans = "";
     while(cnt < n){
         pair<int, char> p1;
         pair<int, char> p2;
         if(!pq.empty()){
        p1 = pq.top();
         pq.pop();
         ans+=p1.second;
         cnt++;
         }
         if(!pq.empty()){
           p2 = pq.top();
         pq.pop();
         ans+=p2.second;
         cnt++;
         }
         
         
         p1.first--;
         p2.first--;
         if(p1.first!=0)pq.push(p1);
         if(p2.first!=0)pq.push(p2);
     }
     return ans;
 }
 
 // -----------------------------------------------------
 
 int main(int argc, char** argv) {
     string s;
     cin>>s;
     cout<<reorganizeString(s);
     cout << endl;
 }