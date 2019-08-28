#include<stdio.h>
#include<stdlib.h>



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i = 0;
    int ccr = 1;
    int * num = NULL;
    for(i = digitsSize-1;i>=0;i--)
    {
        digits[i] += ccr;
        if(10 == digits[i])
        {
            digits[i] = 0;
            ccr = 1;
        }
        else
        {
            break;
        }
    }
    if(digits[0] == 0)
    {
        * returnSize = digitsSize+1;
        num = (int *)malloc((*returnSize)*4);
        num[0] = 1;
        memcpy(num+1,digits,digitsSize*4);
    }
    else
    {
       * returnSize = digitsSize;
       num = (int *)malloc((*returnSize)*4);
       memcpy(num,digits,digitsSize*4);
    }
    return num;
}
int main()
{
	int i = 0;
	int num = 0;
	int *value;
	int num1[3] = {4,9,5};
	value = plusOne(num1,3,&num);
	printf("num is %d,",num);
	for(;i<num;i++)
	{
		printf("%d,\n",value[i]);
	}
	return 0;
}