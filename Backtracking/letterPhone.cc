#include<bits/stdc++.h>
using namespace std;

string a[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void lPhone(string str, int i, char subans[], int j, vector<string> &ans){
	if(i == str.length()){
		string ab = "";
		for(int m = 0; m < j; m++){
			ab+=subans[m];
		}	
		ans.push_back(ab);
		return;
	}

	int digit = str[i]-'0';
	for(int k = 0; k < a[digit].length(); k++){
		subans[j] = (a[digit][k]);
		lPhone(str, i+1, subans, j+1, ans);
	}
}

int main(){
	string str;
	cin >> str;
	int n = str.length();
	char subans[n];
	vector<string> ans;
	lPhone(str, 0, subans, 0, ans);
	sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << endl;
	}
}