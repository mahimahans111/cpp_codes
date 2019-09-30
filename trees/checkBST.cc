#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int arr1[1000];
	int arr2[1000];
	int i, j;
	for(i = 0, j = 0; i < n && j < n; i++, j++){
		cin >> arr1[i];
		cin >> arr2[j];
	}
	for(int i = 0; i < n-1; i++){
		if(arr1[i] > arr2[i]){
			if(arr2[i+1]-arr2[i] > arr1[i])
		}
	}

}