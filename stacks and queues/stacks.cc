#include<iostream>
using namespace std;

class Stack{
private:
	class Node{
	public:
		int data;
		Node* next;
		Node(int d){
			data = d;
			next = NULL;
		}
	};
	Node* head;
	int sze;
public:
	Stack(){
		head = NULL;
	}
	void push(int x){
		Node* newNode = new Node(x);
		newNode->next = head;
		head = newNode;
		++sze;
		}
	void pop(){
		if(empty()) return;
		Node* temp = head;
		head = head->next;
		delete temp;
		--sze;
	}
	int top(){
		if(empty()) return -1;
		return head->data;
	}
	bool empty(){
		return head == NULL;
	}
	int size(){
		return sze;
	}
	~Stack(){
		while(head){
			Node* ahead = head->next;
			delete head;
			head = ahead;
		}
		//while(empty() == false){
		//	pop();
		//}
	}

};
int main(){
	
}