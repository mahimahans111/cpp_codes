#include<bits/stdc++.h>
using namespace std;

bool isOperator(char ch){
	return ch == '+'|| ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

string prefixToPostfix(string str){
	stack<string>s;
	for(int i = str.length()-1; i >= 0;  i--){
		if(str[i] >= '0' && str[i] <= '9'){
			string stri = "";
			stri+=str[i];
			s.push(stri);
		}
		if(isOperator(str[i])){
			string val1 = s.top();
			s.pop();
			string val2 = s.top();
			s.pop();
			string stri="";
			stri+=val1;
			stri+=val2;			
			stri+=str[i];
			s.push(stri);
		}
	}
	return s.top();
}

int main(){
	string str;
	cin >> str;
	string ans = prefixToPostfix(str);
	cout << ans;
}