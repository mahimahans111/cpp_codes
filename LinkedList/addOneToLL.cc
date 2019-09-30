#include<bits/stdc++.h>
   
   using namespace std;
   
   class Node
   {
   public:
       int data;
       Node *next;
   
       Node(int data, Node *next)
       {
           this->data = data;
           this->next = next;
       }
   };
   
   Node *head = NULL;
   
   /*
       * Input Parameters: tail: tail of the linked list in which a new node is to
       * be inserted. data: the data value of the node which is to be inserted.
       * 
       * Return Value: tail of the linked list in which the node is inserted
   */
   Node *insert(Node *tail, int data)
   {
       if (tail == NULL)
       {
           return new Node(data, NULL);
       }
       else
       {
           tail->next = new Node(data, NULL);
           return tail->next;
       }
   }
   
   /*
       * Input Parameters: head: head of the linked list in which is to be
       * displayed.
       * 
       * Return Value: null
   */
   void display(Node *head)
   {
       for (Node *node = head; node != NULL; node = node->next)
       {
           cout << node->data << " ";
       }
       cout << endl;
   }
   
   // -----------------------------------------------------
   // This is a functional problem. Only this function has to be written.
   // It takes as input the head of the linked list. It should return the
   // head of the modifiec list.
   
   Node*reverse(Node*head){
       if(head==NULL||head->next==NULL) return head;
       Node*cur = head;
       Node*prev = NULL;
       while(cur){
           Node*ahead = cur->next;
           cur->next = prev;
           prev = cur;
           cur=ahead;
       }
       return prev;
   }
   
   Node *plusOne(Node *head)
   {
       // write your code here
       Node*temp = head;
       temp = reverse(temp);
       Node*cur = temp;
       int n=cur->data;
       cur->data=(n+1)%10;
       int carry = (n+1)/10;
       cur = cur->next;
       Node*prev = NULL;
       while(cur){
           int no = cur->data;
            cur->data=(no+carry)%10;
            carry = (no+carry)/10; 
            prev = cur;
           // cout << cur->data << " " << carry << endl;
            cur=cur->next;
       }
       if(carry) {prev->next = new Node(carry, NULL);}
       temp = reverse(temp);
       return temp;
   }
   
   // -----------------------------------------------------
   
   int main()
   {
       int s;
       cin >> s;
       int a;
       cin >> a;
       head = insert(NULL, a);
       Node *cur = head;
       for (int i = 1; i < s; i++)
       {
           int temp;
           cin >> temp;
           cur = insert(cur, temp);
       }
   
       Node *added = plusOne(head);
       display(added);
   }