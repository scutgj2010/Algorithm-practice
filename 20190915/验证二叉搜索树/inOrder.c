bool inOrderTraverse(struct TreeNode* root, int **prev)
{
    int ret = true;
    //遍历左子树
    if (root->left)
        if (inOrderTraverse(root->left, prev) == false)
            return false;
    //中间节点
    if (*prev)
        if (root->val <= *(*prev))
            return false;
    //更新前继节点
    *prev = &root->val;
    
    //遍历右子树
    if (root->right)
        if (inOrderTraverse(root->right, prev) == false)
            return false;
    return ret;
}
 
bool isValidBST(struct TreeNode* root){
    int ret = true, *prev = NULL;
    //特殊情况处理
    if (!root)  
    {
        return true;
    }
    //中序遍历
    return inOrderTraverse(root, &prev);
}
