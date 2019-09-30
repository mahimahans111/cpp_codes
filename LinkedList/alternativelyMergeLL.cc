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
     int flag = 1;
     
    Node* alternativelyMerge(Node*&head1, Node*&head2){
         Node*one= head1;
         Node*two = head2;
         while(one && two){
             Node*onen = one->next;
             Node*twon = two->next;
             one->next = two;
             two->next = onen;
             one=onen;
             two=twon;
         }
         if(!one){
             return two;
         }
         
         if(!two){
             return NULL;
         }
     }
     
     int main(){
         int n, m; 
         int a;
         Node*head1 = NULL;
         Node*tail1 = NULL;
         Node*head2 = NULL;
         cin >> n;
         Node*tail2 = NULL;
         for(int i = 0; i < n; i++){
             cin >> a;
             insertAtTail(head1, tail1, a);
         }
         cin >> m;
         for(int i = 0; i < m; i++){
             cin >> a;
             insertAtTail(head2, tail2, a);
         }
        Node* head = alternativelyMerge(head1, head2);
        display(head1);
        cout << endl;
        display(head);
         
     }
     
     