#include<bits/stdc++.h>
using namespace std;

int memo[100][100];

int maxProfit(int arr[], int be, int en, int year){
	if(be > en) return 0;

	int q1 = arr[be]*year + maxProfit(arr, be+1, en, year+1);
	int q2 = arr[en]*year + maxProfit(arr, be, en-1, year+1);
	int ans = max(q1, q2);
	return ans;
}

int maxProfitMemoization(int arr[], int be, int en, int year){
	if(be > en) return 0;

	if(memo[be][en] != -1) return memo[be][en];

	int q1 = arr[be]*year + maxProfitMemoization(arr, be+1, en, year+1);
	int q2 = arr[en]*year + maxProfitMemoization(arr, be, en-1, year+1);
	int ans = max(q1, q2);
	return ans;
}

int maxProfitBottomUp(int arr[], int n){
	int dp[100][100] = {};
	int year = n;

	for(int i = 0; i < n; i++){
		dp[i][i] = year*arr[i];
	}
	--year;

	for(int len = 2; len <= n; len++){
		int srt = 0;
		int end = n-len;
		while(srt <= end){
			int endWindow = srt+len-1;
			dp[srt][endWindow] = max(
				arr[srt]*year + dp[srt+1][endWindow],
				arr[endWindow]*year + dp[srt][endWindow-1]
				);
			srt++;
		}
		--year;
	}
}

int main(){
	int arr[100];
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	memset(memo, -1, sizeof(memo));

	int ans = maxProfit(arr, 0, n-1, 1);
	cout << ans;
}