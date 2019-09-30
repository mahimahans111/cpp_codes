#include<bits/stdc++.h>
using namespace std;

int sum(pair<int, int> arr[], int i, int j){
    int ans = 0;
    for(int k = i; k <= j; k++) ans+=arr[k].second;
    return ans;
}

int countOptimalBSTs(pair<int, int> arr[], int n){
    sort(arr, arr+n);
    int ps[n] = {};
    ps[0] = arr[0].second;
    for(int i = 1; i < n; i++){
        ps[i] = ps[i-1]+arr[i].second;
    }
    int dp[n][n] = {};
    for(int i = 0; i < n; i++){
        dp[i][i] = arr[i].second;
    }
    for(int gap = 1; gap < n; gap++){
 
        for(int i = 0, j = i+gap; j < n; i++, j++){
                  dp[i][j] = INT_MAX;
            for(int k = i; k <= j; k++){
                dp[i][j] = min(((k>i)?dp[i][k-1]:0) + ((k<j)?dp[k+1][j]:0), dp[i][j]);
            }
            dp[i][j]+= sum(arr, i, j);
        }
    }
  
    return dp[0][n-1];
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        pair<int, int> arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i].first;
        }
        for(int i = 0; i < n; i++){
            cin >> arr[i].second;
        }
        
        cout << countOptimalBSTs(arr, n) << endl;
     }
    return 0;
}