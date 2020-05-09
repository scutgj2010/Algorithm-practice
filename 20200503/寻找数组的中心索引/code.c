int pivotIndex(int* nums, int numsSize){
    int sum = 0;
    int leftSum = 0;
    int loopNum;
    int midIdx;

    for(loopNum = 0; loopNum < numsSize; loopNum++) {
        sum += nums[loopNum];
    }

    for(midIdx = 0; midIdx < numsSize; midIdx++) {
        if((sum - nums[midIdx]) % 2) {
            continue;
        }
        
        leftSum = 0;
        for(loopNum = 0; loopNum < midIdx; loopNum++) {
            leftSum += nums[loopNum];
        }
        if(leftSum == (sum - nums[midIdx]) / 2) {
            return midIdx;
        }
    } 
    return -1;   
}

