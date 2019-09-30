#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next; // self referential classes
    Node(int d) {
        data = d;
        next = NULL;
    }
};

Node* createLL() {
    int x;
    Node* head = NULL;
    Node* tail = NULL;
    while (true) {
        cin >> x;
        if (x == -1) break;
        Node* newNode = new Node(x);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            (*tail).next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

void printLL(const Node* head) {
    const Node* cur = head;
    while (cur) {
        cout << cur->data << "-->"; cur = cur->next;
    }
    cout << endl;
}

int lengthLL(Node* head){
    if(head == NULL) return 0;
    return 1+lengthLL(head->next);
}

Node* bubbleSortLL(Node* head){
    if(!head or !head->next) return head;

    int len = lengthLL(head);
    for(int i = 0; i < len; i++){
        Node* prev = NULL;
        Node* cur = head;
        
    }
}