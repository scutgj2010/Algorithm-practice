/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* missingTwo(int* nums, int numsSize, int* returnSize){
    long int sum = 0;
    long int sum1 = 0;
    long int sum2 = 0;
    int uiMidNum;
    int uiLoopNum;

    *returnSize = 2;
    int * result = (int *)malloc(sizeof(int) * 2);

    for(uiLoopNum = 1; uiLoopNum <= numsSize; uiLoopNum++) {
        sum += nums[uiLoopNum-1];
        sum1 += uiLoopNum;
    }

    sum1 = sum1 + numsSize + numsSize + 3;
    sum2 = sum1 - sum;
 
    uiMidNum = sum2/2;
    sum = 0;
    sum1 = 0;
    for(uiLoopNum = 1; uiLoopNum <= numsSize; uiLoopNum++) {
        if(nums[uiLoopNum-1] <= uiMidNum) {
            sum += nums[uiLoopNum-1];
        } 
    }
    for(uiLoopNum = 1; uiLoopNum <= uiMidNum; uiLoopNum++) {
        sum1 += uiLoopNum;
    }    

    result[0] = sum1 -sum;
    result[1] = sum2 - result[0];

    return result;   
}