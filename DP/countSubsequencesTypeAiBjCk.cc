#include<bits/stdc++.h>
using namespace std;

int distinctSubsequences(string s){
    int a = 0, b = 0, c = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'a') a = 2*a+1;
        else if(s[i] == 'b')b = 2*b+a;
        else if(s[i] == 'c')c = 2*c+b;
    }
    return c;
}

int main(){
    int t; cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << distinctSubsequences(s) << endl;
     }
	return 0;
}