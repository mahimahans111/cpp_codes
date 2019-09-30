#include<bits/stdc++.h>
using namespace std;

int longestPalindromicSubsequence(string s){
    int n = s.length();
    int dp[n][n] = {};
    
    for(int i = 0; i < n; i++){
        dp[i][i] = 1;
        if(i!=n-1){
           if(s[i] == s[i+1]){
                dp[i][i+1] = 2;
          }
          else dp[i][i+1] = 1;
        }
    }
    
    for(int gap = 2; gap < n; gap++){
        for(int i = 0, j = i+gap; j < s.length(); j++, i++){
            if(s[i] == s[j]){
                dp[i][j] = dp[i+1][j-1]+2;
            }
            else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][n-1];
   
}

int main(){
    int t; cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << longestPalindromicSubsequence(s) << endl;
     }
	return 0;
}