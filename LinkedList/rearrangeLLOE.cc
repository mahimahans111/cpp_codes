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
     
     Node*rearrangeOE(Node*head){
         Node*temp = head;
         Node*oh=NULL, *ot=NULL, *eh=NULL, *et=NULL;
         int flag = 1;
         Node*ahead;
         while(temp){
             ahead = temp->next;
             if(flag == 1){
                 if(oh == NULL){
                     oh = temp;
                     ot = temp;
                 }
                 else{
                     ot->next=temp;
                     ot = ot->next;
                 }
             }
             else{
                if(eh == NULL){
                     eh = temp;
                     et = temp;
                 }
                 else{
                     et->next=temp;
                     et = et->next;
                 } 
             }
             temp->next = NULL;
             temp = ahead;
             flag = 1-flag;
         }
         if(eh == NULL) return oh;
         else if(oh == NULL) return eh;
         else{
             ot->next = eh;
             return oh;
         }
     }
     
     int main(){
         int n; cin >> n;
         int a;
         Node*head=NULL; Node*tail=NULL;
         for(int i = 0; i < n; i++){
             cin >> a;
             insertAtTail(head, tail, a);
         }
         Node*ans = rearrangeOE(head);
         display(head);
     }
     
     
     
     