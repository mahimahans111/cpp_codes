#include<bits/stdc++.h>
using namespace std;

bool checkStackValidation(int pushed[], int popped[], int n){
    stack<int> s;
    s.push(pushed[0]);
    int i = 1; int j = 0;
    
    while(true){
        if(!s.empty() && s.top() == popped[j]){
            j++;
            s.pop();
        }
        else if(!s.empty() && s.top() != popped[j]){
            if(i == n) return false;
            else{
             s.push(pushed[i]);
            i++;  
            }

        }

    }
    if(j == n) return true;
}

int main(){
    int n;
    cin >> n;
    int popped[n];
    int pushed[n];
    for(int i = 0; i < n; i++){
        cin >> pushed[i];
    }
    for(int i = 0; i < n; i++){
        cin >> popped[i];
    }
    bool ans = checkStackValidation(pushed, popped, n);
    ans?cout<<"true":cout<<"false";    
}

