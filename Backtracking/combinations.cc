 #include<bits/stdc++.h>
using namespace std;

void Combinations(int n, int k, vector<vector<int> > & ans, vector<int> &subans, int i, int j){
	// if(i > n) return;
	if(j == k){
		ans.push_back(subans);
		return;
	}

	if(i <= n){
	subans[j] = i;
	Combinations(n, k, ans, subans, i+1, j+1);
	Combinations(n, k, ans, subans, i+1, j);
	}
	else return;
}

int main(){
	int n, k; cin >> n >> k;
	vector<vector<int> > ans;
	vector<int> subans(k, 0);
	Combinations(n, k, ans, subans, 1, 0);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}