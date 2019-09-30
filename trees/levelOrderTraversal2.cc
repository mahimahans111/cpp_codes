#include<iostream>
  #include<vector>
  #include<queue>
  using namespace std;
  
  // TreeNode class for a node of a Binary Search Tree
  class TreeNode {
      public:
  	  int val;
  	  TreeNode* left;
  	  TreeNode* right;
  
  	  TreeNode(int x) {
  	  	  val = x;
          left = NULL;
          right = NULL;
  	  }
  };
  
  // utility function to display a binary tree
  void display(TreeNode* node) {
      if (node == NULL) {
          return;
      }
      string str = "";
  
      str += node->left == NULL ? "." : to_string(node->left->val);
      str += " <= " + to_string(node->val) + " => ";
      str += node->right == NULL ? "." : to_string(node->right->val);
  
      cout<<str<<endl;
  
      display(node->left);
      display(node->right);
  }
  
  // creation of tree from array by level order, -1 says there is no node
  TreeNode* levelOrder(vector<int> &arr) {
      
      vector<TreeNode*> nodes(arr.size());
      for (int i = 0; i < nodes.size(); i++) {
          if (arr[i] != -1) {
              TreeNode* t = new TreeNode(arr[i]);
              nodes[i] = t;
  
              if (i > 0) {
                  int pi = (i - 1) / 2;
                  if (i == 2 * pi + 1) {
                      nodes[pi]->left = nodes[i];
                  } else {
                      nodes[pi]->right = nodes[i];
                  }
              }
          }
      }
      TreeNode* root = nodes[0];
      return root;
  }
  
  // This is a functional problem. You have to complete this function.
  // It takes as input the root of the given tree. It should return the
  // bottom-up level order traversal as an arraylist of arraylist.
  vector<vector<int> > createTreeBottom(TreeNode* node) {
      // write your code here.
      vector< vector<int> > ans;
      if(node == NULL)  return ans;
      queue<TreeNode*> q;
      q.push(node);
      while(q.size()>0){
          vector<int> v;
          int cnt = q.size();
          while(cnt--){
              TreeNode*t = q.front();
              v.push_back(t->val);
              q.pop();
              
              if(t->left)q.push(t->left);
              if(t->right)q.push(t->right);
          }
          ans.push_back(v);
      }
      for(int i = 0; i < ans.size()/2; i++){
        vector<int> m = ans[i];
        ans[i] = ans[ans.size()-1-i];
        ans[ans.size()-1-i] = m;
      }
      return ans;
  }	  
  
  int main(int argc, char** argv){
      // length of array representing the tree
      int len;
      cin>>len;
  
      vector<int> arr(len);
      for (int i = 0; i < len; i++) {
          cin>>arr[i];
      }
      TreeNode* root = levelOrder(arr);
  
  	  vector<vector<int> > res = createTreeBottom(root);
  
      for(vector<int> list: res) {
          for(int i: list){
              cout<<i<<" ";
          }
          cout<<endl;
      }
  
  }