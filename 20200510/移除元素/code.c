int removeElement(int* nums, int numsSize, int val){
    int quickIdx;
    int slowIdx;

    slowIdx = 0;
    for(quickIdx = 0; quickIdx < numsSize; quickIdx++) {
        if(nums[quickIdx] != val) {
            nums[slowIdx] = nums[quickIdx];
            slowIdx++;    
        }
    }
    return slowIdx;
}