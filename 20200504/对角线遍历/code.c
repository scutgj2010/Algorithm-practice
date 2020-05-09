/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    /*因为奇数行偶数行遍历的方向相反，所以用一个flag区分*/
    int * MidArray;
    int flag = 0; 
    int i,j;
    int k = 0;

    if(matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = matrixSize * (*matrixColSize);
    MidArray = (int *)malloc(sizeof(int) * matrixSize * (*matrixColSize));
    for(int i = 0; i < matrixSize + (*matrixColSize); i++) {
   
        if(flag%2 == 0) {      // 偶数行(0，2，4..)从左到右
            for(int j = 0; j <= i; j++) {
                if((i-j < matrixSize)&& j < *matrixColSize)   // 排除掉超出范围的点
                    MidArray[k++] = matrix[i - j][j];
            }
            flag = 1;
        }
        else {                 // 奇数行(1，3，5..)从右到左
            for(int j = i; j >= 0; j--) {
                if(j < *matrixColSize && (i-j < matrixSize))  // 排除掉超出范围的点
                    MidArray[k++] = matrix[i - j][j];
            }
            flag = 0;
        }   
    }
    return MidArray;
}