#include<bits/stdc++.h>
using namespace std;

int mcm(int arr[], int n){
    int dp[n][n] = {};
    for(int gap = 1; gap < n-1; gap++){
        for(int i = 1, j = i+gap; j < n; j++, i++){
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++){
                int m = dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                dp[i][j] = min(dp[i][j], m);
            }
        }
    }
    
    return dp[1][n-1];
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cout << mcm(arr, n) << endl;
     }
	return 0;
}