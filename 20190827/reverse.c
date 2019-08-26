#include<stdio.h>

void rotate(int* nums, int numsSize, int k){
    int i = 0;
    int temp = 0;
    if((k == 0) || (numsSize == 0))
    {
        return;
    }
    
    k %= numsSize;
    /*翻转整个数组*/
    for(i = 0 ;i<(numsSize/2);i++)
    {
        temp = nums[i];
        nums[i] = nums[numsSize-1-i];
        nums[numsSize-1-i] = temp;
    }
    
    /*翻转前K个数字*/
    for(i = 0; i<(k/2);i++)
    {
        temp = nums[i];
        nums[i] = nums[k-1-i];
        nums[k-1-i] = temp;
    }
        
    /*翻转后numsSize-K个*/
    for(i = k; i<((numsSize+k)/2);i++)
    {
        temp = nums[i];
        nums[i] = nums[numsSize-1-i+k];
        nums[numsSize-1-i+k] = temp;
    }  
    
    return ;
}




int main()
{
	int num = 0;
	int prices[7] = {1,2,3,4,5,6,7};
	rotate(prices,7,3);
	for(num = 0;num<7;num++)
	printf(",%d",prices[num]);
	return 0;
}