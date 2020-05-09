/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* beautifulArray(int N, int* returnSize){
    int uiLoopNum;
    int uiOddNum;
    int uiEvenNum;
    int *pstRst = (int *)malloc(sizeof(int) * N);
    int stRst[N+1][N];
    *returnSize = N;
    if(N == 0) {
        return NULL;
    }
    stRst[1][0] = 1;
    if(N > 1) {
        stRst[2][0] = 1;
        stRst[2][1] = 2;
    }

    for(uiLoopNum = 3; uiLoopNum <= N; uiLoopNum++) {
        for(uiOddNum = 0; uiOddNum < (uiLoopNum + 1)/2; uiOddNum++) {
            stRst[uiLoopNum][uiOddNum] = stRst[(uiLoopNum + 1)/2][uiOddNum]*2-1;
        }
        for(uiEvenNum = 0; uiEvenNum < uiLoopNum/2; uiEvenNum++) {
            stRst[uiLoopNum][uiOddNum + uiEvenNum] = stRst[uiLoopNum/2][uiEvenNum]*2;
        }
    }
    memcpy(pstRst, stRst[N], N * sizeof(int));
    return pstRst;
}