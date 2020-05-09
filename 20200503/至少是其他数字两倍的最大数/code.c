int dominantIndex(int* nums, int numsSize){
    int loopNum;
    int index;

    for(index = 0; index < numsSize; index++) {
        for(loopNum = 0; loopNum < numsSize; loopNum++) {
            if(loopNum == index) {
                continue;
            }
            if(nums[index] < nums[loopNum]*2){
                break;
            }          
        }
        if(loopNum == numsSize) {
            return index;
        }
    }
    return -1;
}