#include<bits/stdc++.h>
using namespace std;

int maxRectArea(int arr[], int n){
    int nsel[n];
    int nser[n];
    stack<int>s1, s2;
    s1.push(0);
    nsel[0] = -1;
    for(int i = 1; i < n; i++){
        while(!s1.empty() && arr[s1.top()]>=arr[i]){
            s1.pop();
        }
        if(s1.empty()) nsel[i] = -1;
        else nsel[i] = s1.top();
        s1.push(i);
    }
    
    nser[n-1] = -1;
    s2.push(n-1);
     for(int i = n-2; i >= 0; i--){
        while(!s2.empty() && arr[s2.top()]>=arr[i]){
            s2.pop();
        }
        if(s2.empty()) nser[i] = -1;
        else nser[i] = s2.top();
        s2.push(i);
    }
    
    int max = 0;
    for(int i = 0; i < n; i++){
        if(nser[i] == -1) nser[i] = n;
        int ans = nser[i]-nsel[i]-1;

        ans=ans*arr[i];
        if(ans > max) max = ans;
    }
    return max;
    
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans = maxRectArea(arr, n);
    cout << ans;
}