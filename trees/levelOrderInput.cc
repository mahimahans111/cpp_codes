#include<iostream>
#include<queue>
using namespace std;

class TreeNode{
public:
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

int height(TreeNode* root){
	if(root == NULL) return 0;
	int x = height(root->left);
	int y = height(root->right);
	return max(x, y)+1;
}

void levelOrderInput(TreeNode* &root){
	//cout << "Enter the root node";
	int d; cin >> d;
	root = new TreeNode(d);
	queue<TreeNode*> q;
	q.push(root);
	
	while(!q.empty()){
		TreeNode* parent = q.front();
		q.pop();
		int c1, c2;
		//cout << "Enter children of " << parent->data;
		cin >> c1 >> c2;
		if(c1 != -1){
			parent->left = new TreeNode(c1);
			q.push(parent->left);
		}
		if(c2 != -1){
			parent->right = new TreeNode(c2);
			q.push(parent->right);
		}
	}
}

void printALevel(TreeNode* root, int level, vector<int> &myvector){
	if(root == NULL or level < 0) return;
	if(level == 0){
		myvector.push_back(root->data);
		return;
	}
	printALevel(root->left, level-1, myvector);
	printALevel(root->right, level-1, myvector);
}

void levelOrderPrint(TreeNode* root){
	int min_level = 0;
	int max_level = height(root);
	for(int depth = min_level; depth <= max_level; depth++){
		vector<int>myvector;
		printALevel(root, depth, myvector);
		cout << myvector[myvector.size()-1] << " ";
	}
}

int main(){
	TreeNode* root = NULL;
	levelOrderInput(root);
	levelOrderPrint(root);
}