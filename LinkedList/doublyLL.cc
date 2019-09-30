#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* prev;
	Node*next;
	Node(int d){
		data = d;
		prev = NULL;
		next = NULL;
	}
};

void addAtHead(Node*&head, Node*&tail, int data){
	Node*newNode = new Node(data);
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}

	else{
		newNode->next = head;
		//newNode->prev = NULL .. this happens in constructor already
		head->prev = newNode;
		head = newNode;
	}
}

void addAtTail(Node*&head, Node*&tail, int data){
	Node*newNode = new Node(data);
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}
	else{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}

}

void removeFromHead(Node*&head, Node*&tail){
	if(head == NULL) return;
	if(head == tail){
		head = NULL;
		tail = NULL;
		return;
	}
	else{
		head = head->next;
		head->prev = NULL;
		return;
	}
}

void removeFromTail(Node*&head, Node*&tail){
	if(head == NULL) return;
	if(head == tail){
		head = NULL;
		tail = NULL;
		return;
	}
	else{
		tail = tail->prev;
		tail->next = NULL;
		return;
	}	
}

void printList(Node* node)  
{  
    Node* last;  
    // printf("\nTraversal in forward direction \n");  
    while (node != NULL) {  
        printf(" %d ", node->data);  
        last = node;  
        node = node->next;  
    }  
  
    // printf("\nTraversal in reverse direction \n");  
    // while (last != NULL) {  
    //     printf(" %d ", last->data);  
    //     last = last->prev;  
    // }  
} 

int main(){
	Node*head = NULL;
	Node*tail = NULL;
	addAtHead(head, tail, 5);
	addAtHead(head, tail, 6);
	addAtHead(head, tail, 7);
	addAtTail(head, tail, 3);
	addAtTail(head, tail, 2);
	addAtTail(head, tail, 1);
	removeFromHead(head, tail);
	printList(head);
	cout << endl;
	removeFromTail(head, tail);
	printList(head);
}