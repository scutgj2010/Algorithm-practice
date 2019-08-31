bool isValidSudoku(char** board, int boardSize, int boardColSize){
    int a[9][10];
        int b[9][10];
        int c[9][10];
        
        for(int i=0;i<9;i++){
            for(int j=0;j<10;j++){
                a[i][j] = 0;
                b[i][j] = 0;
                c[i][j] = 0;
            }
        }
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    int num = board[i][j]-'0';
                    if(a[i][num] == 1) return false;
                    if(b[j][num] == 1) return false;
                    if(c[i/3*3+j/3][num] == 1) return false;

                    a[i][num] = 1;
                    b[j][num] = 1;
                    c[(i/3)*3+j/3][num] = 1;
                }
            }
        }
        return true;
    }
int main()
{
	int i = 0;
	int flag = 0;
	char num1[9][9] = {{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},{".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}};
    flag = isValidSudoku(num1,9,9);
	return 0;
}