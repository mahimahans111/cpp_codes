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
     Node*middle(Node*head){
         Node*slow=head; Node*fast=head;
         while(slow && fast && slow->next && fast->next && fast->next->next){
             slow=slow->next;
             fast=fast->next->next;
         }
         return slow;
     }
     
     Node*reverse(Node*head){
         if(head==NULL || head->next == NULL) return head;
         Node*prev=NULL;
         Node*cur=head;
         while(cur){
             Node*ahead = cur->next;
             cur->next=prev;
             prev=cur;
             cur=ahead;
         }
         return prev;
     }
     
     bool checkPalindrome(Node*head){
         Node*mid = middle(head);
         Node*cur= head;
         Node*temp=NULL;
         temp=mid->next;
         mid->next=NULL;
         temp=reverse(temp);
         while(temp && cur){
             if(cur->data!=temp->data) return false;
             temp=temp->next; cur=cur->next;
         }
         return true;
     }
     
     int main(){
        int n;
        cin >> n;
        Node*head = NULL;
        Node*tail = NULL;
        int a;
        for(int i = 0; i < n; i++){
            cin >> a;
            insertAtTail(head, tail, a);
        }
        bool ans = checkPalindrome(head);
        cout << ans;
     }