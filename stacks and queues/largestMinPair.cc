#include<bits/stdc++.h>
using namespace std;

int largestMinPair(int arr[], int n){
	int ans;
	int max = 0;
	for(int i = 0; i < n-1; i++){
		ans = arr[i]+arr[i+1];
		if(ans>max)max = ans;
	}
	return max;
}

int main(){
	int n; cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int ans = largestMinPair(arr, n);
	cout << ans;
}