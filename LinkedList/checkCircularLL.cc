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

     bool checkCircular(Node*head){
        if(head == NULL) return false;
        Node*temp = head;
        while(temp->next!=head && temp->next!=NULL){
            temp = temp->next;
        }
        if(temp->next == head)return true;
        else return false;
     }


     int main(){
        int n, s; cin >> n >> s;
        int arr[n];
        Node*head = NULL;
        Node*tail = NULL;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            insert(head, tail, arr[i]);
        }
        if(n > 0 && s == 1){
            tail->next = head;
        }
        bool ans = checkCircular(head);
        if(ans) cout << "true";
        else cout << "false";
     }