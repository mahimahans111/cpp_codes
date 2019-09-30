#include<bits/stdc++.h>
using namespace std;

void rotationOfCards(int n){
    map<int, int> m;
    queue<int> q;
    for(int i = 1; i <=n; i++){
        q.push(i);
    }
    for(int i = 1; i <= n; i++){
        for(int k = 0; k < i; k++){
            int p = q.front();
            q.pop();
            q.push(p);
        }
        m[q.front()] = i;
        // cout << q.front() << " " <<  m[q.front()] << endl;
        q.pop();
    }
    // for(map<int, int> :: iterator it = m.begin(); it!=m.end(); it++){
    //     cout << it->first << " " << it->second << endl;
    // }
    for(int i = 1; i <= n; i++){
        cout << m[i] << " ";
    }
}

int main(){
    int n; cin >> n;
    rotationOfCards(n);
}