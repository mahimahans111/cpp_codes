#include<bits/stdc++.h>
using namespace std;

string adjacentTwining(string s){
    stack<char> st;
    
    for(int i = 0; i < s.length(); i++){
        if(!st.empty() && s[i] == st.top()){
            // cout << s[i] << endl;
            st.pop();
        }
        else {
            // cout << s[i] << endl;
            st.push(s[i]);
        }
    }
    int no = st.size();
    //cout << no << endl;
    string n = "";
    while(!st.empty()){
       // cout << st.top();
        char c = st.top();
        n+=c;
        st.pop();
    }
    for(int i = 0; i < no/2; i++){
        swap(n[i], n[no-i-1]);
    }
   
    return n;
}

int main(){
    string s;
    cin >> s;
    string n = adjacentTwining(s);
    cout << n;
}