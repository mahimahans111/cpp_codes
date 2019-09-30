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
             cout << temp->data;
             temp=temp->next;
         }
     }
     
     Node* reverseLL(Node*head){
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
     
     Node* addLL(Node*head1, Node*head2){
         Node*temp1 = head1; Node*temp2 = head2;
        //   temp1 = reverseLL(temp1);
        //   temp2 = reverseLL(temp2);
         Node*cur1 = temp1;
         Node*cur2 = temp2;
         Node*curh = NULL;
         Node*curt = NULL;
         int no1 = cur1->data;
         int no2 = cur2->data;
         int ans = (no1+no2)%10;
         int carry = (no1+no2)/10;
         cur1 = cur1->next;
         cur2 = cur2->next;
         insertAtTail(curh, curt, ans);
         while(cur1 && cur2){
             int no1 = cur1->data;
             int no2 = cur2->data;
             int ans = (no1+no2+carry)%10;
             carry = (no1+no2+carry)/10;
             insertAtTail(curh, curt, ans);
             cur1 = cur1->next;
             cur2 = cur2->next;
         }
         while(cur1){
             int no1 = cur1->data;
             int ans = (no1+carry)%10;
             carry = (no1+carry)/10;
             insertAtTail(curh, curt, ans);
             cur1 = cur1->next;
         }
         while(cur2){
             int no2 = cur2->data;
             int ans = (no2+carry)%10;
             carry = (no2+carry)/10;
             insertAtTail(curh, curt, ans);
             cur2 = cur2->next;
         }
            while(carry){
              insertAtTail(curh, curt, carry);
              carry = carry/10;
            }        //   curh = reverseLL(curh);
         return curh;
    }
    
    Node* multiplyLL(Node*head1, Node*head2){
        Node*temp1 = head1;
        Node*temp2 = head2;
        temp1 = reverseLL(temp1);
        temp2 = reverseLL(temp2);
        Node*cur1 = temp1;
        Node*cur2= temp2;
        int z = 0;
        int carry = 0;
        Node* m = NULL;
        while(temp2){
            Node*curh = NULL, *curt = NULL;
            for(int i = 0; i < z; i++){
                insertAtTail(curh, curt, 0);
            }
            z++;
            while(temp1){
                int no1 = temp1->data;
                int no2 = temp2->data;
                int ans = (no1*no2+carry)%10;
                carry = (no1*no2+carry)/10;
                insertAtTail(curh, curt, ans);
                temp1 = temp1->next;
            }
            temp1 = cur1;
            while(carry){
              insertAtTail(curh, curt, carry);
              carry = carry/10;
            } 
           // display(curh); cout << endl;
            if(m == NULL){
                m = curh;
            }
            else{
                m = addLL(m, curh);
            }
            temp2 = temp2->next;
        }
        //m = reverseLL(m);
        return m;
        
    }
     
     int main(){
         int n; cin >> n;
         Node*head1=NULL, *head2=NULL, *tail1 = NULL, *tail2 = NULL;
         int a;
         for(int i = 0; i < n; i++){
             cin >> a;
             insertAtTail(head1, tail1, a);
         }
         int m;
         cin >> m;
         for(int i = 0; i < m; i++){
             cin >> a;
             insertAtTail(head2, tail2, a);
         }
         Node* ans = multiplyLL(head1, head2); 
         int p=1;
         long long int no = 0;
         while(ans){
             no+=(p*(ans->data))%1000000007;
             //cout << no << endl;
             p=p*10;
             ans=ans->next;
         }
         //no=no%(10^9 + 7);
         //int M = 10^9 + 7;
         cout << no%(1000000007);
     }
     
     
     