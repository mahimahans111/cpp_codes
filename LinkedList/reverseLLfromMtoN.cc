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
     
     Node*reverseLLFromMtoN(Node*head, int m, int n, int no){
         if(m == 1){
             if(n!=no){
              int i =0;
                Node*prev = NULL;
                Node*cur = head; 
                 Node*temptail = cur;
                Node*ahead = cur->next;
                 while(cur && i < n){
                    ahead = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = ahead;
                    i++;
         }
         temptail->next = cur;
         head = prev;
         return head;
             }
             if(n == no){
               int i =0;
         Node*prev = NULL;
         Node*cur = head;
        //  Node*temphead = prev;
        //  Node*temptail = cur;
         Node*ahead = cur->next;
         //cout << i << endl;
         // cout << temphead->data << endl << temptail->data << endl;
         while(cur && i < n){
             ahead = cur->next;
             cur->next = prev;
             prev = cur;
             cur = ahead;
             i++;
         }  
         //temptail->next = cur;
         
         return prev;
         
             }
         }
         
         int i =0;
         Node*prev = NULL;
         Node*cur = head;
         while(cur && i < m-1){
            prev = cur;
             cur = cur->next;
            // cout << prev->data << endl << cur->data << endl;
             i++;
         }
         Node*temphead = prev;
         Node*temptail = cur;
         Node*ahead = cur->next;
         //cout << i << endl;
         // cout << temphead->data << endl << temptail->data << endl;
         while(cur && i < n){
             ahead = cur->next;
             cur->next = prev;
             prev = cur;
             cur = ahead;
             i++;
         }
         // cout << prev->data << endl << cur->data << endl << ahead->data << endl;
         // cout << i << endl;
         
         temphead->next = prev;
         temptail->next = cur;
         
         return head;
     }
     
     int main(){
         int no;
          cin >> no;
          int a;
          Node*head= NULL;
          Node*tail = NULL;
          for(int i = 0; i < no; i++){
              cin >> a;
              insertAtTail(head, tail, a);
          }
          int m, n;
          cin >> m >> n;
          head = reverseLLFromMtoN(head, m, n, no);
          display(head);
     }
     