#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int i, int n){
	if(i == n-1) return;

	bubbleSort(arr, i+1, n);
	if(arr[i]>arr[i+1]){ 
		swap(arr[i], arr[i+1]);
		bubbleSort(arr, i+1, n);}
}

int main(){
	int n; cin >> n;
	int arr[100];

	for (int i = 0; i < n; ++i)
	{	
		cin >> arr[i];
		/* code */
	}

	bubbleSort(arr, 0, n);

	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
}
