#include<stdio.h>
#include<stdlib.h>



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int isValidSudoku(char** board, int boardSize, int boardColSize){
    int i, j, k; 
    int a = 0, b = 0, c = 0, d = 0;
    int row = 0, col = 0;
    int num;
    /* 判断每行数组中的值是否只出现一次 */
    for(k = 0; k < boardSize; k++)
    {
        for(i = 0; i < (boardColSize - 1); i++)
        {
            for(j = i + 1; j < (boardColSize); j++)
            {
                if(board[k][i] == '.')
                    break;
                else if(board[k][j] == '.')
                    continue;
                else if(board[k][i] == board[k][j])
                    return 1;
            }
        }
    }
    
    
    /* 判断每列数组中的值是否只出现一次 */
    for(k = 0; k < (boardColSize); k++)
    {
        for(i = 0; i < (boardSize - 1); i++)
        {
            for(j = i + 1; j < boardSize; j++)
            {
                if(board[i][k] == '.')
                    break;
                else if(board[j][k] == '.')
                    continue;
                else if(board[i][k] == board[j][k])
                    return 1;
            }
        }
    }
    
    /* 判断3x3矩阵中的值是否只出现一次 */
    for(num = 0; num < 9; num++)
    {
        for(a = row; a < 3 + row; a++)
        {
            for(b = col; b < 3 + col; b++)
            {
                /* 判断值为.，则判断下一个 */
                if(board[a][b] == '.')
                {
                    continue;
                }
                /* 判断3x3矩阵是否有相等的值 */
                for(c = 0 + row;c < 3 + row; c++)
                {
                    for(d = 0 + col; d < 3 + col; d++)
                    {
                        if(board[c][d] == '.')
                            continue;
                        else if((a != c) && (b != d) && (board[a][b] == board[c][d]))
                            return 1;
                    }
                }
            }
        }
        /* 移动至下一个3x3矩阵 */
        col += 3;
        if(col >= 9)
        {
            col = 0;
            row += 3;
        }
    }

    return 0;
}

int main()
{
	int i = 0;
	int flag = 0;
	char num1[9][9] = {{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},{".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}};
    flag = isValidSudoku(num1,9,9);
	return 0;
}