int partition(int *nums ,int left,int right)
{
    int temp = 0;
    int selectedValue = 0;
    int loopNum = 0;
    int baseNum = left;
    selectedValue = nums[right];
    for(loopNum = left;loopNum<right;loopNum++)
    {
        if(nums[loopNum]<selectedValue)
        {
             temp = nums[loopNum];
             nums[loopNum] = nums[baseNum];
             nums[baseNum] = temp;
             baseNum++;
        }
    }
    nums[right] = nums[baseNum];
    nums[baseNum] = selectedValue;
    return baseNum;
}
void quicksort(int * nums,int left,int right)
{
	 if(left<right)
	 {
         int baseNum = partition(nums,left,right);
         quicksort(nums,left,baseNum-1);
         quicksort(nums,baseNum+1,right);
	 }
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){

    if(nums1Size==0||nums2Size==0)
    {
        *returnSize=0;
        return NULL;
    }
    
    quicksort(nums1,0,nums1Size-1);
    quicksort(nums2,0,nums2Size-1);
    
    int len=nums1Size<nums2Size?nums1Size:nums2Size;
    int arr[len];           //变量可能为零//
    int i,j,k=0;
    /*
    for（；表达式1，表达式2；）   则以条件2为主。
    for（；表达式1&表达式2；）    则以先达到条件的表达式为主。
    for（；表达式1|表达式2；）     则以后达到条件的表达式为主。
    */
    
    for(i=0,j=0;i<nums1Size&j<nums2Size&k<len;)//学到了新的东西记在了笔记里
    {
        if(nums1[i]<nums2[j])
            i++;
        else if(nums1[i]>nums2[j])
            j++;
        else if(nums1[i]==nums2[j])
        {
            arr[k++]=nums1[i];
            i++;
            j++;
        }    
    }
    *returnSize=k;
    int *returnarr=(int*)malloc(sizeof(int)*k);
    if(returnarr==NULL)
        exit(0);
    for(i=0;i<k;i++)
    {
        *(returnarr+i)=arr[i];  
    }
    return returnarr;

}