
     
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
     
     bool checkSorted(Node* head) {
         if (head == NULL) {
             return true;
         }
 
         Node* curr = head;
 
         bool result = true;
         while (curr->next != NULL && curr->next != head) {
             if(curr->data > curr->next->data){
                 return false;
             }
             curr = curr->next;
         }
     
         return result;
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
     
        void display(Node*head, Node*tail){
         Node*temp = head;
         cout << temp->data;
         temp = temp->next;
             while(temp!=head){
             cout <<" " << temp->data;
             temp=temp->next;
         }
     }
     
     Node*insertIntoCSortedLL(Node*head, Node*tail, int n, int k){
         Node*one = new Node(k);
         if(head == NULL){
            head = one;
         }
         if(n >= 2){
             Node*cur = head;
             Node*ahead =NULL;
             int flag = 0;
             while(cur->next!=head){
                ahead = cur->next;
                 if(cur->data <= k && k <= ahead->data){
                    
                     cur->next = one;
                     one->next = ahead;
                     flag = 1;
                 }
                 cur = cur->next;
             }
             if(flag == 0){
                if(k>=tail->data){
                    tail->next = one;
                    one->next = head;
                }
                if(k <= head->data){
                    tail->next = one;
                    one->next = head;
                    head = one;
                }
             }
         }
         return head;
         
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
         tail->next = head;
         int k; cin >> k;
         head = insertIntoCSortedLL(head, tail, n, k);
         display(head, tail);
         
     }
     
     
     
     