void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i = 0;
    int j = 0;
    /*先转置矩阵*/
    for (i = 0; i < matrixSize; i++) {
      for (j = i; j < matrixSize; j++) {
        int tmp = matrix[j][i];
        matrix[j][i] = matrix[i][j];
        matrix[i][j] = tmp;
      }
    }
    /*再反转每一行*/
    for (int i = 0; i < matrixSize; i++) {
      for (int j = 0; j < matrixSize / 2; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[i][matrixSize - j - 1];
        matrix[i][matrixSize - j - 1] = tmp;
      }
    }
  }