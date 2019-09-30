#include<bits/stdc++.h>
using namespace std;

class Node{
	int data;
	Node*next;
	Node*arb;

	Node(int data){
		this->data = data;
		this->next = NULL;
		this->arb = NULL;
	}
};

Node*createLL(int n){
	Node*head = NULL;
	Node*tail = NULL;
	int i = 0;
	int x;
	while(i < n){
		cin >> x;
		Node*newNode = new Node(x);
		i++;
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

void printLL(Node*head){
	Node*temp = head;
	while(temp){
		cout << temp->data;
		temp = temp->next;
	}
}

Node*clone(head){
	Node*origCurr=head;
	Node*cloneCurr = NULL;

	unordered_map<Node*,Node*>mymap;

	while(origCurr!=NULL){
		cloneCurr = new Node(origCurr->data);
		mymap[origCurr] = cloneCurr;
		origCurr = origCurr->next;
	}

	origCurr = head;

	while(origCurr){
		cloneCurr = mymap[origCurr];
		cloneCurr->next = mymap[origCurr->next];
		cloneCurr->arb = mymap[origCurr->arb];
		origCurr = origCurr->next;
	}
	return mymap[head];
}

int main(){

}