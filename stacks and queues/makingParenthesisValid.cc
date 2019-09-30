#include<bits/stdc++.h>
using namespace std;

int makingParenthesisValid(string str){
	stack<char>s;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '('){
			s.push('(');
		}
		else if(str[i] == ')'){
			if(s.empty()||s.top() == ')'){
				s.push(')');
			}
			else if(s.top() == '('){
				s.pop();
			}
		}
	}
	int ans = 0;
	return s.size();
}

int main(){
	string str;
	cin >> str;
	int ans = makingParenthesisValid(str);
	cout << ans;
}