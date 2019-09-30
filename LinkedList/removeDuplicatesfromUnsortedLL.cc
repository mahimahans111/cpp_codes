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
     
     Node*removeDuplicates(Node*head){
         map<int, int> m;
         //Node*temp = head;
         Node*prev = NULL;
         Node*cur = head;
         while(cur){
             if(m.count(cur->data)){
                 prev->next = cur->next;
                 cur=cur->next;
             }
             else{
                 m[cur->data]=1;
                 prev = cur;
                 cur=cur->next;
             }
         }
         return head;
     }
     
     int main(){
        int n; 
        cin >> n;
        int a;
        Node*head=NULL; Node*tail = NULL;
        for(int i = 0; i < n; i++){
            cin >> a;
            insertAtTail(head, tail, a);
        }
        Node*ans = removeDuplicates(head);
        display(ans);
     }
     
     
     
     
     
     
     