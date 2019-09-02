
void reverseString(char* s, int sSize){
    int i = 0;
    char temp = 0;
    for(i = 0; i<(sSize>>1);i++)
    {
        temp = s[i];
        s[i] = s[sSize-i-1];
        s[sSize-i-1] = temp;
    }
}
