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

int priority(char op){
	switch(op){
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		case '^': return 3;
	}
}

int evaluateInfix(string str){
	stack<int>os, ns;
	for(int i = 0; i < str.length(); ){
		if(i!=0 && str[i]>='0' && str[i] <= '9' && str[i-1]>='0' && str[i-1]<='9'){
			i++;
			continue;
		}
		if(str[i] >= '0' && str[i] <= '9'){
			 int j = i;
			int val = 0;
			int p = 1;
			 while(j < str.length() &&  str[j] >= '0' && str[j] <= '9') 
            { 
                val = (val*10) + int(str[j]-'0'); 
                j++; 
            } 
			ns.push(val);
		}
		else if(str[i] == '('){
			os.push(str[i]);
		}
		else if(str[i] == ')'){
			while(!os.empty() && os.top() != '(') 
            { 
                int val1 = ns.top(); 
                ns.pop(); 
                  
                int val2 = ns.top(); 
                ns.pop(); 
                  
                char op = os.top(); 
                os.pop(); 
                  
                ns.push(operate(val2, val1, op)); 
            } 
			os.pop();
		}
		else if(isOperator(str[i])){
			while(!os.empty() && priority(os.top())>=priority(str[i]) && os.top()!='('){
				char op = os.top();
				os.pop();
				int val1 = ns.top();
				ns.pop();
				int val2 = ns.top();
				ns.pop();
				int ans = operate(val2, val1, op);
				ns.push(ans);
			}
			os.push(str[i]);
		}

		i++;
	}
	while(!os.empty()){
		        char op = os.top();
				os.pop();
				int val1 = ns.top();
				ns.pop();
				int val2 = ns.top();
				ns.pop();
				int ans = operate(val2, val1, op);
				ns.push(ans);	
	}
	return ns.top();
}

int main(){
	string s;
	cin >> s;
	int ans = evaluateInfix(s);
	cout << ans;
}