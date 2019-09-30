#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 vector<string> topKFrequent(vector<string> nums, int k) {
     //Write your code here	 
     unordered_map<string, int> m;
     
    priority_queue<pair<int, string> > pq;
    for(int i = 0; i < nums.size(); i++){
        if(m.count(nums[i])){
            m[nums[i]]++;
        }
        else m[nums[i]] = 1; 
    }
    
    for(unordered_map<string, int> :: iterator it = m.begin(); it!=m.end(); it++){
       pq.push(pair<int, string> (it->second, it->first));
    }
    vector<string> ans;
    for(int i = 0; i < k; i++){
        if(pq.empty()) ans.push_back("-1");
        else{ans.push_back(pq.top().second);
        pq.pop();
        }
    }
    return ans;
 }
 
 //Don't make any changes here
 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<string> arr;
     for (int i = 0; i < n; i++) {
         string val;
         cin>>val;
         arr.push_back(val);
     }
     int k;
     cin>>k;
     vector<string> res = topKFrequent(arr, k);
     sort(res.begin(), res.end());
     cout<<"[";
     for(int i=0; i<res.size(); i++){
         cout<<res[i];
         if(i != res.size() - 1){
             cout<<", ";
         }
     }
     cout<<"]";
 
 }