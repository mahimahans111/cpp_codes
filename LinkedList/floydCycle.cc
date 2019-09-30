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
	Node* head = NULL;
	Node* tail = NULL;
	int x;

	while(1){
		cin >> x;
		if(x == -1) break;

		Node* newNode = new Node(x);

		if(head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail->next = newNode;
			tail = tail->next; 
		}
	}
	return head;
}

void printLL(Node* head){
	Node* cur = head;
	while(cur){
		cout << cur->data << " ";
		cur = cur->next;
	}
}

void removeTheLoop(Node* &head, Node*&slow, Node* & fast, Node*&previous){
        fast = head;
			while(1){

			if(slow == fast){
				previous->next = NULL;
				break;
			}
			else{
			previous = slow;
			slow = slow->next;
			fast = fast->next;
		}
			}
	}

bool detectCycle(Node* &head){
	Node* previous = NULL;
	Node* slow = head;
	Node* fast = head;

	while(slow && fast && fast->next && fast->next->next){
		if(slow == fast) {
			removeTheLoop(head, slow, previous, fast);
			return true;
		}
		previous = slow;
		slow = slow->next;
		fast = fast->next->next;
		}
	return false;
}

int main(){
	Node* head = createLL();
	head->next->next->next->next = head->next;
	bool ans = detectCycle(head);
	cout << ans;
	//printLL(head);
}