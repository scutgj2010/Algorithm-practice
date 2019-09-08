#include<stdio.h>
#include<stdlib.h>
#include<string.h>



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define INT_MIN -2147483648
#define INT_MAX  2147483647




int myAtoi(char * str){
    int length = strlen(str);
    int i = 0;
    char flag = 0;
    char fuhao = 0;
    int num = 0;
    int value = 0;
    for(;i<length;i++)
    {
        if(flag == 0)
        {
            if(str[i] == ' ')
            {
                continue;
            }
            if(str[i] !='-' &&str[i] !='+'&& ((str[i]<'0')||(str[i]>'9')))
            {
                return 0;
            }
            else if(str[i] == '-')
            {
                fuhao = 1;
            }
            else if(str[i] == '+')
            {

            }
            else
            {
                num = str[i] - '0';
                value = num;
            }
            flag = 1;
			continue;
        }
        if(flag == 1)
        {
            if((str[i]<'0')||(str[i]>'9'))
            {
                break;
            }
            else
            {
                num = str[i] - '0';
                
                if((fuhao == 0) &&((value > 214748364)||((value == 214748364)&&(num>=7))))
                {                           
                     return INT_MAX;
                }
                   
                if((fuhao == 1) &&(value > 214748364)||((value == 214748364)&&(num >= 8)))
                {                          
                     return INT_MIN;
                }
                        
                value = 10*value+num;                    
            }
        }        
    }
    if(flag == 0)
    {
        return 0;
    }
    num = (fuhao == 1)?-value:value;
    return num;
}





int main()
{
	char *s = "   +0 123";
	//char *t = "nagaram";
	int num = 0;
	//char flag = 0;
	//char num1[9][9] = {{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},{".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}};
    num = myAtoi(s);
	printf("num is %d\n",num);
	return 0;
}