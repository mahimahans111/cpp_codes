#include<iostream>
 #include<string>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input 2 arrays and m, n as lengths.
 // It should return required output.
 vector<int> intersect(vector<int>& nums1, vector<int>& nums2)  
 {  
     unordered_map<int, int> m1, m2;
     for(int i = 0; i < nums1.size(); i++){
         if(m1.count(nums1[i])){
             m1[nums1[i]]++;
         }
         else m1[nums1[i]] = 1;
     }
     
     for(int i = 0; i < nums2.size(); i++){
         if(m2.count(nums2[i])){
             m2[nums2[i]]++;
         }
         else m2[nums2[i]] = 1;
     }
     
     vector<int> ans;
     
     for(unordered_map<int, int> :: iterator it = m1.begin(); it!=m1.end(); it++){
         if(m2.count(it->first)){
             int mini = min(it->second, m2[it->first]);
             for(int i = 0; i < mini; i++){
               ans.push_back(it->first);  
             }
         }
     }
     return ans;
     //Write your code here
 }
 
 
 int main(int argc,char** argv){
     int n ;
     cin>>n;
     vector<int> num1(n);
     for (int i = 0; i < n; i++) {
         
         cin>>num1[i];
     }
     int m;
     cin>>m;
     vector <int> num2(m);
     for (int i = 0; i < m; i++) {
         cin>>num2[i];
     }
 n
     vector<int> res=intersect(num1, num2);
     for(int i=0;i<res.size();i++)
         cout<<res[i]<<" ";
         cout << endl;
 }