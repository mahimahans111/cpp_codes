#include<bits/stdc++.h>
using namespace std;

int optimalGame(int arr[], int n){
    int dp[n][n] = {};
    
    for(int i = 0; i < n; i++) dp[i][i] = arr[i];
    for(int i = 0; i < n-1; i++){
        dp[i][i+1] = max(arr[i], arr[i+1]);
    }
    
    for(int gap = 2; gap < n; gap++){
        for(int i = 0, j = i+gap; j < n; i++, j++){
            dp[i][j] = max(
                arr[i]+min(dp[i+1][j-1], dp[i+2][j]),
                arr[j]+min(dp[i+1][j-1], dp[i][j-2])    
                );
        }
    }
    return dp[0][n-1];
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cout << optimalGame(arr, n) << endl;
     }
	return 0;
}