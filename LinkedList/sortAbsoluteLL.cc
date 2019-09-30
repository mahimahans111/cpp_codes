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
     
     Node* sort(Node*head){
          Node*temp = head;
         Node*ph = NULL, *pt = NULL, *nh=NULL, *nt=NULL;
         while(temp){
             if(temp->data>=0){
                insertAtTail(ph, pt, temp->data);
             }
             else{
                insertAtHead(nh, nt, temp->data);
             }
             temp = temp->next;
         }
         if(ph==NULL) return nh;
         else if(nh == NULL) return ph;
         else{
             nt->next = ph;
         return nh; 
         }
     }
     
     int main(){
         int n; cin >> n;
         int arr[n];
         Node*head = NULL; Node*tail = NULL;
         for(int i = 0; i < n; i++){
             cin >> arr[i];
             insertAtTail(head, tail, arr[i]);
         }
         head= sort(head);
         display(head);
         
     }
     