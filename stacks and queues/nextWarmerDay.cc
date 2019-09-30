//Count the no. of days until the next warmer day(day with more temp than the current day)

#include<bits/stdc++.h>
using namespace std;

void nextWarmerDay(int arr[], int n, int nwd[]){
	stack<int>s;
	nwd[n-1] = -1;
	s.push(n-1);
	for(int i = n-2; i >= 0; i--){
		while(!s.empty() && arr[s.top()] <= arr[i]){
			s.pop();
		}
		if(s.empty()) nwd[i] = -1;
		else nwd[i] = s.top()-i;
		s.push(i);
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
	nextWarmerDay(arr, n, ans);
	for(int i = 0; i < n; i++){
		cout << ans[i] << " "; 
	}
}