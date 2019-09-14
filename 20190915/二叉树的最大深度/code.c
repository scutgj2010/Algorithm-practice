int maxDepth(struct TreeNode* root){
    if(NULL == root)
    {
        return 0;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    int depth = (left>right)?left+1:right+1;
    return depth;
}