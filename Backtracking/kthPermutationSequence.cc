#include<bits/stdc++.h>
using namespace std;

void permu(vector<int> &arr, int be, vector<vector<int> > & ans){
    if(be == arr.size()){
        ans.push_back(arr);
        return;
    }
    
    for(int pos = be; pos < arr.size(); pos++){
        swap(arr[pos], arr[be]);
        permu(arr, be+1, ans);
        swap(arr[pos], arr[be]);
    }
}

vector<vector<int> > permute(vector<int> &arr) {
    vector<vector<int> >ans;
    int be = 0;
    permu(arr, be, ans);
    return ans;
}

int main(){
	int n;
	cin >> n;
	int k; cin >> k;
	vector<int> arr;
	for(int i = 1; i <= n; i++){
		arr.push_back(i);
	}
	vector<vector<int> > ans = permute(arr);
	for(int i = 0; i < ans[k-1].size(); i++){
		cout << ans[k-1][i];
	}
}