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
    // This function takes as input the head of the linked list.
    // It should return the head of the rearranged linked list.
    
    Node*middle(Node*head){
        Node*slow= head; Node*fast = head;
        while(slow && slow->next && fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* reverseLL(Node*head){
        Node*prev = NULL;
        Node*cur = head;
        while(cur){
            Node*ahead = cur->next;
            cur->next = prev;
            prev = cur;
            cur = ahead;
        }
        return prev;
    }
    
    Node*alternativelyMerge(Node*head1, Node*head2){
         Node*one= head1;
         Node*two = head2;
         while(one && two){
             Node*onen = one->next;
             Node*twon = two->next;
             one->next = two;
             two->next = onen;
             one=onen;
             two=twon;
         }
         return head1;
    }
    
    Node* rearrange(Node* node)
    {
        // write your code here
        Node* cur = head;
        Node*mid = middle(head);
        Node*temp = mid->next;
        mid->next = NULL;
        temp = reverseLL(temp);
        display(cur);
        cout << endl;
        display(temp);
        cout << endl;
        Node*ans=alternativelyMerge(cur, temp);
        //display(ans);   
        return ans;
    }
    
    // -----------------------------------------------------
    
    int main()
    {
        int s;
        cin >> s;
        int a;
        cin >> a;
        head = insert(NULL, a);
        Node *tail = head;
        for (int i = 1; i < s; i++)
        {
            int temp;
            cin >> temp;
            tail = insert(tail, temp);
        }
    
        Node* rehead = rearrange(head);
        display(rehead);
    
    }