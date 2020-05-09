char * addBinary(char * a, char * b){
    int aStart;
    int bStart;
    int counter;
    int rstLen;
    int ccr;
    char * rst;

    if(strlen(a) == 0) {
        return b;
    } else if(strlen(b) == 0) {
        return a;
    }
    
    if(a[0] == '0' && b[0] == '0') {
        return "0";
    }
    counter = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
    rst = (char *)malloc((counter+2)*sizeof(char));
    memset(rst,0,counter+2);
    aStart = strlen(a)-1;
    bStart = strlen(b)-1;
    rstLen = counter;
    ccr = 0;
    
    while(aStart >=0 && bStart >= 0) {
        if(((a[aStart] + b[bStart] + ccr - '0' - '0') & 1) == 0) {
            rst[counter] = '0';
        } else {
            rst[counter] = '1';            
        }
        ccr = (a[aStart] + b[bStart] + ccr - '0' - '0') >>1;
        counter--;
        aStart--;
        bStart--;
    }
    while(aStart >=0) {
        if(((a[aStart] + ccr - '0') & 1) == 0) {
            rst[counter] = '0';
        } else {
            rst[counter] = '1';            
        }
        ccr = (a[aStart] + ccr - '0') >>1;
        counter--;
        aStart--;
    }
    while(bStart >=0) {
        if(((b[bStart] + ccr - '0') & 1) == 0) {
            rst[counter] = '0';
        } else {
            rst[counter] = '1';            
        }
        ccr = (b[bStart] + ccr - '0') >>1;
        counter--;
        bStart--;
    }
    if(ccr) {
        rst[0] = '1';
    } else {
        memmove(rst,rst+1,rstLen);
        rst[rstLen] = 0;
    }
    return rst;
} 