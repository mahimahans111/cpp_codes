#include<bits/stdc++.h>
using namespace std;

int lbs(int arr[], int n){
    if(n == 0) return 0;
    int lis[n], lds[n];
    for(int i = 0; i < n; i++){
        int maxi = 0;
        for(int j = 0; j < i; j++){
           if(arr[j] < arr[i])maxi = max(maxi, lis[j]);
        }
        lis[i] = maxi+1;
    }
    for(int i = n-1; i >= 0; i--){
        int maxi = 0;
        for(int j = n-1; j > i; j--){
           if(arr[j] < arr[i])maxi = max(maxi, lds[j]);
        }
        lds[i] = maxi+1;
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, lis[i]+lds[i]-1);
    }
    return ans;
}

int main(){
  
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cout << lbs(arr, n) << endl;
  
	return 0;
}