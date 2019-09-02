int firstUniqChar(char * s){
        //极端情况，空串，单字母？
        if(!s)
                return -1;

        short count[26] = {0};
        char *end = s + strlen(s);
        for (char *p = s; p < end;++p)
                ++count[*p - 'a'];

        //遍历字符串，输出首个仅1次的字母的下标
        for (char *p = s ; p<end ; ++p)
        {
                if(count[*p-'a']==1)
                        return p - s;
        }
        return -1;//若都重复，返回-1
}