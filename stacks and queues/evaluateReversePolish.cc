#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c){
	return c=='+' || c == '-'||c=='*'||c=='/';
}

int operate(int a, int b, char op){
	switch(op){
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;
	}
}

int solveReversePolish(vector<string> str){
	  stack<int> st;
    int ans;
    for(int i = 0; i < str.size(); i++){
        string s = str[i];
        if(s.length() == 1 && isOperator(s[0])){
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            ans = operate(op1, op2, s[0]);
            //cout << ans << endl;
            st.push(ans);
        }
        else if(s[0]!='-'){
            int p = 1;
            int no = 0;
            for(int i = s.length()-1; i >= 0; i--){
                no+=p*(int)(s[i]-'0');
                p=p*10;
            }
            st.push(no);
            //cout << no << endl;
        }
        else if(s[0] == '-'){
            int p = 1;
            int no = 0;
            for(int i = s.length()-1; i >= 1; i--){
                no+=p*(int)(s[i]-'0');
                p=p*10;
            }
            st.push(no*(-1));
        }
    }
    return st.top();
}

int main(){
	int n; cin >> n;
	vector<string> s(n);
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	int ans = solveReversePolish(s);
	cout << ans;
}