#include<bits/stdc++.h>
using namespace std;

int lis(int arr[100], int n){
	int dp[n];

	for(int i = 0; i < n; i++) dp[i] = 1;

	int maxi = 0;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(arr[j] < arr[i]){
				int curLen = 1+dp[j];
				dp[i] = max(curLen, dp[i]);
			}
		}
		maxi = max(maxi, dp[i]);
	}	
	return n-maxi;
}

int main(){
    int t; cin >> t;
    while(t--){
    int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int ans = lis(arr, n);
	cout << ans << endl;  
    }

}