#include<stdio.h>
#include<stdlib.h>

#define true 0
#define false 1

int partition(int *arr,int left,int right)
{
    int j = left, i;
    int selectedValue = arr[right];
    int temp;
    // 用j指定预期的中心点位置
    // 用游标i从左向右遍历，如果小于选定值，则扔到j指定位置的左侧，否则继续向右
    for (i = left; i < right; i++) {
        if (arr[i] < selectedValue) {
            // 交换i与j位置的值，并更新j指向的位置
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
    arr[right] = arr[j];
    arr[j] = selectedValue;
    return j;
}

void quicksort(int * arr,int left,int right)
{
    int basenum = 0;
    if(left < right)
    { 
        basenum = partition(arr, left, right); 
        quicksort(arr,left,basenum-1);
        quicksort(arr,basenum+1,right);
    }
}

int containsDuplicate(int* nums, int numsSize){
    int loopNum = 0;
    quicksort(nums,0,numsSize-1);
    for(loopNum = 0;loopNum<(numsSize-1);loopNum++)
    {
        if(nums[loopNum] == nums[loopNum+1])
            return true;
    }
    return false;
}

int main()
{
	int flag = 0;
	int i = 0;
	int prices[7] = {1,2,3,4,5,6,2};
	flag = containsDuplicate(prices,7);
	for(;i<7;i++)
	{
		printf("%d,\n",prices[i]);
	}
	printf("flag is %d\n",flag);
	return 0;
}