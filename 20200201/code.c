int lengthOfLongestSubstring(char * s){

    int maxLen = 1;
    int len = strlen(s);
    int start = 0;
    int end = 0;
    int loop = 0;
    char * str = (char*)malloc(sizeof(char)*(len+1));
    memset(str,0,(len+1));

    if(0 == len)
    {
        return 0;
    } 

    for(end = start+1; end < len;end++)
    {
        for(loop = start;loop < end;loop++)
        {
            if(s[loop] == s[end])
            {
                str[loop-start] = s[loop];
                start = loop+1;
                end = start;
                break;
            }
            else
            {
                str[loop-start] = s[loop];
            }
        }

        if((loop-start+1) > maxLen)
        {
           maxLen = loop - start + 1;
        }
    }
    return maxLen;
}