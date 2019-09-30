#include<bits/stdc++.h>
using namespace std;

int maxSquareAll1s(vector<vector<int> >v, int n, int m){
    int dp[n][m] = {};
    int ans=-1;
    for(int i = 0; i < n; i++){
        dp[i][m-1] = v[i][m-1];
        ans = max(ans, dp[i][m-1]);
    }
    for(int j = 0; j < m; j++){
        dp[n-1][j] = v[n-1][j];
        ans = max(ans, dp[n-1][j]);
    }
    
    for(int i = n-2; i >= 0; i--){
        for(int j = m-2; j >= 0; j--){
            dp[i][j] =v[i][j] == 0? 0 : 1+min(dp[i+1][j], min(dp[i+1][j+1], dp[i][j+1]));
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int> > v;
        for(int i = 0; i < n; i++){
            vector<int>a;
            for(int j = 0; j < m; j++){
                int x; cin >> x;
                a.push_back(x);
            }
            v.push_back(a);
        }
        cout << maxSquareAll1s(v, n, m) << endl;
     }
	return 0;
}