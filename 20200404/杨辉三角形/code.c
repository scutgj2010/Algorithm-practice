
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compute(int ** result,int row,int column)
{
    if(row == 0 || column == 0) {
        result[row][column] = 1;
        return result[row][column];
    }
    if(row == column) {
        result[row][column] = 1;
        return result[row][column];
    }
    if(result[row][column] != 0) {
        return result[row][column];
    }
    result[row][column] = compute(result,row-1,column-1) + compute(result,row-1,column);
    return result[row][column];
}
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int ** result = (int **)malloc(numRows * sizeof(int *));
    (*returnColumnSizes)=(int*)malloc(sizeof(int)*numRows);
    
    int loopNum ;
    
    for(loopNum = 1; loopNum<=numRows;loopNum++) {
        result[loopNum-1] = (int*)malloc(loopNum * sizeof(int));
        memset(result[loopNum-1] , 0 , loopNum * sizeof(int));
        result[loopNum-1][0] = 1;
        result[loopNum-1][loopNum-1] = 1;
        (*returnColumnSizes)[loopNum-1] = loopNum;
    }
    
    for(loopNum = 1;loopNum<numRows-1;loopNum++) {
       result[numRows-1][loopNum] = compute(result,numRows-2,loopNum) + compute(result,numRows-2,loopNum-1);
    }
    *returnSize = numRows;
    return result;
}