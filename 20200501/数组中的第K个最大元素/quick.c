int QuickSort(int *nums,int low,int high,int k)
{
    int pivot=nums[low];
    int or_low=low,or_high=high;
    while(high>low)
    {
        while(high>low&&nums[high]<=pivot) {
            high--;
        }
        nums[low]=nums[high];

        while(high>low&&nums[low]>=pivot) {
            low++;
        }
        nums[high]=nums[low];
    }
    nums[high]=pivot;
    if(high==k-1) {
        return nums[high];
    } else if (high>k-1) {
        return QuickSort(nums,or_low,high-1,k);
    }
    return QuickSort(nums,high+1,or_high,k);
}
int findKthLargest(int* nums, int numsSize, int k){
    int result= QuickSort(nums,0,numsSize-1,k);
    return result;
}
