#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int i = 0;
	int number = 0;
    if(numsSize <= 0)
    {
        return 0;
    }

    for (i = 0; i < numsSize; i++) {
        if (nums[i] != nums[number]) {
            number++;
            nums[number] = nums[i];
        }
    }    
    return number + 1;
}

int main()
{
	int loopNum = 0;
	int numbers = 0;
	int nums[11] = {1,1,2,3,4,6,7,8,9,9,10};
	numbers = removeDuplicates(nums,11);
	for(loopNum = 0;loopNum<numbers;loopNum++)
	{
		printf("nums[%d] is %d,",loopNum,nums[loopNum]);
	}
	return 0;
}