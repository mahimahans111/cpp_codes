#include<iostream>
#include<vector>
#include<unordered_map>
 
 using namespace std;
     // This is a functional problem. You have to complete this function.
     // It takes as input an array A and a sum S.
     // You have to return the number of subarrays with sum S.
 
     int numSubarraysWithSum(vector<int> v, int S) {
         // write your code here.
         int rs = S;
         int ps = 0;
         int cnt = 0;
         unordered_map<int, int> m;
         m[0] = 1;
         for(int i = 0; i < v.size(); i++){
             ps+=v[i];
             if(m.count(ps-rs)){
                 cnt+=m[ps-rs];
             }
            if(m.count(ps))m[ps]++;
             else m[ps] = 1;
         }
         return cnt;
     }
 
     int main(int args,char** argv) {
         // Taking input for the array.
         int N; cin>>N;
         vector<int> array(N,0);
 
         for (int i = 0; i < N; i++) {
             cin>>array[i];
         }
 
         // Taking input for sum.
         int sum;cin>>sum;
 
         cout<<(numSubarraysWithSum(array, sum));
 
     }