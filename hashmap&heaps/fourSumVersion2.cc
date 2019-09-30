#include <iostream>
 #include <algorithm>
 #include <vector>
 #include<bits/stdc++.h>
 using namespace std;
 
 int fourSumCount(vector<int> &a, vector<int> &b, vector<int> &c, vector<int> &d)
 {
  int cnt = 0;
     int n = a.size();
    map<int, int> msum;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            int sum = a[i]+b[j];
            if(msum.count(sum)) msum[sum]++;
            else msum[sum] = 1;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int s = c[i]+d[j];
            
            s = 0-s;
            if(msum.count(s))cnt+=msum[s];
        }
    }
    
    
    return cnt;   
     
 }
 
 int main(int args, char **argv)
 {
     int n;
     cin >> n;
     vector<int> A(n, 0);
     vector<int> B(n, 0);
     vector<int> C(n, 0);
     vector<int> D(n, 0);
 
     for (int i = 0; i < n; i++)
     {
         cin >> A[i];
     }
 
     for (int i = 0; i < n; i++)
     {
         cin >> B[i];
     }
     for (int i = 0; i < n; i++)
     {
         cin >> C[i];
     }
     for (int i = 0; i < n; i++)
     {
         cin >> D[i];
     }
 
     cout << fourSumCount(A, B, C, D);
 }