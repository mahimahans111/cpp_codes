#include<bits/stdc++.h>
using namespace std;

int maxLengthBitonicSubarray(int arr[], int n){
    int mis[n];
    int mds[n];
    
    mis[0] = 1;
    for(int i = 1; i < n; i++){
        if(arr[i-1] < arr[i]){
            mis[i] = mis[i-1]+1;
        }
        else mis[i] = 1;
    }
    
    mds[n-1] = 1;
    for(int i = n-2; i >= 0; i--){
        if(arr[i+1] < arr[i]){
            mds[i] = mds[i+1]+1;
        }
        else mds[i] = 1;
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, mds[i]+mis[i]-1);
    }
    return ans;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cout << maxLengthBitonicSubarray(arr, n) << endl;
     }
	return 0;
}