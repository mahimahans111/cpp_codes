#include<bits/stdc++.h>
using namespace std;

int sumOfSubsequencesWidths(vector<int> &arr){
	int n = arr.size();
	sort(arr.begin(), arr.end());
	int i = 0;
	int j = n-1;
	int ans = 0;
	for(int k = 0; k < n; k++){
		ans+=arr[k]*(pow(2,i)-pow(2,j));
		i++;
		j--;
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	int a; vector<int> arr;
	for(int i = 0; i < n; i++){
		cin >> a;
		arr.push_back(a);
	}
	int ans = sumOfSubsequencesWidths(arr);
	cout << ans;
}