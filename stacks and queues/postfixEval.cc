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

int postfixEvaluation(string str){
	stack<int>s;
	for(int i = 0; i < str.length(); ){
		// if(i!=0 && str[i] >= '0' && str[i] <= '9' && str[i-1] >= '0' && str[i-1] <= '9'){
		// 	i++;
		// 	continue;
		// }
		// else if(str[i] >= '0' && str[i] <= '9'){
		// 	int j = i;
		// 	int val = 0;
		// 	int p = 1;
		// 	 while(j < str.length() &&  str[j] >= '0' && str[j] <= '9') 
  //           { 
  //               val = (val*10) + int(str[j]-'0'); 
  //               j++; 
  //           } 
		// 	s.push(val);
		// }
		if(str[i]>='0' && str[i] <='9'){
			s.push((int)(str[i]-'0'));
		}
		else if(isOperator(str[i])){
			int val1 = s.top();
			s.pop();
			int val2 = s.top();
			s.pop();
			int ans = operate(val2, val1, str[i]);
			s.push(ans);
		}
		i++;
	}
	return s.top();
}

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	int ans = postfixEvaluation(s);
	cout << ans;
	return 0;
}