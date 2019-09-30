// Kadane
// Reverse Kadane!

#include<bits/stdc++.h>
using namespace std;

int maxSumCircularSubarray(int arr[], int n){
	int ps = 0;
	int max1 = 0;
	int totsum = 0;
	for(int i = 0; i < n; i++){
		if(ps < 0){
			ps = 0;
		}
		ps+=arr[i];
		max1 = max(ps, max1);
		totsum += arr[i];
	}

	int min1 = INT_MAX;
	ps = 0;
	for(int i = 0; i < n; i++){
		if(ps > 0){
			ps = 0;
		}
		ps+=arr[i];
		cout << ps << endl;
		min1 = min(min1, ps);
	}
	 int max2;
    if(min1 == totsum){
       max2 = INT_MIN;
    }
	else max2 = totsum-min1;
	int ans = max(max1, max2);
	return ans;

}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	int ans = maxSumCircularSubarray(arr, n);
	cout << ans;
}