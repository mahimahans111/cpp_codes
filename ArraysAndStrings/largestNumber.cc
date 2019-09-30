#include<bits/stdc++.h>
using namespace std;

string largestNumber(int arr[], int n){
	string str[n];
	for(int i = 0; i < n; i++){
		str[i] = to_string(arr[i]);
	}
	sort(str.begin(), str.end());
	string ans = "";
	for(int i = n-1; i >= 0; i--){
		ans+=str[i];
	}
	return ans;
}

int main(){
	int n; cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	string ans = largestNumber(arr, n);
	cout << ans;	
}