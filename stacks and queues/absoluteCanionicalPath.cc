
#include<bits/stdc++.h>
using namespace std;

string directoryProb(string str){
    stack<string>s;
    if(str[0]!='/'){
        string st = "";
        st+='/';
        s.push(st);
    }
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '/'){
            if(s.empty()){
               string st = "";
               st+='/';
               s.push(st);
            }
            else{
                if(s.top()!="/"){
                    string st = "";
                    st+='/';
                    s.push(st);                }
            }
        }
        else if(str[i] >= 'a' && str[i] <= 'z'){
            string stri = s.top();
            if(stri.length() > 1){
                string ans = "";
                ans+=str[i];
                ans+=stri;
                s.pop();
                s.push(ans);
            }
            else{
                if(stri == "/"){
                    string st="";
                    st+=str[i];
                    s.push(st);
                }
                else{
                    string ans = "";
                    ans+=str[i];
                    ans+=stri;
                    s.pop();
                    s.push(ans);
                }
            }
        }
        else if( i+1 != str.length() && str[i] == '.' && str[i+1] == '.'){
           if(!s.empty()) s.pop();
           if(!s.empty())  s.pop();
            i++;
        }
    }
    
    string ans="";
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    int n = ans.length();
    for(int i = 0; i < n/2; i++){
        swap(ans[i], ans[n-1-i]);
    }
    if(ans[n-1] == '/' && ans.length()>1)ans[n-1]='\0';
    return ans;
}

int main(){
    string s;
    cin >> s;
    string ans = directoryProb(s);
    cout << ans;
}