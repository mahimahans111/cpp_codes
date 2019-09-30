#include<bits/stdc++.h>
using namespace std;

int MSIS(int arr[], int n){
	int maxs[n];
	int ansmax = 0;
	for(int i = 0; i < n; i++){
		int maxi = 0;
		for(int j = 0; j < i; j++){
			if(arr[j] < arr[i])maxi = max(maxi, maxs[j]);
		}
		maxs[i] = maxi+arr[i];
		ansmax = max(maxs[i], ansmax);
	}
	return ansmax;
}

int main(){
	int n; cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	cout << MSIS(arr, n);
}