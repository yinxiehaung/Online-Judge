#include <stdio.h>

int main(){
    int _row, _col, time, val;
    scanf("%d %d %d", &_row, &_col, &time);
    int num[_row][_col];
    for( int i = 0; i < _row; i++ ){
        for( int j = 0; j < _col; j++ ){
            num[i][j] = 0;
        }
    }
    for( int i = 0; i < time; i++ ){
        int row, col;
        scanf("%d %d %d", &row, &col, &val);
        num[row][col] = val;
    }
    for( int i = 0; i < _row; i++ ){
        for( int j = 0; j < _col; j++ ){
            printf("%d ", num[i][j]);
        }
        printf("\n");
    }
    return 0;
}
