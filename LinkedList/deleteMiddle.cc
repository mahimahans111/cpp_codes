 #include<bits/stdc++.h>
 using namespace std;
   
     class Node {
         public:
         int data;
         Node* next;
         Node(){
             
         }
 
         Node(int data) {
             this->data = data;
             this->next = NULL;
         }
 
     };
     
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
     
     void insertAtHead(Node*&head, Node*&tail, int c){
          Node* newNode = new Node(c);
         if(head == NULL){
             head = newNode;
             tail = newNode;
         }
         else{
            newNode->next = head;
            head = newNode;
         }
     }
     
    void display(Node*head){
         Node*temp = head;
         while(temp){
             cout << temp->data << " ";
             temp=temp->next;
         }
     }
     Node*deleteMiddle(Node*head, int n){
         if(n == 1) return NULL;
         Node*slow=head; Node*fast=head;
         Node*prev = NULL;
         while(slow && fast && slow->next && fast->next && fast->next->next){
             prev = slow;
             slow=slow->next;
             fast=fast->next->next;
         }
         if(n%2==0){prev = slow; slow=slow->next;}
         prev->next = slow->next;
         //delete(slow);
         return head;
     }
    
    int main(){
        int n; cin >> n;
        int a; 
        Node*head = NULL; Node*tail = NULL;
        for(int i = 0; i < n; i++){
            cin >> a;
            insertAtTail(head, tail, a);
        }
        head = deleteMiddle(head, n);
        display(head);   
        
    }



