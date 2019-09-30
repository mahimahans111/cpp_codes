//Given an array, find the nearest larger element G[i] for every element A[i] in the array
//such that the element has an index smaller than i.
//larger, smaller dono ke liye same procedure hoga. Smaller wale mei cur<=s.top() kardena

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
}

vector<int> nearestLarger(const vector<int>&arr){
	int n = arr.size();
	vector<int>ans(n);
	stack<int>s;

	for(int i = 0; i < arr.size(); i++){
		int cur = arr[i];
		while(!s.empty() && cur >= s.top()){
			s.pop();
		}
		ans[i] = s.empty()?-1:s.top();
		s.push(arr[i]);
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i =0; i < n; i++){
		cin >> arr[i];
	}
	vector<int>ans = nearestLarger(arr);
	printVector(ans);
}
