bool hasPathSum(Node *root, int sum)
{
   //Your code here
   if(root == NULL) return false;
   if(root->left == NULL && root->right == NULL){
       if(sum == root->data) return true;
   }

   if(hasPathSum(root->left, sum-root->data) || hasPathSum(root->right, sum-root->data)) return true;
   else return false;
}