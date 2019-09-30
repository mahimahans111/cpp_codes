#include<bits/stdc++.h>
using namespace std;

void inputArr(int arr[], int n){
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
}

void outputArr(int arr[], int n){
	for (int i = 0; i < n; ++i){
		/* code */cout << arr[i] << " ";
	}
}

void mergeEm(int arr[], int s, int e){
	int mid = (s+e)/2;
	int i = s;
	int j = mid+1;
	int k = s;
	int ans[100]; 

	while(i <= mid && j <= e){
		if(arr[i] < arr[j]) ans[k++] = arr[i++];
		else ans[k++] = arr[j++];
	}

		while(i <= mid){
			ans[k++] = arr[i++];
		}
		
		while(j <= e){
			ans[k++] = arr[j++];   
		}

	for(int i = s; i <= e; i++){
		arr[i] = ans[i];
	}
}

void mergeSort(int arr[], int s, int e){
	if(s >= e) return;

	int mid = (s+e)/2;

	mergeSort(arr, s, mid);
	mergeSort(arr, mid+1, e);
	mergeEm(arr, s, e);
}

int main(){
	int n; cin >> n;
	int arr[100];
	inputArr(arr, n);
	mergeSort(arr, 0, n-1);
	outputArr(arr, n);
}