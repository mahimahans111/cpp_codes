#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	int key;
	Node* prev;
	Node*next;
	Node(int d, int k){
		data = d;
		key = k;
		prev = NULL;
		next = NULL;
	}
};

void addAtHead(Node*&head, Node*&tail, int data, int key){
	Node*newNode = new Node(data, key);
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

void addAtTail(Node*&head, Node*&tail, int data, int key){
	Node*newNode = new Node(data, key);
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

void removeNode(Node* &head, Node* &tail, int d){
    if(head->data == d){
        removeFromHead(head, tail);
        return;
    }
    else if(tail->data == d){
        removeFromTail(head, tail);
        return;
    }
    else{
        Node*temp = head;
        while(temp){
            if(temp->data == d){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete(temp);
                return;
            }
            else
            temp = temp->next;
        }
    }
}

void printList(Node* node)  
{  
    Node* last;  

    while (node != NULL) {  
        printf(" %d ", node->data);  
        last = node;  
        node = node->next;  
    }  
  
  
} 


class LRUCache{
    map<int, Node*>m;
    Node*head;
    Node*tail;
    int cap;
    public:
    LRUCache(int n){
        cap = n;
        head = NULL;
        tail = NULL;
    }
    int get(int x){
        if(m.count(x)){
            Node*n = m[x];
            removeNode(head, tail, n->data);
            addAtHead(head, tail, n->data, x);
            return n->data;
        }
        else return -1;
    }
    void set(int x, int y){
        if(!m.count(x)){
            if(m.size()==cap){
                m.erase(tail->key);
                removeFromTail(head, tail);
            }
            Node* n = new Node(y, x);
            addAtHead(head, tail, n->data, x);
            m[x] = n;            
        }
        else{
            Node*n = m[x];
            int old = n->data;
            n->data = y;
            removeNode(head, tail, old);
            m[x] = n;
            addAtHead(head, tail, n->data, x);
        }

    }
};

int main(){
    int cap; cin >> cap;
    int q; cin >> q;
    LRUCache lc(cap);
     for(int i=0;i<q;i++){
     string op;
     cin >> op;
     if(op == "SET"){
     	 int x;
     	 cin >> x;
     	 int y;
     	 cin >> y;
     	 lc.set(x, y);
     }
     else if(op == "GET"){
     	 int x;
     	 cin >> x;
     	 cout << lc.get(x) << endl;
     }
 }
}



 