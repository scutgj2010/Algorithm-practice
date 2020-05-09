int findMaxConsecutiveOnes(int* nums, int numsSize){
    int maxNum;
    int curNum;
    int index;
    
    curNum = 0;
    maxNum = 0;
    for(index = 0; index < numsSize; index++) {
        if(nums[index] == 1) {
            curNum++;
        } else {
            maxNum = maxNum > curNum ? maxNum : curNum;
            curNum = 0;
        }
    }
    maxNum = maxNum > curNum ? maxNum : curNum;
    return maxNum;
}
