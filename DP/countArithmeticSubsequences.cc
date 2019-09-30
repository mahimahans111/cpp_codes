#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll countAPSub(ll arr[], ll n){
	map<ll, ll> maps[n];

	ll cnt = 0;
	for(ll i = 1; i < n; i++){
		for(ll j = 0; j < i; j++){
			ll dif = arr[i]-arr[j];
			maps[i][dif] = maps[j][dif]+1;
			cnt+=maps[j][dif];
		}
	}
	return cnt;
}

int main(){
	ll n; cin >> n;
	ll arr[n];
	for(ll i = 0; i < n; i++) cin >> arr[i];

	cout << countAPSub(arr, n);	
}