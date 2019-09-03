#include<stdio.h>
#include<stdlib.h>
#include<string.h>



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool isAnagram(char * s, char * t){
    int slen = strlen(s);
    int tlen = strlen(t);
    char str[26] = {0};
    char str1[26] = {0};
    int num = 0;
    int loop = 0;
    
    for(loop = 0; loop<slen;loop++)
    {
         num = s[loop] - 'a';
         str[num]++;
    }
    for(loop = 0; loop<tlen;loop++)
    {
         num = t[loop] - 'a';
         str1[num]++;
    } 
    if(0 == memcmp(str,str1,sizeof(str)))
    {
        return true;
    }
    return false;
}

int main()
{
	char *s = "anagram";
	char *t = "nagaram";
	char flag = 0;
	//char num1[9][9] = {{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},{".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}};
    flag = isAnagram(s,t);
	printf("flag is %d\n",flag);
	return 0;
}