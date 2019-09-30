#include<bits/stdc++.h>
using namespace std;

int minJumps(vector<int> arr){
	int n = arr.size();
	if(n <= 1) return 0;
	int dp[n];
	dp[n-1] = 0;
	for(int i = n-2; i >= 0; i--){
		dp[i] = n+1;
		for(int j = 1; j <= arr[i]; j++){
			if(i+j< n)dp[i] = min(dp[i], 1+dp[i+j]);
		}
	}
	return dp[0];
}

int main(){
	int n, a; cin >> n;
	vector<int> arr;
	for(int i = 0; i < n; i++){
		cin >> a;
		arr.push_back(a);
	}
	cout << minJumps(arr);
}