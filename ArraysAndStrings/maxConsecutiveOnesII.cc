#include<bits/stdc++.h>
using namespace std;

int maxConsecutive1s(vector<int> arr, int n){
	int noOfZeroes = 0;
	int s = 0; int e = 0;
	int maxl = 0;
	int l = 0;
	while(s <= e && e < arr.size()){
		while(e < arr.size() && noOfZeroes <= 1){
			l++;
			if(arr[e] == 0) noOfZeroes++;
			e++;
		}
		if(noOfZeroes == 2){
			e--;
			noOfZeroes--;
			l--;
		}
		if(l > maxl) maxl = l;

		while(s <= e && noOfZeroes == 1){
			if(arr[s] == 0){
				noOfZeroes--;
			}
			l--;
			s++;
		}
	}
	return maxl;
}

int main(){
	int n; cin >> n;
	int x;
	vector<int> arr;
	for(int i = 0; i < n; i++){
		cin >> x;
		arr.push_back(x);
	}
	int ans = maxConsecutive1s(arr, n);
	cout << ans;
}