#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n, k;
	cin >> n >> k;
	long long int* arr = new long long int[n];
	for(long long int i = 0; i < n; i++){
		cin >> arr[i];
	}
	long long int cnt = 0;
	sort(arr, arr+n);
	long long int l = 0, r = n-1;
	while(l < r){
		if(arr[l]+arr[r] < k){
			cnt+=r-l;
			l++;
		}
		else r--;
	}
	cout << cnt;
}