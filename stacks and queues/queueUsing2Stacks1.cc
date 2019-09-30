#include<iostream>
//enqueue operation costly here nd dequeue operation fun !!
#include<queue>
#include<stack>
using namespace std;

void enqueue(stack<int> &s1, stack<int> &s2, int x){
	while(!s1.empty()){
		s2.push(s1.top());
		s1.pop();
	}
	s1.push(x);
	while(!s2.empty()){
		s1.push(s2.top());
		s2.pop();
	}
}

void dequeue(stack<int> &s1, stack<int> &s2){
	s1.pop();
}
void printQueue(stack<int> s1, stack<int> s2){
	while(!s1.empty()){
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;
}

int main(){
	
	stack<int> s1;
	stack<int> s2;
	enqueue(s1, s2, 1);
	printQueue(s1, s2);	
	enqueue(s1, s2, 2);
	printQueue(s1, s2);
	enqueue(s1, s2, 3);
	printQueue(s1, s2);
	dequeue(s1, s2);
	enqueue(s1, s2, 4);
	printQueue(s1, s2);
	enqueue(s1, s2, 5);
	printQueue(s1, s2);
	dequeue(s1, s2);
	printQueue(s1, s2);
}

