#include<stdio.h>

int maxProfit(int* prices, int pricesSize){
    int i = 0;
	int num = 0;
    if(pricesSize == 0)
        return 0;
    
    for(i = 0;i<(pricesSize-1);i++)
    {
       if(prices[i]<prices[i+1])
           num += (prices[i+1] -prices[i]);
    }

    return num;
}

int main()
{
	int num = 0;
	int prices[5] = {7,5,7,2,5};
	num = maxProfit(prices,5);
	printf("num is %d\n",num);
	return 0;
}