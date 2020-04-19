/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int  circle(int * num ,int ** matrix,int rowStart,int matrixSize,int colStart,int matrixColSize,int start)
{
    int loopNum = 0;
    int  counter = start;
    //printf("%x,%x,%x,%x,%x\n",counter,rowStart,matrixSize,colStart,matrixColSize);
    if (colStart >= matrixColSize || rowStart >= matrixSize)
    {
        return  counter;
    }
    for(loopNum = colStart; loopNum<matrixColSize;loopNum++) {
       num[counter] = matrix[rowStart][loopNum];
       counter++;
    }
    if(rowStart + 1 == matrixSize) {
        return counter;
    }
    for(loopNum = rowStart+1; loopNum<matrixSize;loopNum++) {
        num[counter] = matrix[loopNum][matrixColSize-1];
        counter++;
    }
    if(matrixColSize < 2){
        return counter;
    }
    if(colStart + 1 == matrixColSize) {
        return counter;
    }
    for(loopNum = matrixColSize-2; loopNum>=colStart;loopNum--) {
        num[counter] = matrix[matrixSize-1][loopNum];
        counter++;
    }
    if(matrixSize < 2) {
        return counter;
    }
    for(loopNum = matrixSize-2; loopNum>rowStart;loopNum--) {
        num[counter] = matrix[loopNum][colStart];
        counter++;
    }
    counter = circle(num,matrix,rowStart+1,matrixSize-1,colStart+1,matrixColSize-1,counter);
    return counter;
}
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize == 0 || matrixColSize == NULL || *matrixColSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int * num = (int*)malloc(sizeof(int)*matrixSize * (*matrixColSize));
    memset(num,0,sizeof(int) * matrixSize * (*matrixColSize));
    *returnSize = circle(num,matrix,0,matrixSize,0,*matrixColSize,0);
    return num;
}