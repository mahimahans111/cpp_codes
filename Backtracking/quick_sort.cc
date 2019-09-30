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

int getPartition(int arr[], int s, int e){
	int i = s-1;
	int j = s;
	int pivot = arr[e];

	for(; j < e; j++){
		if(arr[j] <= pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[e] );
	return i+1;
}


void quickSort(int arr[], int s, int e){
	if(s >= e) return;

	int p = getPartition(arr, s, e);

	quickSort(arr, s, p-1);
	quickSort(arr, p+1, e);

}

int main(){
	int n; cin >> n;
	int arr[100];
	inputArr(arr, n);
	quickSort(arr, 0, n-1);
	outputArr(arr, n);
}