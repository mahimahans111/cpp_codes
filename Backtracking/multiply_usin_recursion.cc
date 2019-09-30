#include<bits/stdc++.h>
using namespace std;

int multiplyEm(int a, int b, int cnt, int ans){
	if(cnt == b) return ans;

	ans = ans + a;
	return multiplyEm(a, b, cnt+1, ans);
}

int main(){
	int n1, n2;
	cin >> n1 >> n2;
	int ans = multiplyEm(n1, n2);
	cout << ans;
}