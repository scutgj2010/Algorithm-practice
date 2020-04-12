void reverse(char *s, int start,int end){
    char c;
    while(start<end) {
        c = s[start];
        s[start] = s[end];
        s[end] = c;
        start++;
        end--;
    }
}
char * reverseWords(char * s){
    int length = strlen(s);
    int start = 0;
    int end = length-1;
    int loopNum;
    
    if(length == 0) {
        return s;
    }

    reverse(s,0,length-1);
   
    while(s[start] == ' ') {
        start++;
    }
    while(s[end] == ' ') {
        if(end == 0) {
            return "";
        }
        end--;
    }

    if (end != length){
        length = end-start;
        s[end+1] = '\0';
    }

    s = s + start;
    start = 0;
    end = 0;
    for(; end<length;end++){
        if(s[end] == ' ') {
            if(s[end-1] == ' '){
                memmove(s+end,s+end+1,length-end+1);
                s[length] = '\0';
                length -= 1;
                end -= 1; 
                continue;
            }
            reverse(s,start,end-1);
            start = end+1;
        }
    }
    printf("%s,end is 0x%x\n",s,end);
    reverse(s,start,end);
    return s;
}