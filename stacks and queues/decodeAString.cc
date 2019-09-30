#include<bits/stdc++.h>
using namespace std;

string decode(string s){
    int n = s.length();
    stack<string> st;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == ']'){
            string str = "";
            str+=']';
            st.push(str);
            // cout << str << " ";
        }
        if(s[i]>='a' && s[i]<='z'){
            if(st.top()=="]"){
                string str = "";
                str+=s[i];
                st.push(str);
                // cout << str << " ";
            }
            else{
                string str = st.top();
                st.pop();
                string ans = "";
                ans+=s[i];
                ans+=str;
                st.push(ans);
                // cout << ans << " ";
            }
        }
        if(s[i] == '['){
            string str = st.top();
            st.pop();
            st.pop();
            st.push(str);
            // cout <<  str << " ";
        }
        if(s[i]>='1' && s[i] <= '9'){
            int no = int(s[i]-'0');
            string str = st.top();
            string ans = st.top();
            st.pop();
            for(int i = 1; i < no; i++){
                ans+=str;
            }
            st.push(ans);
            // cout << ans << " ";
        }
    }
    return st.top();
}

int main(){
    string s;
    cin >> s;
    string ans = decode(s);
    cout << ans;
    
}