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
     
     int noOfConnectedComp(Node*head, map<int, int> m){
         int count = 0;
         Node*temp = head;
         bool flag = false;
         while(temp){
             if(flag == false){
                 if(m.count(temp->data)){
                     count++;
                     flag = true;
                 }
             }
             else{
                 if(!m.count(temp->data)){
                    flag = false; 
                 }
             }
             temp = temp->next;
         }
         return count;
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
         int n2; cin >> n2;
         map<int, int> m;
         for(int i = 0; i < n2; i++){
             cin >> a;
             m[a] = 1;
         }
         int ans = noOfConnectedComp(head, m);
         cout << ans;
     }
     
     