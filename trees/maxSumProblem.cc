///question- It's that you are given a tree, and you have to find the maximum subset sum, and there's
///this condtion that if you include a node in a particular subset, you can't include it's parent or 
///children in the subset. so here again we go on with the bottom up approach. we take that subset sum
/// which has children included and hence we don't include that node,and we take subsets which doesn't
///have children included , hence we take the node, the max of them gives the answer.

#include<iostream>
using namespace std;

class TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data){
		data = d;
		left = NULL;
		right = NULL;
	}
};

TreeNode* createTree(){
	int data; cin >> data;
	if(data == -1) return NULL;
	TreeNode* root = new TreeNode(data);
	root->left = createTree();
	root->right = createTree();
	return root;
}

class sumPair{
	int exc;
	int inc;
};

sumPair maxSumProblem(TreeNode* root){
	sumPair p;
	if(root == NULL){
		p.exc = 0;
		p.inc =  0;
		return p;
	}

	sumPair leftSum = maxSumProblem(root->left);
	sumPair rightSum = maxSumProblem(root->right);

	p.inc = root->data + leftSum.exc + rightSum.exc;
	p.exc = max(left.exc, left.inc) + max(right.exc, right.inc);

	return p;
}

int main(){
	TreeNode* root = createTree();
	sumPair p = maxSumProblem(root);
	int ans = max(p.inc, p.exc);
	cout << "maximum possible subset sum is" << ans;
}