#include<iostream>
#include<map>
#include<vector>
#include<iterator>
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

TreeNode*createTree(){
	int x;
	cin>>x;
	if(x==-1) return NULL;
	TreeNode*root = new TreeNode(x);
	root->left = createTree();
	root->right = createTree();
	return root;
}
int height(TreeNode*root){
	if(root==NULL) return 0;
	int x = height(root->left);
	int y = height(root->right);
	return max(x,y)+1;
}
void inorderprint(const TreeNode*root){
	if(root==NULL) return;
	inorderprint(root->left);
	cout<<root->data<<" ";
	inorderprint(root->right);
}
void vertical_order_printing(TreeNode* root, map<int, vector<int> > &m, int d = 0){
	if(root == NULL) return;

	m[d].push_back(root->data);
	vertical_order_printing(root->left, m, d-1);
	vertical_order_printing(root->right, m, d+1);
}

int main(){
	TreeNode* root = createTree();
	map<int, vector<int> > m;
	vertical_order_printing(root, m);
	//levelorderprint(root);
	//inorderprint(root);
	for(map<int, vector<int> >  :: iterator it = m.begin(); it!=m.end(); it++){
		cout << it->first << "->";
		for(int j = 0; j < it->second.size();j++){
			cout << it->second[j] << " ";
		}
		cout << endl;
	}
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1