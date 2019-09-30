#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int> coins, int amount){
    int n = coins.size();
    int ans[amount+1] = {};
        ans[0] = 1;

        for(int j = 0; j < coins.size(); j++){
            for(int i = 1; i <= amount; i++){
                if(i-coins[j]>=0) ans[i] += ans[i-coins[j]];
            }
        }
        return ans[amount];
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr;
        int a;
        for(int i = 0; i < n; i++){
            cin >> a;
            arr.push_back(a);
        }
        int k; cin >> k;
        cout << coinChange(arr, k) << endl;
     }
	return 0;
}