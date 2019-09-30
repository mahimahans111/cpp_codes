#include<bits/stdc++.h>
using namespace std;

int waysToDecode(string str){
	int n = str.length();
	int dp[n];
	dp[0] = 1;
	for(int i = 1; i < n; i++){
		int num = 0;
		num = num*10+int(str[i-1]-'0');
		num = num*10+int(str[i]-'0');
		if(num <= 26){
			dp[i] = dp[i-1]+1;
		}
		else dp[i] = dp[i-1];
	}
	return dp[n-1];
}

int main(){
	string str; cin >> str;
	cout << waysToDecode(str);
}