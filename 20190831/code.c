#include<stdio.h>
#include<stdlib.h>



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i = 0;
    int j = 0;
    int num[numsSize];
    int flag[numsSize];
    int * value;
    
    *returnSize = 0;
    
    if(numsSize == 1)
    {
        return NULL;
    }
    
    memset(flag,0,numsSize*4);
    
    for(i = 0;i<(numsSize);i++)
    {
        for(j = (i+1);j<(numsSize);j++)
        {
            if(flag[i]==1)
            {
                break;
            }
            if((target == (nums[i]+nums[j]))&&(flag[j]==0)&&(flag[i]==0))
            {
                num[*returnSize] = i;
                num[*returnSize+1] = j;
                flag[i] = 1;
                flag[j] = 1;
                *returnSize += 2;
                break;
            }
        }
    } 
    value = (int *)malloc((*returnSize)*4);
    memcpy(value,num,(*returnSize)*4);
    return value;
}


int main()
{
	int i = 0;
	int number = 0;
	int num1[4] = {3,2,4};
	int * value;
    value = twoSum(num1,3,6,&number);
	printf("num is %d\n",number);
	for(;i<number;i++)
	{
		printf("%d,\n",value[i]);
	}
	return 0;
}