#include<bits/stdc++.h>
using namespace std;

void numberOfFetches(int ans[], int n){
    queue<int>q;
    int a;
    cin >> a;
    ans[0] = 1;
    q.push(a);
    for(int i = 1; i < n; i++){
        cin >> a;
        q.push(a);
        while(q.front() < a-3000){
            q.pop();
        }
        ans[i] = q.size();
    }
}

int main(){
    int n; cin >> n;
    int ans[n];
    numberOfFetches(ans, n);
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
}