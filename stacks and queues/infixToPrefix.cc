#include<bits/stdc++.h>
using namespace std;

bool isOperator(char ch){
	return ch == '+'|| ch == '-' || ch == '*' || ch == '/' || ch == '^';
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

string infixToPostfix(string str){
	stack<string>s;
	stack<char>os;
	for(int i = 0; i < str.length(); ){
		if(i!=0 && str[i]>='0' && str[i] <= '9' && str[i-1]>='0' && str[i-1]<='9'){
			i++;
			continue;
		}
		if(str[i] >= '0' && str[i] <= '9'){
			 int j = i;
			int val = 0;
			int p = 1;
			string stri = "";
			 while(j < str.length() &&  str[j] >= '0' && str[j] <= '9') 
            { 
                stri+=str[j];
                j++;
            } 
			s.push(stri);
		}
		else if(str[i] == '('){
			os.push(str[i]);
		}
		else if(str[i] == ')'){
			while(!os.empty() && os.top() != '(') 
            { 
                string val1 = s.top(); 
                s.pop(); 
                  
                string val2 = s.top(); 
                s.pop(); 
                  
                char op = os.top(); 
                os.pop(); 
                
                string stri = "";
                stri+=(val2);
                stri+=(val1); 
                stri+=op;
                s.push(stri); 
                // ns.push(operate(val2, val1, op)); 
            } 
			os.pop();
		}
		else if(isOperator(str[i])){
			while(!os.empty() && priority(os.top())>=priority(str[i]) && os.top()!='('){
				char op = os.top();
				os.pop();
				string val1 = s.top();
				s.pop();
				string val2 = s.top();
				s.pop();
				string stri = "";
                stri+=(val2);
                stri+=(val1); 
                stri+=op;
                s.push(stri);
			}
			os.push(str[i]);
		}

		i++;
	}
	while(!os.empty()){
		        char op = os.top();
				os.pop();
				string val1 = s.top();
				s.pop();
				string val2 = s.top();
				s.pop();
				string stri = "";
                stri+=(val2);
                stri+=(val1); 
                stri+=op;
                s.push(stri);	
	}
	return s.top();
}

string reverse(string str){
	int n = str.length();
	for(int i = 0; i < n/2; i++){
		swap(str[i], str[n-1-i]);
	}
	return str;
}

string normalizeBrackets(string str){
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '('){
			str[i] = ')';
		}
		if(str[i] == ')'){
			str[i] = '(';
		}
	}
	return str;
}

string infixToPrefix(string str){
	string s = reverse(str);
	s = normalizeBrackets(s);
	s = infixToPostfix(s);
	s = reverse(s);
	return s;
}

int main(){
	string str;
	cin >> str;
	string ans = infixToPrefix(str);
	cout << ans;
}