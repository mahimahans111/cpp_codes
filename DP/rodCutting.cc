#include<bits/stdc++.h>
using namespace std;

int memo[100];

int maxProfitMemo(int arr[], int totalLen){
	if(totalLen == 0) return 0;

	if(memo[totalLen]!=-1) return memo[totalLen];

	int best = 0;
	for(int len = 1; len <= totalLen; len++){
		int netProfit = arr[len]+maxProfitMemo(arr, totalLen-len);
		best = max(best, netProfit);
	}
	memo[totalLen] = best;
	return best;
}

int maxProfitRec(int arr[], int totalLen){
	if(totalLen == 0) return 0;

	int best = 0;
	for(int len = 1; len <= totalLen; len++){
		int netProfit = arr[len]+maxProfitRec(arr, totalLen-len);
		best = max(best, netProfit);
	}
	return best;
}

int dp[100] = {};

int maxProfitDP(int arr[], int totalLen){

	for(int len = 1; len <= totalLen; len++){
		int best = 0;
		for(int piece = 1; piece <= len; piece++){
			int netProfit = arr[piece] + dp[len-piece];
			best = max(best, netProfit);
		}
		dp[len] = best;
	}
	return dp[totalLen];
}

int main(){
	int priceOfEachLen[100];
	int totalLen;
	cin >> totalLen;

	for(int eachPiece = 1; eachPiece <= totalLen; ++eachPiece){
		cin >> priceOfEachLen[eachPiece];
	}

	//clr memopad
	for(int i = 0; i <= totalLen; i++){
		memo[i] = -1;
	}

	int ans = maxProfitDP(priceOfEachLen, totalLen);
	cout << ans;
}