#include<stdio.h>
#include<stdlib.h>

int singleNumber(int* nums, int numsSize){
    int loopNum = 0;
    int temp = 0;
    if(1 == numsSize)
    {
        return nums[0];
    }
    
    for(loopNum = 0; loopNum<numsSize;loopNum++)
    {
        temp ^= nums[loopNum];
    }
    return temp;
}

int main()
{
	int flag = 0;
	int i = 0;
	int prices[7] = {1,2,3,4,5,6,2};
	flag = singleNumber(prices,7);
	printf("flag is %d\n",flag);
	return 0;
}