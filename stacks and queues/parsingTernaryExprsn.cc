#include<bits/stdc++.h>
using namespace std;

char ParseTernary(string str){
	stack<char>s;
	int flag = 0;
	for(int i= str.length(); i >= 0; i--){
		if(str[i] >= '0' && str[i] <= '9'){
			s.push(str[i]);
		}
		else if(str[i] == '?'){
			flag = 1;
		}
		else if((str[i] == 'T' && flag == 0)||(str[i] == 'F' && flag == 0)){
			s.push(str[i]);
		}
		else if(str[i] == 'T' && flag == 1){
			flag = 0;
			if(s.size()>1){
			char no1 = s.top();
			s.pop();
			char no2 = s.top();
			s.pop();
			s.push(no1);
			}

		}
		else if(str[i] == 'F' && flag == 1){
			flag = 0;
			if(s.size()>1){
			char no1 = s.top();
			s.pop();
			char no2 = s.top();
			s.pop();
			s.push(no2);
			}
		}
	}
	if(!s.empty())return s.top();
	return -1;
}

int main(){
	string s;
	cin >> s;
	char ans = ParseTernary(s);
	cout << ans;
}