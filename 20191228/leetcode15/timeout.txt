/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void *a,const void *b)
{
    return (*(int*)a - *(int*)b);
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    int i,j,k,l; 
    int mallocSize = 1000;
    *returnSize = 0;
    
    /*排序是为了方便去重*/
    qsort(nums,numsSize,sizeof(int),compare);
    
    int ** returnArray = (int **)malloc(mallocSize*sizeof(int*));
    returnArray[*returnSize] = (int *)malloc(sizeof(int)*3);    
    *returnColumnSizes = (int *)malloc(mallocSize*sizeof(int));
    for(i = 0; i < numsSize;i++) {
        for(j = i+1;j<numsSize;j++) {
            for(k = j+1;k<numsSize;) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    //if(*returnSize >= (mallocSize-1000)) {
                    //    mallocSize = mallocSize<<1;
                    //    realloc(returnColumnSizes,mallocSize*12);
                    //}
                    for(l = 0;l<(*returnSize);l++) {
                        
                        if(((returnArray[l][0]) == nums[i]) && ((returnArray[l][1]) == nums[j])
                            && ((returnArray[l][2]) == nums[k])) {
                            goto CONTINUE;
                        }
                    }
                    returnArray[*returnSize][0] = nums[i];
                    returnArray[*returnSize][1] = nums[j];
                    returnArray[*returnSize][2] = nums[k];
                    (*returnColumnSizes)[*returnSize] = 3;
                    (*returnSize)++;
                    returnArray[*returnSize] = (int *)malloc(sizeof(int)*3); 
                }
                CONTINUE:
                k++;
            }
        }
    }
    return returnArray;
}
