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
         cout << temp->data << " ";
         if(temp)temp=temp->next;
         while(temp!=head){
             cout << temp->data << " ";
             temp=temp->next;
         }
     }
     Node*middleCircular(Node*head){
         Node*slow=head; Node*fast=head;
         if(slow && fast && slow->next && fast->next && fast->next->next){
             slow = slow->next;
             fast = fast->next->next;
         }
         while(slow!=head && fast!=head && slow->next!=head && fast->next!=head && fast->next->next!=head){
             slow=slow->next;
             fast=fast->next->next;
         }
         return slow;
     }
     
     void splitCircular(Node*head, Node*tail){
         Node*mid = middleCircular(head);
         Node*temp = mid->next;
         mid->next = head;
         Node*cur = temp;
         tail->next = temp;
         display(head);
         cout << endl;
         display(cur);
         
     }
     
     int main(){
         int n;
         cin >> n;
         int a;
         Node*head = NULL;
         Node*tail = NULL;
         for(int i = 0; i < n; i++){
             cin >> a;
             insertAtTail(head, tail, a);
         }
         tail->next=head;
         if(n==1){
             cout << head->data;
         }
         else{
             splitCircular(head, tail);
         }
     }