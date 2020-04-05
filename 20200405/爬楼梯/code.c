int climb(int * remark,int n)
{
    if(n == 1 || n == 2) {
        remark[n-1] = n;
        return  remark[n-1];
    }
    if(remark[n-1] == 0) {
        remark[n-1] = climb(remark,n-1)+ climb(remark,n-2);
    }
    return  remark[n-1];   
}

int climbStairs(int n){
    int * remark = (int *)malloc(sizeof(int) * n);
    memset(remark,0,sizeof(int)*n);
    return climb(remark,n);
}