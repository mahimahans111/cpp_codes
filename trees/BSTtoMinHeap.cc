// Program to convert a BST into a Min-Heap 
// in O(n) time and in-place 
#include <iostream> 
#include <queue> 
using namespace std; 

// Node for BST/Min-Heap 
struct Node 
{ 
	int data; 
	Node *left, *right; 
}; 

// Utility function for allocating node for BST 
Node* newNode(int data) 
{ 
	Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 
	return node; 
} 

// Utility function to print Min-heap level by level 
void printLevelOrder(Node *root) 
{ 
	// Base Case 
	if (root == NULL) return; 

	// Create an empty queue for level order traversal 
	queue<Node *> q; 
	q.push(root); 

	while (!q.empty()) 
	{ 
		int nodeCount = q.size(); 
		while (nodeCount > 0) 
		{ 
			Node *node = q.front(); 
			cout << node->data << " "; 
			q.pop(); 
			if (node->left) 
				q.push(node->left); 
			if (node->right) 
				q.push(node->right); 
			nodeCount--; 
		} 
		cout << endl; 
	} 
} 

// A simple recursive function to convert a given 
// Binary Search tree to Sorted Linked List 
// root	 --> Root of Binary Search Tree 
// head_ref --> Pointer to head node of created 
//			 linked list 
void BSTToSortedLL(Node* root, Node** head_ref) 
{ 
	// Base cases 
	if(root == NULL) 
		return; 

	// Recursively convert right subtree 
	BSTToSortedLL(root->right, head_ref); 

	// insert root into linked list 
	root->right = *head_ref; 

	// Change left pointer of previous head 
	// to point to NULL 
	if (*head_ref != NULL) 
		(*head_ref)->left = NULL; 

	// Change head of linked list 
	*head_ref = root; 

	// Recursively convert left subtree 
	BSTToSortedLL(root->left, head_ref); 
} 

// Function to convert a sorted Linked 
// List to Min-Heap. 
// root --> Root of Min-Heap 
// head --> Pointer to head node of sorted 
//			 linked list 
void SortedLLToMinHeap(Node* &root, Node* head) 
{ 
	// Base Case 
	if (head == NULL) 
		return; 

	// queue to store the parent nodes 
	queue<Node *> q; 

	// The first node is always the root node 
	root = head; 

	// advance the pointer to the next node 
	head = head->right; 

	// set right child to NULL 
	root->right = NULL; 

	// add first node to the queue 
	q.push(root); 

	// run until the end of linked list is reached 
	while (head) 
	{ 
		// Take the parent node from the q and remove it from q 
		Node* parent = q.front(); 
		q.pop(); 

		// Take next two nodes from the linked list and 
		// Add them as children of the current parent node 
		// Also in push them into the queue so that 
		// they will be parents to the future nodes 
		Node *leftChild = head; 
		head = head->right;	 // advance linked list to next node 
		leftChild->right = NULL; // set its right child to NULL 
		q.push(leftChild); 

		// Assign the left child of parent 
		parent->left = leftChild; 

		if (head) 
		{ 
			Node *rightChild = head; 
			head = head->right; // advance linked list to next node 
			rightChild->right = NULL; // set its right child to NULL 
			q.push(rightChild); 

			// Assign the right child of parent 
			parent->right = rightChild; 
		} 
	} 
} 

// Function to convert BST into a Min-Heap 
// without using any extra space 
Node* BSTToMinHeap(Node* &root) 
{ 
	// head of Linked List 
	Node *head = NULL; 

	// Convert a given BST to Sorted Linked List 
	BSTToSortedLL(root, &head); 

	// set root as NULL 
	root = NULL; 

	// Convert Sorted Linked List to Min-Heap 
	SortedLLToMinHeap(root, head); 
} 

// Driver code 
int main() 
{ 
	/* Constructing below tree 
				8 
			/ \ 
			4	 12 
		/ \ / \ 
		2 6 10 14 
	*/

	Node* root = newNode(8); 
	root->left = newNode(4); 
	root->right = newNode(12); 
	root->right->left = newNode(10); 
	root->right->right = newNode(14); 
	root->left->left = newNode(2); 
	root->left->right = newNode(6); 

	BSTToMinHeap(root); 

	/* Output - Min Heap 
				2 
			/ \ 
			4	 6 
		/ \ / \ 
		8 10 12 14 
	*/

	printLevelOrder(root); 

	return 0; 
} 
