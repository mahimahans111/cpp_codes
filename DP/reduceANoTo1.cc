#include<bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;

int memo[10000];

int reduceNoRec(int n){
	if(n == 1) return 0;
	int q1 = inf, q2 = inf, q3 = inf;

	if(n%3 == 0) q1 = 1 + reduceNoRec(n/3);
	if(n%2 == 0) q2 = 1 + reduceNoRec(n/2);
	q3 = 1 + reduceNoRec(n - 1);

	return min(q1, min(q2, q3));
}

int reduceNoMemoize(int n){
	if(n == 1) return 0;

	int q1 = inf, q2 = inf, q3 = inf;

	if(memo[n] != -1) return memo[n];

	if(n%3 == 0) q1 = 1+reduceNoMemoize(n/3);
	if(n%2 == 0) q2 = 1+reduceNoMemoize(n/2);
	q3 = 1+reduceNoMemoize(n-1);

	memo[n] = min(q1, min(q2, q3));
	return memo[n];
}


int reduceNoDP(int n){
	int dp[10000];
	dp[0]=0; dp[1]=0;
	dp[2]=1; dp[3]=1;
	if(n == 1){
		return 0;
	}

	for(int i = 4; i <= n; i++){
		int q1 = inf, q2 = inf, q3 = inf;
		if(!i%3)q1 = 1+dp[n/3];
		if(!i%2)q2 = 1+dp[n/2];
		q3 = 1+dp[n-1];
		dp[i] = min(q1, min(q2, q3));
	}
	return dp[n];
}

int main(){
	int n; cin >> n;
	fill(memo, memo+n+1, -1);
	int ans = reduceNoRec(n);
	cout << ans;
}