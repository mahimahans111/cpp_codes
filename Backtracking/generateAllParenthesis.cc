#include<bits/stdc++.h>
using namespace std;

void generateParenthesis(int n, int i, int ob, int cb, char sans[], vector<string> &ans){
	if(cb == 0){
		string ab="";
		for(int m = 0; m < 2*n; m++){
			ab+=sans[m];
		}
		ans.push_back(ab);
		return;
	}
	if(ob!=0){
		sans[i] = '(';
		generateParenthesis(n, i+1, ob-1, cb, sans, ans);
	}
	if(cb!=0 && ob < cb){
		sans[i] = ')';
		generateParenthesis(n, i+1, ob, cb-1, sans, ans);
	}
}

int main(){
	int n;
	cin >> n;
	char sans[2*n+1];
	vector<string> ans;
	generateParenthesis(n, 0, n, n, sans, ans);
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << endl;
	}
}