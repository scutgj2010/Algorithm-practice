#include<stdio.h>
#include<stdlib.h>
#include<string.h>



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char isPalindrome(char * s){
    int length = strlen(s);
    int i = 0,j=length-1;
    int distance = 'a' -'A';
    if(0 == length)
    {
        return 0;
    }
    
    for(;(i < j);)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') )
        {
            if((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9') )
            {
                if(((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) && (s[j] >= '0' && s[j] <= '9'))
				{
					return 1;
				}

				if(((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z')) && (s[i] >= '0' && s[i] <= '9'))
				{
					return 1;
				}

				if((s[i] != s[j])&&(s[i] != (s[j]+distance))&&((s[i] + distance)!= s[j]))
                {
                    return 1; 
                }
                i++;
                j--;
            }
			else
			{
               j--;
               continue;
			}
        }
		else 
		{
            i++;
		}
    }
    return 0;
}

int main()
{
	char *s = "A man, a plan, a canal: Panama";
	//char *t = "nagaram";
	char flag = 0;
	//char num1[9][9] = {{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},{".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}};
    flag = isPalindrome(s);
	printf("flag is %d\n",flag);
	return 0;
}