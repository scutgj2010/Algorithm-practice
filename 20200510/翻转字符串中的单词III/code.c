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
   int startIdx;
   int endIdx;

   for(startIdx = 0, endIdx = 0; endIdx < strlen(s); endIdx++) {
       if(s[endIdx] != ' ' && s[startIdx] == ' ') {
           startIdx = endIdx;
       } else if(s[startIdx] != ' ' && s[endIdx] == ' ') {
           reverse(s,startIdx,endIdx-1);
           startIdx = endIdx;
       }
   }
   reverse(s,startIdx,endIdx-1);
   return s;
}