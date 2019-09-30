#include<iostream>
 #include<vector>
 #include<string>
 #include<unordered_map>
 using namespace std;
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input an array and n length of array.
 // It should return a boolean value.
 void solve(vector<int>& arr,int k) {
 // write your code here.
    unordered_map<int, int> m;
    for(int i = 0; i < arr.size(); i++){
        if(m.count(arr[i])){
            m[arr[i]]++;
            if(m[arr[i]] == k) m.erase(arr[i]);
        }
        else m[arr[i]] = 1;
    }
    for(unordered_map<int, int> :: iterator it = m.begin(); it!=m.end(); it++){
        if(it->second==1){
            cout << it->first;
            break;
        }
    }
 }
 
 //Don't make any changes here
 
 int main(int argc,char** argv){
 
     int n,k;
     cin>>n;
     cin>>k;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     solve(v,k);
 
 }