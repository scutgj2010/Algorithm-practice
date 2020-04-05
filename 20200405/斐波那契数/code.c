int fib(int N){
    int remark[30] = {0};
    if( N < 2) {
        return N;
    }
    
    if(remark[N-1] == 0) {
        remark[N-1] = fib(N-1) + fib(N-2);
    }
    
    return remark[N-1];
}

