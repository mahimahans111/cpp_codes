#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
	int data;
	TreeNode*left;
	TreeNode*right;
	TreeNode*next;

	TreeNode(int d){
		data = d;
		left = NULL;
		right = NULL;
		next = NULL;
	}
}

TreeNode*createTree(){
	int x;
	cin >> x;
	if(x == -1) return NULL;
	TreeNode* root = new TreeNode(x);
	root->left = createTree();
	root->right = createTree();
	return root;
}

TreeNode*connectNodes(root){
	queue<TreeNode*> q;
	q.push_back(root);

	while(!q.empty()){
		TreeNode*hey = q.front();
		for(queue<TreeNode*>::iterator it = q.begin(); it!= q.end(); it++){
			if(it!=q.end())
			it->next = it+1;
		}
		q.pop();
		q.push(hey->left);
		q.push(hey->right);

	}
}

int main(){

}