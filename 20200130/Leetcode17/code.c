/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    int len = strlen(digits);
    int loop = 0;
    int counter = 0;
    int divide = 0;
    char ch[8][4] = {{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    int number[8] = {3,3,3,3,3,4,3,4};
    int sum = 1;
    int * num = (int *)malloc(sizeof(int)*len);
    char ** str = NULL;
    int sumNum = 0;
    

    for(loop = 0;loop<len;loop++)
    {
        num[loop] = *(digits+loop) - '2';
        sum = sum*number[num[loop]];
    } 

    str = (char**)malloc(sizeof(char*)*sum);
    memset(str,0,sizeof(char*)*sum);
    if(0 == len)
    {
        *returnSize = 0;
        return str;
    }

    for(loop = 0;loop<sum;loop++)
    {
        str[loop] = (char*)malloc(sizeof(char)*(len+1));
        memset(str[loop],0,sizeof(char)*(len+1));

        divide = sumNum;
        for(counter = len-1;counter>=0;counter--)
        {
            str[loop][counter] = ch[num[counter]][divide%(number[num[counter]])];
            divide = divide/number[num[counter]];
        }
        sumNum = sumNum + 1;
    }
    *returnSize = sum;
    return str;    
}