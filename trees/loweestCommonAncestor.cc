#include<bits/stdc++.h>
using namespace std;

int s = 0;
Treenode*lca;
bool lca(TreeNode* root, int d1, int d2){
	if(root == NULL) return false;

	bool sf = false;

	if(root->data == d1 || root->data == d2) {
		sf = true;
		s++;
	}

	if(s < 2){
		bool lf = lca(root->left, d1, d2);
		bool rf = lca(root->right, d1, d2);
		if((lf&&rf)||(lf&&sf)||(rf&&sf))lca = root;
		return lf||rf||sf;
	}
	else return true;
}

int main(){

}