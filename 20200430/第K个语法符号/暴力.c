int kthGrammar(int N, int K){
    int * lastrow = malloc(sizeof(int)*(1 << N));
    memset(lastrow,0,sizeof(int)*(1 << N));

    for (int i = 1; i < N; ++i) {
        for (int j = (1 << (i-1)) - 1; j >= 0; --j) {
             lastrow[2*j] = lastrow[j];
             lastrow[2*j+1] = 1 - lastrow[j];
        }
    }
    return lastrow[K-1];
}