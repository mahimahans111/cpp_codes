#include<bits/stdc++.h>
using namespace std;

int longestParenthesis(string s, int n){
    stack<pair<char, int> > st;
    st.push(pair<char, int>(')', -1));
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            st.push(pair<char, int>('(', i));
        } 
        if(s[i] == ')'){
            if(st.top().first == ')'){
                st.push(pair<char, int>(')', i));
            }
            else{
                st.pop();
                int a = i-st.top().second;
                //cout << a << endl;
                if(a>ans) ans=a;
            }
        }
    }
    return ans;
}

int main(){
    int n; cin >> n;
    string s;
    cin >> s;
    int ans = longestParenthesis(s, n);
    cout << ans;
}