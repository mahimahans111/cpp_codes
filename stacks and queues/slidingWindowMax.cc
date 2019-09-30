#include<bits/stdc++.h>
using namespace std;

void maxValueInWindow(int arr[], int n, int ans[], int k){
    int nge[n];
    stack<int>s;
    nge[n-1] = -1;
    s.push(n-1);
    for(int i = n-2; i>=0; i--){
        while(!s.empty() && arr[i] >= arr[s.top()]){
            s.pop();
        }
        if(s.empty())nge[i]=-1;
        else nge[i]=s.top();
        s.push(i);
    }

    queue<int> q;
    int j = 0;
    for(int i = 0; i < n-k+1; i++){
        if(nge[j]==-1)ans[i] = arr[j];
        else if(nge[j] < i+k){
            while(nge[j] < i+k && j!=n-1){
                j = nge[j];
            }
            ans[i] = arr[j];
        }
        else{
            ans[i] = arr[j];
        }
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
    maxValueInWindow(arr, n, ans, k);
    for(int i = 0; i < n-k+1; i++){
        cout << ans[i] << " ";
    }
}