#include<bits/stdc++.h>
using namespace std;

bool isOperator(char ch){
	return ch == '+'|| ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int operate(int a, int b, char ch){
	switch(ch){
		case '+':return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;
		case '^': return pow(a, b);
	}
}

int evaluatePrefix(string str){
	stack<int> s;
	for(int i = str.length()-1; i >= 0; i--){
		if(str[i] >= '0' && str[i] <= '9'){
			s.push(int(str[i]-'0'));
		}
		if(isOperator(str[i])){
			int val1 = s.top();
			s.pop();
			int val2 = s.top();
			s.pop();
			s.push(operate(val1, val2, str[i]));
		}
	}
	return s.top();
}

int main(){
	string str;
	cin >> str;
	int ans = evaluatePrefix(str);
	cout << ans;
}