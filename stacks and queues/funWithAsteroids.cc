#include<bits/stdc++.h>
using namespace std;

void funWithAsteroids(int arr[], int n){
    stack<int>s;
    s.push(arr[0]);
    for(int i = 1; i < n; i++){
        if(s.empty())s.push(arr[i]);
        else if((arr[i] >= 0 && s.top() >= 0)||(arr[i] <= 0 && s.top() <= 0)){
            s.push(arr[i]);
        }
        else if(arr[i] >= 0 && s.top() <= 0){
            s.push(arr[i]);
        }
        else if(arr[i] <= 0 && s.top() >= 0){
            int flag = 0;
            while(!s.empty() && s.top() >= 0){
                if(abs(arr[i]) >= abs(s.top())){
                    s.pop();
                    flag = 1;
                }
                else{
                    flag = 2;
                    break;
                }
            }
            if(flag == 1) s.push(arr[i]);
        }
    }
    stack<int>ans;
    while(!s.empty()){
        int p = s.top();
        ans.push(p);
        s.pop();
    }
    while(!ans.empty()){
        cout << ans.top() << endl;
        ans.pop();
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    funWithAsteroids(arr, n);
}