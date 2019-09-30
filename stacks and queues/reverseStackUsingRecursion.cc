//reverse a stack using 0 extra stack(recursion)
#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int key){
	if(s.empty()){
		s.push(key);
		return;
	}
	int m = s.top();
	s.pop();
	insertAtBottom(s, key);
	s.push(m);
}

void reverseStackUsingRecursion(stack<int> &s){
	if(s.empty() == true){
		return;
	}
	int p = s.top();
	s.pop();
	reverseStackUsingRecursion(s);
	insertAtBottom(s, p);
}

void printStack(stack<int> &s){
	while(s.empty() == false){
	cout << s.top() << " ";
	s.pop();}
}

int main(){
	stack<int> s;
	//printStack(s);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	reverseStackUsingRecursion(s);
	printStack(s);
}