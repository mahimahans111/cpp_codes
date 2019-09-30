#include<bits/stdc++.h>
using namespace std;

int climbStairs(int n){
	int a = 1, b = 1, c;
	if(n <= 1) return 1;
	for(int i = 2; i <= n; i++){
		c = a+b;
		a = b;
		b = c;
	}
	return c;
}

int main(){
	int n; cin >> n;
	cout << climbStairs(n);
}