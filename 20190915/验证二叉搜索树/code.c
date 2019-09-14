bool isABST(struct TreeNode* root,long min,long max){
    if(NULL == root)
    {
        return true;
    }
    if (root->val <= min || root->val >= max)
    {
        return false;
    }
    return isABST(root->left, min, root->val) && isABST(root->right, root->val, max);
}

bool isValidBST(struct TreeNode* root){
    return isABST(root,-2147483649,2147483648);
}