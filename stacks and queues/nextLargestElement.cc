#include<bits/stdc++.h>
using namespace std;

void nextLargestElement(int arr[], int n, int nle[]){
	stack<int> s;
	nle[n-1] = -1;
	s.push(arr[n-1]);
	for(int i = n-2; i >= 0; i--){
		while(!s.empty() && s.top() <= arr[i]){
			s.pop();
		}
		if(s.empty()) nle[i] = -1;
		else nle[i] = s.top();
		s.push(arr[i]);
	}
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int ans[n];
	nextLargestElement(arr, n, ans);
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
}