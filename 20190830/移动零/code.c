#include<stdio.h>
#include<stdlib.h>



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void moveZeroes(int* nums, int numsSize){

    int i = 0;
    int m = 0;
    int j = numsSize-1;
    int temp = 0;

    if(1 == numsSize)
	{
        return;
	}
    for(i = 0;(i<numsSize)&&(i<j);i++)
    {
       if(nums[i] == 0)
       {
           temp = nums[i];
           for(m=0;m<(j-i);m++)
           {
               nums[m+i] = nums[m+1+i];              
           }
           nums[j] = temp;
           j--;
           i--;
       }
    }
    return;
}

int main()
{
	int i = 0;
	int num1[5] = {0,1,0,3,12};
    moveZeroes(num1,5);
	for(;i<5;i++)
	{
		printf("%d,\n",num1[i]);
	}
	return 0;
}