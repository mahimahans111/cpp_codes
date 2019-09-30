#include<iostream>
#include<bits/stdc++.h>
    using namespace std;
    
    // Class declaration for a Node of the Linked List
    class Node {
        public:
        int data;
        Node* next;
    
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
    };
    
    Node* head1;
    
    /*
    * Input Parameters: head: head of the linked list in which a new node is to
    * be inserted. data: the data value of the node which is to be inserted.
    * 
    * Return Value: head of the linked list in which the node is inserted
    */
    Node* insert(Node* head, int data) {
    
        if (head == NULL) {
            Node* nn = new Node(data);
            return nn;
        }
    
        head->next = insert(head->next, data);
        return head;
    }
      void insertAtTail (Node*&head, Node*&tail, int c){
        Node* newNode = new Node(c);
         if(head == NULL){
             head = newNode;
             tail = newNode;
         }
         else{
             tail->next = newNode;
             tail=tail->next;
         }
    //return head;
     }
    
    void display(Node* head) {
        for (Node* node = head; node != NULL; node = node->next) {
            cout<<node->data<<" ";
        }
    }
    // -----------------------------------------------------
    // This is a functional problem. Only this function has to be written.
    // This takes as input the head of the linked list and x.
    // It should return the head of the modified list.
    Node* partition(Node* head, int x) {
    // write your code here
    Node*prev = NULL;
    Node*cur = head;
    Node*ansh = NULL; Node*anst = NULL;
    while(cur){
        if(cur->data < x){
            insertAtTail(ansh, anst, cur->data);
            if(cur==head){
                head=cur->next;
                cur = head;
            }
            else{
                prev->next=cur->next;
                cur = cur->next;
            }
        }
        else{
                prev=cur;
                cur=cur->next;            
        }

    }
    if(!ansh) return head;
    if(!head) return ansh;
    else {
        anst->next = head;
        return ansh;
    }
        
    }
    
    // -----------------------------------------------------
    
    int main(int argc, char** argv) {
        int n1;
        cin>>n1;
    
        for (int i = 0; i < n1; i++) {
            int a;
            cin>>a;
            head1 = insert(head1, a);
        }
    
        int x;
        cin>>x;
        
        head1 = partition(head1, x);
        display(head1);
    
    }