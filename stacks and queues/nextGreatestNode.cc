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
     
     Node*reverseLL(Node*head){
         Node*cur = head;
         Node*prev = NULL;
         while(cur){
             Node*ahead = cur->next;
             cur->next = prev;
             prev = cur;
             cur = ahead;
         }
         return prev;
     }
     
     void nextGreaterNode(Node*head, int n, int ans[]){
         Node*temp = head;
         temp = reverseLL(temp);
         Node*cur = temp;
         stack<int>s;
         int i = 0;
         while(cur){
             if(s.empty()){
                 ans[i] = 0;
                 s.push(cur->data);
             }
             else{
                 while(!s.empty() && s.top() <= cur->data){
                     s.pop();
                 }
                 if(s.empty()) ans[i] = 0;
                 else ans[i] = s.top();
                 s.push(cur->data);
             }
             cur = cur->next; i++;
         }
     }
     
int main(){
    int n;
    cin >> n;
    int arr[n];
    Node*head = NULL; Node*tail = NULL;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        insertAtTail(head, tail, arr[i]);
    }
    int ans[n];
    nextGreaterNode(head, n, ans);
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    
}