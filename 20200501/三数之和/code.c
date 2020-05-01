/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void * a, const void * b)
{
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int ** result; 
    int uiCur;
    int uiLow;
    int uiHig;

    *returnSize = 0;
    if (numsSize < 3) {
        return NULL;
    }
    
    result = (int **)malloc(sizeof(int) * numsSize * numsSize );
    *returnColumnSizes = (int *)malloc(sizeof(int) * numsSize * numsSize);

    qsort(nums,numsSize,sizeof(int),compare);

    for(uiCur = 0; uiCur < numsSize-2;) {
        if(nums[uiCur] > 0) {
            break;
        }

        uiLow = uiCur + 1;
        uiHig = numsSize - 1;

        while(uiLow < uiHig) {
            if(nums[uiCur] + nums[uiLow] + nums[uiHig] == 0) {
                //printf("%d,%d,%d,%d\n",uiCur,nums[uiCur],nums[uiLow],nums[uiHig]);
                result[*returnSize] = (int *)malloc(sizeof(int) * 3);
                (*returnColumnSizes)[*returnSize] = 3; 
                result[*returnSize][0] = nums[uiCur];
                result[*returnSize][1] = nums[uiLow];
                result[*returnSize][2] = nums[uiHig];
                (*returnSize)++;

                while((nums[uiLow] == nums[++uiLow]) && (uiLow < uiHig)); 
                while((nums[uiHig] == nums[--uiHig]) && (uiLow < uiHig));
            } else if(0 < (nums[uiLow] + nums[uiHig] + nums[uiCur])) {
                uiHig--;
            } else {
                uiLow++;
            }  
        }
        while( (nums[uiCur] == nums[++uiCur]) && (uiCur + 1 < numsSize - 1) ); 
    }
    return result;
}