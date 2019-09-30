#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    int dp[n+1][m+1] = {};
    
    for(int i = 0; i < n; i++){
        dp[0][m] = 0;
    }
    
    for(int i = 0; i < m; i++){
        dp[n][i] = 0;
    }
    
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i+1][j+1]+1;
            }
            else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    return dp[0][0];
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        cout << lcs(s1, s2) << endl;
     }
	return 0;
}