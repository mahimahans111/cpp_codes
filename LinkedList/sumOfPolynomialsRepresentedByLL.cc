#include<bits/stdc++.h>
 using namespace std;
   
     class Node {
         public:
         pair<int, int> data;
         Node* next;
         Node(){
             
         }
 
         Node(int x, int y) {
             this->data.first = x;
             this->data.second = y;
             this->next = NULL;
         }
 
     };
     
     void insertAtTail (Node*&head, Node*&tail, int x, int y){
        Node* newNode = new Node(x, y);
         if(head == NULL){
             head = newNode;
             tail = newNode;
         }
         else{
             tail->next = newNode;
             tail=tail->next;
         }
     }
     
     
        void display(Node*head){
         Node*temp = head;
        cout << temp->data.first << 'x' << '^' << temp->data.second;
             temp=temp->next;
         while(temp){
             cout << " " << '+' << " " <<temp->data.first << 'x' << '^' << temp->data.second;
             temp=temp->next;
         }
     }
     
     Node*sumofpolynomials(Node*head1, Node*head2){
         Node*ansh = NULL;Node*anst = NULL;
         //Node*cur=ans;
         Node*temp1 = head1; Node*temp2 = head2;
         while(temp1 && temp2){
             if(temp1->data.second > temp2->data.second){
                 insertAtTail(ansh, anst, temp1->data.first, temp1->data.second);
                 temp1 = temp1->next;
             }
             else if(temp2->data.second > temp1->data.second){
                 insertAtTail(ansh, anst, temp2->data.first, temp2->data.second);
                 temp2 = temp2->next;
             }
             else{
                 insertAtTail(ansh, anst, temp1->data.first+temp2->data.first, temp1->data.second);
                 temp1 = temp1->next;
                 temp2 = temp2->next;
             }
         }
         while(temp1){
             insertAtTail(ansh, anst, temp1->data.first, temp1->data.second);
                 temp1 = temp1->next;
         }
         while(temp2){
              insertAtTail(ansh, anst, temp2->data.first, temp2->data.second);
                 temp2 = temp2->next;
         }
         return ansh;
     }
     
     int main(){
         int n; cin >> n;
         int x, y;
         Node*head1 = NULL;
         Node*tail1 = NULL;
         Node*head2 = NULL;
         Node*tail2 = NULL;
         for(int i = 0; i < n; i++){
             cin >> x >> y;
             insertAtTail(head1, tail1, x, y);
         }
         int m; cin >> n;
         for(int i = 0; i < n; i++){
             cin >> x >> y;
             insertAtTail(head2, tail2, x, y);
         }
         Node*ans = sumofpolynomials(head1, head2);
         display(ans);
     }
     
     