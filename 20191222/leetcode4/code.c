double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int midNum = (nums1Size+nums2Size)/2;
    int loopNum = 0;
    int i = 0;
    int j = 0;
    int num1 = 0;
    int num2 = 0;
    double num = 0;
    for(loopNum = 0;loopNum<=midNum;loopNum++)
    {
        num1 = num2;
        if((i < nums1Size) && (j < nums2Size))
        {
            if(nums1[i]>=nums2[j])
            {
                num2 = nums2[j];  
                j++;
            }
            else
            {
                num2 = nums1[i];
                i++;
            }
        }
        else if(i < nums1Size)
        {
            num2 = nums1[i];
            i++;
            
        }
        else if(j < nums2Size)
        {
            num2 = nums2[j];
            j++;
        }
    }
    
    if((nums1Size+nums2Size)%2)
    {
        num = (double) num2;              
    }
    else
    {
        num = ((double)num1 + (double)num2)/2;
    }
    return num;
}