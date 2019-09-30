
// C++ program to check whether a given 
// Binary Tree is Perfect or not 
#include<bits/stdc++.h> 
  
/*  Tree node structure */
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
  
// Returns depth of leftmost leaf. 
int findADepth(Node *node) 
{ 
   int d = 0; 
   while (node != NULL) 
   { 
      d++; 
      node = node->left; 
   } 
   return d; 
} 
  
/* This function tests if a binary tree is perfect 
   or not. It basically checks for two things : 
   1) All leaves are at same level 
   2) All internal nodes have two children */
bool isPerfectRec(struct Node* root, int d, int level = 0) 
{ 
    // An empty tree is perfect 
    if (root == NULL) 
        return true; 
  
    // If leaf node, then its depth must be same as 
    // depth of all other leaves. 
    if (root->left == NULL && root->right == NULL) 
        return (d == level+1); 
  
    // If internal node and one child is empty 
    if (root->left == NULL || root->right == NULL) 
        return false; 
  
    // Left and right subtrees must be perfect. 
    return isPerfectRec(root->left, d, level+1) && 
           isPerfectRec(root->right, d, level+1); 
} 
  
// Wrapper over isPerfectRec() 
bool isPerfect(Node *root) 
{ 
   int d = findADepth(root); 
   return isPerfectRec(root, d); 
} 
  
/* Helper function that allocates a new node with the 
   given key and NULL left and right pointer. */
struct Node *newNode(int k) 
{ 
    struct Node *node = new Node; 
    node->key = k; 
    node->right = node->left = NULL; 
    return node; 
} 
  
// Driver Program 
int main() 
{ 
    struct Node* root = NULL; 
    root = newNode(10); 
    root->left = newNode(20); 
    root->right = newNode(30); 
  
    root->left->left = newNode(40); 
    root->left->right = newNode(50); 
    root->right->left = newNode(60); 
    root->right->right = newNode(70); 
  
    if (isPerfect(root)) 
        printf("Yes\n"); 
    else
        printf("No\n"); 
  
    return(0); 
} 