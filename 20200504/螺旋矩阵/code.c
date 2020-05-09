/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int * result;
    int rowStart;
    int rowEnd;
    int colStart;
    int colEnd;
    int counter;
    int loopNum;
    if(matrixSize == 0 || *matrixColSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = matrixSize * (*matrixColSize);
    result = (int *)malloc(*returnSize * sizeof(int));
    rowStart = 0;
    rowEnd = matrixSize-1;
    colStart = 0;
    colEnd = *matrixColSize - 1;
    counter = 0;
    while((rowStart <= rowEnd) && (colStart <= colEnd)) {
        for(loopNum = colStart; loopNum<= colEnd; loopNum++) {
            result[counter++] = matrix[rowStart][loopNum];
 
        }
        rowStart++;
        for(loopNum = rowStart; loopNum <= rowEnd; loopNum++) {
            result[counter++] = matrix[loopNum][colEnd];
        }
        if(counter == *returnSize) {
            break;
        }
        colEnd--;
        for(loopNum = colEnd; loopNum >= colStart; loopNum--) {
            result[counter++] = matrix[rowEnd][loopNum];
        }
        rowEnd--;
        for(loopNum = rowEnd; loopNum >= rowStart; loopNum--) {
            result[counter++] = matrix[loopNum][colStart];
        }
        colStart++;      
    }
    return result;
}