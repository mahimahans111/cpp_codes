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

    Node*swapKthNodes(Node*head, int n, int k){
        Node*p1 = NULL, *p2 = NULL, *c1 = NULL, *c2 = NULL, *n1 = NULL, *n2 = NULL;
        Node*temp = head;
        Node*prev = NULL;
        for(int i = 1; i <= n; i++){
            if(i == k){
                p1 = prev;
                c1 = temp;
                n1 = temp->next;
            }
            if(i == n-k){
                p2 = prev;
                c2 = temp;
                n2 = temp->next;
                //break;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << p1->data << " " << c1->data << " " << n1->data << " " << p2->data;
        p1->next = c2;
        c2->next = n1;
        p2->next = c1;
        c1->next = n2;
        
        return head;
    }


int main(){
    int n, k;
    cin >> n >> k;
    Node*head = NULL;
    Node*tail = NULL;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        insertAtTail(head, tail, a);
    }
    Node*ans = swapKthNodes(head, n, k);
    display(ans);
}