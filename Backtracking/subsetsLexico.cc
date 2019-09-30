#include<bits/stdc++.h>
using namespace std;

void subset(vector<int> arr, int n, vector<vector<int> > &ans, int subans[], int i, int j){
	if(i == n){
		vector<int>v;
		for(int k = 0; k < j; k++){
			v.push_back(subans[k]);
		}
		int flag = 0;
		for(int k = 0; k < ans.size(); k++){
			if(ans[k] == v){ flag = 1;
				break;}
		}
		if(flag == 0) ans.push_back(v);
		return;
	}
	
	subans[j] = arr[i];

	subset(arr, n, ans, subans, i+1, j+1);
	subset(arr, n, ans, subans, i+1, j);
}

bool myCompare(vector<int> a, vector<int> b){
	int flag = 0;
	for(int i = 0, j = 0; i < a.size() && j < b.size(); i++, j++){
		if(a[i]!=b[j]){
			flag = 1;
			return a[i] < b[j];
		}
	}
	if(flag==0) return a.size() < b.size();
}

int main(){
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) cin >> arr[i];
	vector<vector<int> > ans;
	int subans[n];
	sort(arr.begin(), arr.end());
	subset(arr, n, ans, subans, 0, 0);	
	sort(ans.begin(), ans.end(), myCompare);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}