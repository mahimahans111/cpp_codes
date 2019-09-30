#include<bits/stdc++.h>
using namespace std;

int  twoKeysKeyboard(int n){
	int s[n+1];
	for(int i = 0; i <= n; i++){
		s[i] = i;
	}

	for(int i = 2; i <= n; i+=2){
		s[i] = 2;
	}

	for(int i = 3; i <= n; i++){
		for(int j = i; j<= n; j+=i){
			s[j] = min(s[j], i);
		}
	}

	int ans = 0;
	while(n!=1){
		ans+=s[n];
		n = n/s[n];
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	cout << twoKeysKeyboard(n);
}