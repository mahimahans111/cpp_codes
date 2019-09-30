#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n; cin >> n;
	long long int* arr = new long long int[n];
	for(long long int i = 0; i < n; i++) cin >> arr[i];
		long long int minIdx; long long int minSum = 0;
	long long int i = 0;
	while(i+2 < n){
		
		if(arr[i] <= arr[i+1] and arr[i] <= arr[i+2]){ minIdx = i; minSum += arr[i];}
		else if(arr[i+1] <= arr[i] and arr[i+1] <= arr[i+2]) { minIdx = i+1; minSum+=arr[i+1];}
		else minIdx = i+2; minSum += arr[i+2];
		i = minIdx+1;
			}
			cout << minSum;
}