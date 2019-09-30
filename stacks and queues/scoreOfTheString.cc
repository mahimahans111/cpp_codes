#include<bits/stdc++.h>
using namespace std;

int scoreOfString(string str){
	stack<char>s;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '('){
			s.push('(');
		} 
		else if(str[i] == ')'){
			if(!s.empty() && s.top()=='('){
				s.pop();
				s.push('1');
			}
			else{
			int ans = 0;
			while(!s.empty() && s.top()!='('){
				ans+=int(s.top()-'0');
				s.pop();
			}
			s.pop();
			s.push(char(2*ans)+'0');
			}
		}
	}
	return int(s.top()-'0');
}

int main(){
	string s;
	cin >> s;
	int ans = scoreOfString(s);
	cout << ans;
}