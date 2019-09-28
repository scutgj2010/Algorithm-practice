struct TreeNode * sortArray(int* nums,int left, int right)
{
    if (left > right) return NULL;
    int mid = (left + right) / 2;
    struct TreeNode *cur = malloc(sizeof(struct TreeNode));
    cur->val = nums[mid];
    cur->left = sortArray(nums, left, mid - 1);
    cur->right = sortArray(nums, mid + 1, right);
    return cur;   
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return sortArray(nums,0,numsSize-1);
}