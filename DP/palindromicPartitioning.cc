using namespace std;

int palindromicPartitioning(string s){
    int n = s.length();
    
    int dp[n][n] = {};
    for(int gap = 1; gap < n; gap++){
        for(int i = 0, j = i+gap; j < n; i++, j++){
            if(s[i] == s[j] && dp[i+1][j-1] == 0) dp[i][j] = 0;
            else{
                dp[i][j] = INT_MAX;
            for(int k = i; k <= j-1; k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+1);
            }
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    int t; cin >> t;
    while(t--){
        string str; cin >> str;
        cout << palindromicPartitioning(str) << endl;
     }
	return 0;
}