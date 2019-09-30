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
     
     void insert (Node*&head, Node*&tail, int c){
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

     void display(Node*head){
         Node*temp = head;
         while(temp){
             cout << temp->data << " ";
             temp=temp->next;
         }
     }

     int binaryLLToDecimalNo(Node*head){
        Node*temp = head;
     int no = temp->data;
     temp = temp->next;
     while(temp){
         if(temp->data == 1){
             no = 2*no+1;
         }
         else no = 2*no;
         temp = temp->next;
     }
     return no;
     }
     
     int main(){
         int n; cin >> n;
         int a;
         Node*head = NULL;
         Node*tail = NULL;
         for(int i = 0; i < n; i++){
             cin >> a;
            insert(head, tail, a);
         }
         int ans = binaryLLToDecimalNo(head);
         cout << ans;
     }