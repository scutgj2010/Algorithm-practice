#include<stdio.h>
#include<stdlib.h>



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_NUM  214748364
#define MIN_NUM -214748364

int reverse(int x){
    int y = 0;
    int i = 0;
    int shan = 0;
    int yushu = 0;
    do{
        yushu = x%10;
        x = x/10;
        if((y>MAX_NUM)||((y==MAX_NUM)&&(yushu>7)))
        {
            return 0;
        }
        if((y<MIN_NUM)||((y==MIN_NUM)&&(yushu<-8)))
        {
            return 0;
        }
        y = y*10+yushu;
        i++;
    }while(x);
    return y;
}
int main()
{
	int i = 123;
	int flag = 0;
	//char num1[9][9] = {{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},{".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}};
    flag = reverse(i);
	printf("flag is %d\n",flag);
	return 0;
}