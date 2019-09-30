#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int d){
		data = d;
		next = NULL;
	}
};

Node* createLL(){
	int x;
	Node* head = NULL;
	Node* tail = NULL;

	while(true){
		cin >> x;
		if(x == -1) break;

		Node* newNode = new Node(x);
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail -> next = newNode;
			tail = tail ->next;
		}
	}
	return head;

}

void printLL(Node* head){
	Node* cur = head;
	while(cur){
		cout << cur->data << "->";
		cur = cur->next;
	}
	cout << endl;
}

istream &operator>>(istream &is, Node* &head){
	createLL();
	return is;
}
/* for the void funcn
istream& operator>>(istream &is, Node* & head){
	createLL(head);
	return is;
}
*/
ostream &operator<<(ostream&os, Node* & head){
	printLL(head);
	return os;
}
int main(){
	Node* head = NULL;
	cin >> head;
	cout << head;
}