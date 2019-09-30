#include<bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2, int n, int m){
    int dp[n+1][m+1] = {};
    for(int i = 0; i <= n; i++){
        dp[i][0] = i;
    }
    for(int j = 0; j <= m; j++){
        dp[0][j] = j;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1+min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
    }
    return dp[n][m];
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        cout << editDistance(s1, s2, n, m) << endl;
     }
    return 0;
}