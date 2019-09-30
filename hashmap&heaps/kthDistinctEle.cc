#include<iostream>
 #include<vector>
 #include<string>
 #include<unordered_set>
 #include<unordered_map>
 using namespace std;
 // -----------------------------------------------------
 // This is a functional problem. Only this function has to be written.
 // This function takes as input an array,n length of array and k.
 // It should print required output.
 void solve(vector<int>& arr,int n,int k){
     //Write your code here
     unordered_set<int> s;
     unordered_set<int> s2;
     unordered_map<int, int> m;
     for(int i = 0; i < n; i++){
         if(m.count(arr[i])){
             m[arr[i]]++;
         }
         else m[arr[i]] = 1;
     }
     for(int i = 0; i < n; i++){
         if(m[arr[i]] == 1){
             s.insert(arr[i]);
         }
     }
     

     int x = 0;
     vector<int> a;
     int flag = 0;
     for(int i = 0; i < n; i++){
         if(s.count(arr[i])){
            if(!s2.count(arr[i])){
              if(x == k-1){flag = 1; cout << arr[i];}
              x++;
               s2.insert(arr[i]);   
            }
            
         }
     }
     if(flag == 0) cout << -1;
 }
 
 int main(int argc,char** argv){
     int n;
     cin>>n;
     
     vector<int> v(n);
     for(int i=0;i<n;i++)
         cin>>v[i];
     
     int k;
     cin>>k;
     solve(v,n,k);
 }