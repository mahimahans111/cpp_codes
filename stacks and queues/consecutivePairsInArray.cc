#include<bits/stdc++.h>
using namespace std;

bool consecutivePairs(stack<int>s){
    while(!s.empty()){
        int one = s.top();
        s.pop();
        int two = s.top();
        s.pop();
        if(abs(one-two) != 1) {
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    stack<int> s;
    cin >> n;
    int a;
    if(n%2 == 0){
       for(int i = 0; i < n; i++){
            cin >> a;
            s.push(a);
        }
    }
    else{
        for(int i = 0; i < n-1; i++){
            cin >> a;
            s.push(a);
        }
        cin >> a;
    }
    bool ans = consecutivePairs(s);
    if(ans) cout << "true";
    else cout << "false";
}