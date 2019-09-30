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
     
     void swap(int& a, int& b){
         int temp = a;
         a = b;
         b = a;
     }
     
     void fashion(Node* &head){
         int flag = 1;
         Node*temp = head;
         while(temp){
             if(!flag && temp->data <= temp->next->data){
                 swap(temp->data, temp->next->data);
             }
             if(flag && temp->data >= temp->next->data){
                 swap(temp->data, temp->next->data);
             }
             temp = temp->next;
                      flag = 1-flag;

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
         fashion(head);
         display(head);
         
     }
     