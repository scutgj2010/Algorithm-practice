int strStr(char * haystack, char * needle){
   
    int i =0,j=0,l = 0; 
    if(0 == strlen(needle))
    {
        return 0;
    }
    
    for(i = 0,j = 0; (i<strlen(haystack))&&(j<strlen(needle));)
    {
        if(needle[j] == haystack[i])
        {
            i++;
            j++;
        }
        else
        {
            l++;
            j = 0;
            i = l;
        }
    }
    
    if(j != strlen(needle))
    {
        return -1;
    }
    else
    {
        return l;
    }
    
}
