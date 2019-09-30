#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int checkRedundantParenthesis(string str){
    stack<char>s;
    int cnt = 0;
    for(int i = 0; i < str.length(); i++){
        if(!isOperator(str[i]) && str[i]!='(' && str[i]!=')') continue;
        
        if(isOperator(str[i]) && !s.empty())s.push(str[i]);
        
        if(str[i] == '(') s.push(str[i]);
        
        if(str[i] == ')'){
            bool isRedundant = true;
            while(!s.empty() && s.top()!='('){
                isRedundant = false;
                s.pop();
            }
            s.pop();
            if(isRedundant) cnt++;
        }
    }
    if(cnt) return 1;
    else return 0;
}

int main(){
    string s;
    cin >> s;
    int ans = checkRedundantParenthesis(s);
    if(ans == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
}