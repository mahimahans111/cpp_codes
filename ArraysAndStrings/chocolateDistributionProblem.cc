#include<bits/stdc++.h>
using namespace std;

int chocolateDistribution(int arr[], int n, int m){
	sort(arr, arr+n);
	if(n == m) return arr[n-1]-arr[0];
	int min = INT_MAX;
	for(int i = 0; i < n-m+1; i++){
		if(arr[i+m-1]-arr[i] < min) min = arr[i+m-1]-arr[i];
	}
	return min;
}

int main(){
	int n; cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int m; cin >> m;

	cout << chocolateDistribution(arr, n, m);
}