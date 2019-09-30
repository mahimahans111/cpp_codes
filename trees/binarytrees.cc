#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
	int data;
	TreeNode*left;
	TreeNode*right;
	TreeNode(int d){
		data=d;
		left=NULL;
		right=NULL;
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
void printpreorder(TreeNode*root){
	if(root == NULL) return;
	cout<<root->data<<" ";
	printpreorder(root->left);
	printpreorder(root->right);
}
void printpostorder(TreeNode*root){
	if(root == NULL) return ;
	printpostorder(root->left);
	printpostorder(root->right);
	cout<<root->data<<" ";
}
//printing a particular level..
void printlevel(TreeNode*root,int level){
	if((root == NULL)||level<0)  return;
	if(level == 0) 
	{
		cout<<root->data<<" "; 
		return ;
	}
	printlevel(root->left,level-1);
	printlevel(root->right,level-1);
}
void levelorderprint(TreeNode*root){
	int min_level = 0;
	int max_level = height(root);
	for (int depth = min_level ; depth <= max_level ; depth++){
		printlevel(root,depth);
		cout<<endl;
	}
}

int diameter(const TreeNode*root){
	if(root== NULL) return 0;
	int left_dia = diameter(root->left);
	int right_dia = diameter(root->right);
	int curr_dia = height(root->left) + height(root->right) + 1;
	return max(max(left_dia,right_dia),curr_dia);
}
int countTreeNodes(TreeNode*root){
	if(root == NULL){
		return 0;
	}
	int ans = 1 + countTreeNodes(root->left) + countTreeNodes(root->right);
	return ans;
}
// *Question* -- replace every node with sum of nodes + node_data in the tree..
 int replacewithsum(TreeNode*root){
 	if(root == NULL){
 		return 0;
 	}
 	int leftsum = replacewithsum(root->left);
 	int rightsum = replacewithsum(root->right);
 	root->data += leftsum + rightsum ;
 	return root->data;
 }
 // *Question -- replace node with children ka sum..
   int replaceWithChildSum(TreeNode*root){
   	if(root == NULL) return 0;
   	if(root->left == NULL && root->right == NULL){
   		return root->data;
   	}
   	int lsum = replaceWithChildSum(root->left);
   	int rsum = replaceWithChildSum(root->right);
   	int temp = root->data;
   	root->data = lsum + rsum;
   	return root->data + temp;
   }
   // count same value sub tree..
   bool isSameValSubtree(TreeNode*root){
   	if (root == NULL) return true;
   	bool isRoot = (root->left ? root->data == root->left->data:true)&&
   				  (root->right ? root->data == root->right->data:true);
   	return isRoot && isSameValSubtree(root->left) && isSameValSubtree(root->right);
   }
   int cntSameValSubTree(TreeNode*root){
   	if(root == NULL){
   		return 0;
   	}
   	int x = cntSameValSubTree(root->left);
   	int y = cntSameValSubTree(root->right);
   	bool isRootSameVal = isSameValSubtree(root);
   	return x + y + (isRootSameVal?1:0);
   }
   //2nd way..
   class Pair {
public:
    int cnt;
    bool isSameValSubTree;
    Pair(int c, bool isSameVal) {
        cnt = c;
        isSameValSubTree = isSameVal;
    }
};

Pair cntSameValSubTree2(TreeNode* root) {
    if (root == NULL) {
        return Pair(0, true);
    }

    Pair x = cntSameValSubTree2(root->left);
    Pair y = cntSameValSubTree2(root->right);

    Pair curAns(0, true);
    curAns.isSameValSubTree = (root->left ? root->data == root->left->data : true) &&
                              (root->right ? root->data == root->right->data : true) &&
                              x.isSameValSubTree &&
                              y.isSameValSubTree;

    curAns.cnt = x.cnt + y.cnt + (curAns.isSameValSubTree ? 1 : 0);
    return curAns;
}
// now the 3rd way bruh !
bool isSameValSubTree2(TreeNode* root, int& cnt) {
    // isSameValSubTree2 tells if the tree starting at root is a same value subtree
    // or not AND also update the cnt of same value subtrees in the tree starting at root
    
    if (root == NULL) {
        return true;
    }

    bool isLeft = isSameValSubTree2(root->left, cnt);
    bool isRight = isSameValSubTree2(root->right, cnt);

    bool isRootSameVal = (root->left ? root->data == root->left->data : true) &&
                         (root->right ? root->data == root->right->data : true) &&
                         isLeft && isRight;

    if (isRootSameVal) { ++cnt; }
    return isRootSameVal;
}

int cntSameValSubTree3(TreeNode* root){
    // wrapper function
    int cnt = 0;
    isSameValSubTree2(root, cnt);
    return cnt;
}


bool isBST(TreeNode*root, int minV = INT_MIN, int maxV = INT_MAX){
  if(root == NULL) return true;

  if(root->data >= minV && root->data <= maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV)){
    return true;
  }

  return false;
}

int main(){
	TreeNode*root = createTree();
	inorderprint(root);
	int ans1 = height(root);
	cout<<endl<<ans1;
	int ans2 = diameter(root);
	cout<<endl<<ans2;
}

