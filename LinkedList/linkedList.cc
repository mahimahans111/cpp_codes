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

Node* deleteNode(Node* head, int dataToDelete){
	Node* cur = head;
	Node* previous = NULL;
	while(cur){
		if(cur->data == dataToDelete){
			if(cur == head){
				head = cur->next;
				delete cur;
			}
			else{
				previous->next = cur->next;
				delete cur;
			}
			break;
		}
		else{
		previous = cur;
		cur = cur->next;
	}
	}
	return head;
}

Node* reverseListByRecursion(Node* head){
	if(head == NULL || head->next == NULL) return head;

	Node* remList = reverseListByRecursion(head->next);
	head->next->next = head;
	head->next = NULL;
}

Node* reverseListByLooping(Node*head){
	Node* cur = head;
	Node* previous = NULL;
	while(cur){
		Node* ahead = cur->next;
		cur->next = previous;
		previous = cur;
		cur = ahead;
	}
	return previous;
}

Node* middle(Node* head){
	Node* slow = head;
	Node* fast = head;

	while(slow && fast && fast->next && fast->next->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Node* mergeThem(Node*a, Node* b){
	if(a == NULL) return b;
	if(b == NULL) return a;

	if(a->data < b->data){
		a->next = mergeThem(a->next, b);
		return a;
	}
	else{
		b->next = mergeThem(a, b->next);
		return b;
	}
}

Node* mergeSortLinkedList(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	Node* midPt = middle(head);
	Node*l1 = head;
	Node*l2 = midPt->next;
	midPt->next = NULL;

	 l1 = mergeSortLinkedList(l1);
	 l2 = mergeSortLinkedList(l2);
	head = mergeThem(l1, l2);
	return head;
}

int main(){
	Node*head = createLL();
	printLL(head);
	cout << endl;
	head = mergeSortLinkedList(head);
	printLL(head);
}