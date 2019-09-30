#include<iostream>
 #include<vector>
 #include<unordered_map>
 using namespace std;
 
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input an array.
 // It should return an integer value.
 int mt(vector<int> &arr) {
     unordered_map<int, int> m;
     // Write your code here
     for(int i = 0; i < arr.size(); i++){
         if(m.count(arr[i])){
             m[arr[i]]++;
         }
         else m[arr[i]] = 1;
     }
     
     int ans = 0;
     for(unordered_map<int, int> :: iterator it = m.begin(); it!=m.end(); it++){
         ans+=(it->second/2);
     }
     return 2*ans;
 }
 
 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> arr;
 
     // Input for array elements.
     for (int i = 0; i < n; i++) {
         int val;
         cin>>val;
         arr.push_back(val);
     }
 	 cout<<mt(arr);
 }