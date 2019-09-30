#include<iostream>
using namespace std;

void merge(int a[], int p, int q, int r, int mergeSortedArr[]){
	int i = p; int j = q+1; int k = p;
 
	while(i <= q && j <= r){
		if(a[i] < a[j]){
			mergeSortedArr[k] = a[i];
			k++; i++;
		}
		else{
			mergeSortedArr[k] = a[j];
			k++; j++;
		}
	}
	while(i <= q){
		mergeSortedArr[k] = a[i];
		k++; i++;
	}
	while(j <= r){
		mergeSortedArr[k] = a[j];
		k++; j++;
	}
}

void mergeSort(int ans[], int a[], int p, int r){
	if(p < r){
		int q = (p+r)/2;
		mergeSort(ans, a, p, q);
		mergeSort(ans, a, q+1, r);
		merge(a, p, q, r, ans);
	}
}

int main(){
	int n; cin >> n;
	int a[100];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int ans[100] = {};
    mergeSort(ans, a, 0, n-1);
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
}