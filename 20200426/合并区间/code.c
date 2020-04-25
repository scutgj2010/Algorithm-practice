/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static int comp(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){

    int ** result = (int **)malloc(sizeof(int *) * intervalsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * intervalsSize);
    if(intervalsSize == 0 ) {
        *returnSize = 0;
        return returnSize;
    }

    int *pStart = (int *)malloc(sizeof(int) * intervalsSize);
    int *pEnd = (int *)malloc(sizeof(int) * intervalsSize);
    int loopNum = 0;
    int counter = 0;
    
    for(loopNum = 0; loopNum<intervalsSize;loopNum++) {
        result[loopNum] = (int *)malloc(sizeof(int) * *intervalsColSize);
        pStart[loopNum] = intervals[loopNum][0];
        pEnd[loopNum] = intervals[loopNum][1];
    }

    qsort(pStart,intervalsSize,sizeof(int),comp);
    qsort(pEnd,intervalsSize,sizeof(int),comp);

    for(loopNum = 0;loopNum<intervalsSize;loopNum++) {
        result[counter][0] = pStart[loopNum];
        for(;loopNum<intervalsSize-1;loopNum++) {
            if(pStart[loopNum+1] > pEnd[loopNum]) {
                break;
            }
        }
        result[counter][1] = pEnd[loopNum];
        (*returnColumnSizes)[counter] = 2;
        counter++;
    }
    *returnSize = counter;
    return result;
}