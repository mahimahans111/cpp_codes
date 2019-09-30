#include<bits/stdc++.h>
using namespace std;

int noOfFleets(pair<int, int> arr[], int n, int target){
    queue<float> q;
    int ans = 0;
    q.push((float)(target-arr[n-1].first)/(float)(arr[n-1].second));
    for(int i = n-2; i >= 0; i--){
        float time = (float)(target-arr[i].first)/(float)(arr[i].second);
        if(time > q.front()){
            ans++;
            q.pop();
            q.push(time);
        }
        else{
            ;
        }   
    }
    if(!q.empty()) ans++;
    return ans;
}

int main(){
    int target;
    cin >> target;
    int n; cin >> n;
    pair<int, int> obj[n];
    for(int i = 0; i < n; i++){
        cin >> obj[i].first;
    }
    for(int i = 0; i < n; i++){
        cin >> obj[i].second;
    }
    sort(obj, obj+n);
    int ans = noOfFleets(obj, n, target);
    cout << ans;
}