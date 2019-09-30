#include<iostream>
using namespace std;

class Treenode{
	int data;
	Treenode* left;
	Treenode* right;
	Treenode(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

Treenode* insertInBST(Treenode* root, int data){
	if(root == NULL){
		root = new Treenode(data);
		return root;
	}
	if(data < root->data){
		root->left = insertInBST(root->left, data);
	}
	else{
		root->right = insertInBST(root->right, data);
	}
	return root;
}

Treenode* createBST(){
	int data;
	cin >> data;
	while(data!= -1){
	Treenode* root = insertInBST(root, data);
	cin >> data;
	}
}
//complexity of the search function is O(H). During one search, one height will be traversed anyway.
//O(log n) <= O(H) <= O(n) ..maximum height of a tree is n as in case of a skew tree and min height is 
//log(2)n in case of a balanced tree.
bool searchInBST(Treenode* root, int data){
	if(root == NULL) return false;
	if(root->data == data) return true;
	if(root->data < data) return searchInBST(root->right, data);
	return searchInBST(root->left, data);
}
