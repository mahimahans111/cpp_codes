//find the maximum contiguous subarray sum

#include<bits/stdc++.h>
using namespace std;

int kadaneAlgo(int arr[], int n){
    int ps = 0;
    int ans = INT_MIN;
    
    for(int i = 0; i < n; i++){
        ps+=arr[i];
        if(ps > ans) ans = ps;
        
        if(ps < 0) ps = 0;
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
        int ans = kadaneAlgo(arr, n);
        cout << ans << endl;
     }
	return 0;
}