int lengthOfLongestSubstring(char * s){

    int maxLen = 1;
    int len = strlen(s);
    int start = 0;
    int end = 0;
    int loop = 0;
    char temp = 0;

    if(0 == len)
    {
        return 0;
    } 

    for(end = start+1; end < len;end++)
    {
        temp = s[end];
        for(loop = start;loop < end;loop++)
        {
            if(s[loop] == temp)
            {
                start = loop+1;
                break;
            }
        }

        if((loop-start+1) > maxLen)
        {
           maxLen = loop - start + 1;
        }
    }
    return maxLen;
}