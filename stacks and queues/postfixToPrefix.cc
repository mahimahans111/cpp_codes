#include<bits/stdc++.h>
using namespace std;

bool isOperator(char ch){
	return ch == '+'|| ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

string postfixToPrefix(string str){
	stack<string>s;
	for(int i = 0; i < str.length(); i++){
		if(str[i]>='0'&&str[i]<='9'){
			string stri = "";
			stri+=str[i];
			s.push(stri);
		}
		else if(isOperator(str[i])){
			string val1 = s.top();
			s.pop();
			string val2 = s.top();
			s.pop();
			string stri = "";
			stri+=str[i];
			stri+=val2;
			stri+=val1;
			s.push(stri);
		}
	}
	return s.top();
}

int main(){
	string s;
	cin >> s;
	string ans = postfixToPrefix(s);
	cout << ans;
}