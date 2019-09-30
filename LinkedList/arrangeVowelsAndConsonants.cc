 #include<bits/stdc++.h>
 using namespace std;
   
     class Node {
         public:
         char data;
         Node* next;
         Node(){
             
         }
 
         Node(char data) {
             this->data = data;
             this->next = NULL;
         }
 
     };
     
     void insert (Node*&head, Node*&tail, char c){
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
     
     Node*change(Node*head){
         Node*temp = head;
         Node*vh = NULL, *vt = NULL, *ch=NULL, *ct=NULL;
         while(temp){
             if(temp->data == 'a' || temp->data == 'e' || temp->data == 'o' || temp->data == 'i' || temp->data == 'u'){
                insert(vh, vt, temp->data);
             }
             else{
                insert(ch, ct, temp->data);
             }
             temp = temp->next;
         }
         if(vh==NULL) return ch;
         else if(ch == NULL) return vh;
         else{
             vt->next = ch;
         return vh; 
         }
        
     }
     
     void display(Node*head){
         Node*temp = head;
         while(temp){
             cout << temp->data << " ";
             temp=temp->next;
         }
     }
     
     int main(){
         int n; cin >> n;
         char arr[n];
         Node*head = NULL;
         Node*tail = NULL;
         for(int i = 0; i < n; i++){
             cin >> arr[i];
            insert(head, tail, arr[i]);
         }
         head = change(head);
         display(head);
     }
