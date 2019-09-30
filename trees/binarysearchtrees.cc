#include<iostream>
#include<queue>
using namespace std;
class TreeNode{
public:
	int data;
	TreeNode*left;
	TreeNode*right;
	TreeNode*(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};
TreeNode*insertIntoBst(TreeNode*root,int x){
	if(root == NULL) {
		root = new TreeNode(x);
		return root;
	}
	if(x>root->data){
		root->right = insertIntoBst(root->right,x);
		return root;
	}
	else{
		root->left = insertIntoBst(root->left,x);
		return root;
	}
}
TreeNode*createBst(int stopper){
	int x;

	TreeNode*root = NULL;
	while(true){
		cin>>x;
		if(x==stopper) break;
		root = insertIntoBst(root,x);
	}
	return root;
}
void printPreOrderBst(TreeNode*root){
	if(root == NULL) return;
	printBst(root->left);
	cout<<root->data;
	printBst(root->right);
}
int main(){

}