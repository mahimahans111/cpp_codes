#include<bits/stdc++.h>
using namespace std;

void runningMedians(double arr[], int n){
	priority_queue<double>maxheap;
	priority_queue<double, vector<double>, greater<double> >minheap;

	double median = arr[0];

	maxheap.push(arr[0]);
	cout << double(median) << endl;

	for(int i = 1; i < n; i++){
		if(maxheap.size() > minheap.size()){
			if(arr[i] <= median){
				minheap.push(maxheap.top());
				maxheap.pop();
				maxheap.push(arr[i]);
			}
			else{
				minheap.push(arr[i]);
			}
			median = double((minheap.top()+maxheap.top()))/2.0;
		}

		else if(minheap.size() > maxheap.size()){
			if(arr[i] > median){
				maxheap.push(minheap.top());
				minheap.pop();
				minheap.push(arr[i]);
			}
			else{
				maxheap.push(arr[i]);
			}
			median = double((minheap.top()+maxheap.top()))/2.0;
		}
		else{
			if(arr[i] <= median){
				maxheap.push(arr[i]);
				median = double(maxheap.top());
			}
			else{
				minheap.push(arr[i]);
				median = double(minheap.top());
			}
		}
		cout << median << endl;
	}
}

int main(){
	int n; cin >> n;
	double arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	runningMedians(arr, n);
}