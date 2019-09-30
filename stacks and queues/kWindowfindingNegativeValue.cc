#include<bits/stdc++.h>
using namespace std;

void negativeValueInWindow(int arr[], int n, int ans[], int k){
    queue<int> q;
    int j = 0;
    for(int i = 0; i < n-k+1; i++){
        if(j < i) j = i;
        while(arr[j]>=0){
            j++;
        }
        if(j > i+k-1)ans[i] = 0;
        else ans[i] = arr[j];
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k; cin >> k;
    int s = n-k+1;
    int ans[s];
    negativeValueInWindow(arr, n, ans, k);
    for(int i = 0; i < n-k+1; i++){
        cout << ans[i] << " ";
    }
}