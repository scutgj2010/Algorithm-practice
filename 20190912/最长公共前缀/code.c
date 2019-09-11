char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0)//输入可能为空，如果答案消耗时间很短的话，很有可能输入的是空字符
    {
        return "";
    }       
    char *str = (char*)calloc(128, sizeof(char));//分配128个字节的内存，来存储公共前缀
    for (int i = 0,j; i < strlen(*strs); i++)//外循环，以第一个字符串的长度为循环次数，因为最长公共前缀的长度小于等于它
    {
        for (j = 0; j < strsSize - 1; j++)
        {
            if(strs[j][i] != strs[j+1][i])
            {               
                return str;
            }                      
        }
        str[i] = strs[j][i];  
    }        
    return str;
}