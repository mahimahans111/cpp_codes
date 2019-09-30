#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* prev;
	Node*next;
	Node(int d){
		data = d;
		prev = NULL;
		next = NULL;
	}
};

void addAtHead(Node*&head, Node*&tail, int data){
	Node*newNode = new Node(data);
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}
	
	else if(head == tail){
	    head = newNode;
	    head->next = tail;
	    tail->prev = head;
	    tail->next = head;
	    head->prev = tail;
	}

	else{
		newNode->next = head;
		tail->next = newNode;
		newNode->prev = tail;
		//newNode->prev = NULL .. this happens in constructor already
		head->prev = newNode;
		head = newNode;
	}
}

void addAtTail(Node*&head, Node*&tail, int data){
	Node*newNode = new Node(data);
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}
	
	else if(head == tail){
	    tail = newNode;
	    head->next = tail;
	    tail->prev = head;
	    tail->next = head;
	    head->prev = tail;
	}
	
	else{
		tail->next = newNode;
		newNode->next = head;
		head->prev = newNode;
		newNode->prev = tail;
		tail = newNode;
	}

}

void removeFromHead(Node*&head, Node*&tail){
	if(head == NULL) return;
	if(head == tail){
		head = NULL;
		tail = NULL;
		return;
	}
	else{
		head = head->next;
		head->prev = tail;
		tail->next = head;
		return;
	}
}

void removeFromTail(Node*&head, Node*&tail){
	if(head == NULL) return;
	if(head == tail){
		head = NULL;
		tail = NULL;
		return;
	}
	else{
		tail = tail->prev;
		tail->next = head;
		head->prev = tail;
		return;
	}	
}

class CircularDeque {
    public:
 	int size;
	Node* head;
	Node* tail;
	int sze;
 
        CircularDeque(int k) {
        head = NULL;
		tail = NULL;
		size = k;
		sze = 0;
         }
 
          bool isFull() {
              return (sze == size);
         }
         
         bool isEmpty() {
             return (head == NULL);
         }
 
         
         bool insertFront(int x) {
             if(!isFull()){
                addAtHead(head, tail, x);
                sze++;
                return true;
             }
             return false;
         }
 
         bool insertLast(int x) {
             if(!isFull()){
                 addAtTail(head, tail, x);
                 sze++;
                 return true;
             }
             return false;
         }
 
         bool deleteFront() {
             if(!isEmpty()){
                 removeFromHead(head, tail);
                 sze--;
                 return true;
             }
             return false;
         }
 
         bool deleteLast() {
             if(!isEmpty()){
                 removeFromTail(head, tail);
                 sze--;
                 return true;
             }
             return false;             
         }
 
         int getFront() {
             if(isEmpty()) return -1;
             return head->data;
         }
 
         int getRear() {
             if(isEmpty()) return -1;
             return tail->data;
         }


 
     };


int main(){
    int size; cin >> size;
    CircularDeque cd(size);
    int n; cin >> n;
    
         for (int i = 0; i < n; i++) {
             int q; cin >> q;
             string s = "";
             if (q == 1) {
                 int a; cin >> a;
                //  cout << cd.insertFront(a) << endl;
                 if(cd.insertFront(a)) cout << "true" << " ";
                 else cout << "false" << " ";
             } else if (q == 0) {
                 int a; cin >> a;
                  if(cd.insertLast(a)) cout << "true" << " ";
                 else cout << "false" << " ";
                //  cout << cd.insertLast(a) << endl;
             } else if (q == 2) {
                  if(cd.deleteFront()) cout << "true" << " ";
                 else cout << "false" << " ";
                //  cout << cd.deleteFront() << endl;
             } else if (q == -2) {
                  if(cd.deleteLast()) cout << "true" << " ";
                 else cout << "false" << " ";
                //  cout << cd.deleteLast() << endl;
             } else if (q == 3) {
                cout << cd.getFront() << " ";
             } else if (q == -3) {
                 cout << cd.getRear() << " ";
             } else if (q == 4) {
                  if(cd.isEmpty()) cout << "true" << " ";
                 else cout << "false" << " ";
                //  cout << cd.isEmpty() << endl;
             } else if (q == 5) {
                  if(cd.isFull()) cout << "true" << " ";
                 else cout << "false" << " ";
                //  cout << cd.isFull() << endl;
             }
            //  System.out.print(s + " ");
            // cout << s << " ";
         }    
}

// int main(){
//     int size; cin >> size;
//     CircularDeque cd(size);
//     int n; cin >> n;
    
//          for (int i = 0; i < n; i++) {
//              int q; cin >> q;
//              string s = "";
//              if (q == 1) {
//                  int a; cin >> a;
//                 //  s = "" + cd.insertFront(a);
//              } else if (q == 0) {
//                  int a; cin >> a;
//                 //  s = "" + cd.insertLast(a);
//              } else if (q == 2) {
//                  s = "" + cd.deleteFront();
//              } else if (q == -2) {
//                  s = "" + cd.deleteLast();
//              } else if (q == 3) {
//                  s = "" + cd.getFront();
//              } else if (q == -3) {
//                  s = "" + cd.getRear();
//              } else if (q == 4) {
//                  s = "" + cd.isEmpty();
//              } else if (q == 5) {
//                  s = "" + cd.isFull();
//              }
//             //  System.out.print(s + " ");
//             cout << s << " ";
//          }    
// }


//      // Dont make changes here
//      public static void main(String[] args) {
//          Scanner sc = new Scanner(System.in);
//          CircularDeque cd = new CircularDeque(sc.nextInt());
//          int n = sc.nextInt();
//          for (int i = 0; i < n; i++) {
//              int q = sc.nextInt();
//              String s = "";
//              if (q == 1) {
//                  s = "" + cd.insertFront(sc.nextInt());
//              } else if (q == 0) {
//                  s = "" + cd.insertLast(sc.nextInt());
//              } else if (q == 2) {
//                  s = "" + cd.deleteFront();
//              } else if (q == -2) {
//                  s = "" + cd.deleteLast();
//              } else if (q == 3) {
//                  s = "" + cd.getFront();
//              } else if (q == -3) {
//                  s = "" + cd.getRear();
//              } else if (q == 4) {
//                  s = "" + cd.isEmpty();
//              } else if (q == 5) {
//                  s = "" + cd.isFull();
//              }
//              System.out.print(s + " ");
//          }
 
//      }
 
//  }