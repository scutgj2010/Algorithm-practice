

char * longestPalindrome(char * s){
    
    int outLoop = 0;
    int inLoop = 0;
    int length = strlen(s);
    int len = 0;
    int flag = 0;
    int end = 0;
    int max = 0;
    int start = 0;
    int hitFlag = 0;
    if(NULL == s)
    {
        return NULL;
    }
    
    if((1 == length)||(0 == length))
    {
        return s;
    }
  
    for(inLoop = 0;inLoop<length;inLoop++)
    {
        len = length-1;
        end = len;
        char ch = s[inLoop];
        flag = 0;
        hitFlag = 0;
        
        for(outLoop = inLoop;outLoop<= len;)
        {        
        
            if(outLoop >= len)
            {
               if((end-inLoop+1)>max)
               {
                   start = inLoop;
                   max = end-inLoop+1;
               }
               break;
            }
            
            if(s[outLoop] == s[len])
            {
                len--;
                hitFlag = 1;
                if(len != outLoop)
                {
                    outLoop++;
                }
            }
            else if(flag != 0)
            {
                outLoop = inLoop;
                len = flag;
                end = len;
                flag = 0;
                hitFlag = 0;
            }
            else
            {
                outLoop = inLoop;
                len--;
                hitFlag = 0;
                end = len;
            }
        
            if((ch == s[len])&&(flag == 0)&&(hitFlag ==1))
            {
                flag = len;
            }
        }
    }
    
    char * str = malloc(length*2);
    memset(str,0,length*2);
    memcpy(str,s+start,max);
    
    return str;
}

