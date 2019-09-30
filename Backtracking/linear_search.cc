#include<bits/stdc++.h>
using namespace std;

int linear_search(int n, int i, int arr[], int key){
	if(i == n) return -1;

	if(arr[i] == key) return i;
	else return linear_search(n, i+1, arr, key);
}

int main(){
	int n, key; cin >> n;
	int arr[100];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cin >> key;
	int ans = linear_search(n, 0, arr, key);
	cout << ans;
}