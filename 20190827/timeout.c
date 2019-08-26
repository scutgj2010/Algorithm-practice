#include<stdio.h>

void rotate(int* nums, int numsSize, int k){
    int i = 0;
    int j = 0;
    int temp = 0;
    if((k == 0) || (numsSize == 0))
    {
        return;
    }
    
    for(i = 0;i<k;i++)
    {
        temp = nums[numsSize-1];
        for(j = (numsSize-2);j>=0;j--)
        {
           nums[j+1] = nums[j]; 
        }
        nums[0] = temp;
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