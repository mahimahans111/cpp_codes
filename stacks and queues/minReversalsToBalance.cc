#include<bits/stdc++.h>
using namespace std;

int minReversals(string str){
	stack<int> s;
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '{'){
			s.push(str[i]);
		}
		else{
			if(s.empty())s.push('}');
			else if(s.top() == '{'){
				s.pop();
			}
			else{
				s.push('}');
			}
		}
	}
	int open = 0;
	int closed = 0;
	while(!s.empty()){
		if(s.top()=='{')open++;
		else closed++;
		s.pop();
	}
	return (open+1)/2+(closed+1)/2;
}

int main(){
	string str;
	cin >> str;
	int ans = minReversals(str);
	cout << ans;
}