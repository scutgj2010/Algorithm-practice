void revers(char *s,int left,int right)
{
    char temp;
    if(left>=right) {
        return;
    }
    revers(s,left+1,right-1);
    temp = s[left];
    s[left] = s[right];
    s[right] = temp;
}

void reverseString(char* s, int sSize){
    if(sSize < 2) {
        return s;
    }
    revers(s,0,sSize-1);
}