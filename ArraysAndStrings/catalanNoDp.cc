using namespace std;

int catalan_no(int n){
    int dp[n+1] = {};
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < i; j++){
            dp[i]+=dp[j]*dp[i-1-j];
        }
    }
    return dp[n];
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << catalan_no(n) << endl;
     }
	return 0;
}