#include<stdio.h>
#include<stdlib.h>

#define true 0
#define false 1

int containsDuplicate(int* nums, int numsSize){
    int i,j=0;
    for(i=0;i<(numsSize-1);i++)
    {
        for(j = (i+1);j<numsSize;j++)
        {
            if(nums[i] == nums[j])
                return true;
        }
    }
    return false;
}




int main()
{
	int flag = 0;
	int prices[7] = {1,2,3,4,5,6,1};
	flag = containsDuplicate(prices,7);
	printf("flag is %d\n",flag);
	return 0;
}