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


      int countpair(Node *head1, Node *head2, int x)
  {
      int ans = 0;
      map<int, int>m;
      Node*temp = head1;
      while(temp){
          if(m.count(temp->data)>0){
              m[temp->data]+=1;
          }
          else{
              m[temp->data] = 1;
          }
          temp = temp->next;
      }
      
      Node*cur = head2;
      while(cur){
          if(m.count(x-cur->data)>0){
              ans+=m[x-cur->data];
          }
          cur = cur->next;
      }
      return ans;
      
  }
  
  int main()
  {
      int n1 = 0, n2 = 0, x = 0;
      cin >> n1;
      Node*head1 = NULL; Node*tail1 = NULL;
      Node*head2 = NULL; Node*tail2 = NULL;
      for (int i = 0; i < n1; i++)
      {
          int a;
          cin >> a;
          insert(head1, tail1, a);
      }
  
      cin >> n2;
  
      for (int i = 0; i < n2; i++)
      {
          int a = 0;
          cin >> a;
          insert(head2, tail2, a);
      }
  
      cin >> x;
  
      cout << countpair(head1, head2, x);
  
      return 0;
  }