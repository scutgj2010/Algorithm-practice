int compare(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}
int arrayPairSum(int* nums, int numsSize){
    int loopNum;
    int sum = 0;

    qsort(nums,numsSize,sizeof(int),compare);
    for(loopNum = 0; loopNum<numsSize/2; loopNum++) {
        sum += nums[2*loopNum];
    }
    return sum;
}