#include<stdio.h>
#include<stdlib.h>



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int firstUniqChar(char * s){
    int num = 0;
    int j,k;
    int *p;
    while(s[num] != '\0')
    {
        num++;
    }
    
    p = (int*)malloc(num*4);
    memset(p,0,num*4);
    
    for(j = 0;j<num;j++)
    {
        if(1 == p[j])
        {
            continue;
        }
        
        for(k = j+1;k<num;k++)
        {
            if(s[j] == s[k])
            {
                p[j] = 1;
                p[k] = 1;
            }
        }
        /*if(k == num)
        {
            return j;
        }*/
    }
    
    for(j = 0;j<num;j++)
    {
        if(p[j] == 0)
        {
            free(p);
            return j;
        }
    }
    free(p);
    return -1;
}

int main()
{
	char *s = "aadadaad";
	int flag = 0;
	//char num1[9][9] = {{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},{".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}};
    flag = firstUniqChar(s);
	printf("flag is %d\n",flag);
	return 0;
}