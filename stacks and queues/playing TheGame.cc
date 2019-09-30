#include<bits/stdc++.h>
using namespace std;

int score(string arr[], int n){
    stack<int>st;
    for(int i = 0; i < n; i++){
        string s = arr[i];
       // cout << s << endl;
        if(s.length() == 1){
            // cout << "1len" << endl;
            if(s[0] == '+'){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                int cur = first+second;
                st.push(second);
                st.push(first);
                st.push(cur);
                // cout  << first << " " << second << " " << "cur" << cur << endl;
            }
            else if(s[0] == 'D'){
                st.push(2*(st.top()));
                // cout << "D" << 2*(st.top()) << endl;
            }
            else if(s[0] == 'C'){
                  st.pop(); 
                // cout << "C" << endl;
            }
            else{
                st.push(int(s[0]-'0'));
                // cout << "push" << int(s[0]-'0') << endl;
            }
        }
        else{
            if(s[0] == '-'){
            int m = 1;
            int no = 0;
            for(int j = s.length()-1; j >= 1; j--){
                no+=m*(int(s[j]-'0'));
                m=m*10;
            }
            st.push(no*(-1));
            }
            else{
               int m = 1;
            int no = 0;
            for(int j = s.length()-1; j >= 0; j--){
                no+=m*(int(s[j]-'0'));
                m=m*10;
            }
            st.push(no); 
            }
        }
    }
    int ans = 0;
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}

int main(){
    int n; cin >> n;
    string arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans = score(arr, n);
    cout << ans;
}

