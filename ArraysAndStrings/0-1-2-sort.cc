#include<bits/stdc++.h>
using namespace std;
 
vector<int> the012sort(vector<int> arr){
	int n = arr.size();
	int lo = 0, hi = n-1, mid = 0;
	while(mid <= hi){
		if(arr[mid] == 0){
			swap(arr[mid], arr[lo]);
			lo++; mid++;
		}
		else if(arr[mid] == 1){
			mid++;
		}
		else if(arr[mid] == 2){
			swap(arr[mid], arr[hi]);
			hi--;
		}
	}
	return arr;
}

int main(){
	int n; cin >> n;
	int a; 
	vector<int> arr;
	for(int i = 0; i < n; i++){
		cin >> a;
		arr.push_back(a);
	}
	vector<int> ans = the012sort(arr);
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}