#include<bits/stdc++.h>
using namespace std;

int countWays(int n, int k){
	int dp[k+1][n+1]={};
	for(int i = 1; i <= n; i++){
		dp[1][i] = 1;
	}

	for(int i = 2; i <= k; i++){
		for(int j = 1; j <= n; j++){
			if(i <= j){
				dp[i][j] = dp[i-1][j-1]+(i*dp[i][j-1]);
			}
		}
	}
	return dp[n][k];

}

int main(){
	int n, k; cin >> n >> k;
	int ans = countWays(n, k);
	cout << ans;
}