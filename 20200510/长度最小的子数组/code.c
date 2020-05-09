int minSubArrayLen(int s, int* nums, int numsSize){
    int startIdx;
    int endIdx;
    int sum;
    int minNum;
    int curNum;

    for(startIdx = 0, endIdx = 0, sum = 0, minNum = 0x7FFFFFFF; endIdx < numsSize; endIdx++) {
        sum += nums[endIdx];
        while(sum >= s) {
            curNum = endIdx - startIdx + 1; 
            minNum = minNum <= curNum ? minNum : curNum;
            sum -= nums[startIdx];
            startIdx++;   
        }
    }
    minNum = minNum == 0x7FFFFFFF ? 0 : minNum;
    return minNum;
}  