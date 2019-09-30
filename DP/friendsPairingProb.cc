using namespace std;

int M = 1000000007;

int friendsPairing(int n){
   long long int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    
    for( int i = 3; i <= n; i++){
        dp[i] = (dp[i-1]%M+((i-1)*dp[i-2])%M)%M;
    }
    return dp[n]%M;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans = friendsPairing(n);
        cout << ans << endl;
     }
	return 0;
}