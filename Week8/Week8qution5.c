#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INBORAD(y,x) (x) < 19 && (y) < 19 && (x) >= 0 && (y) >= 0
int Direction[8][2] = {{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};


int main(){
    char board[19][20];
    for( int i = 0; i < 19; i++ ){
        scanf("%s", board[i]);
    }
    for( int i = 0; i < 19; i++ ){
        for( int j = 0; j < 19; j++ ){
            if(board[i][j] == 'O'){
                for( int k = 0; k < 8; k++ ){
                    int x = j + Direction[k][1], y = i + Direction[k][0], time = 4;
                    while( abs(x - j) <= 4 && abs(y - i) <= 4){
                        if( INBORAD(y,x) && board[y][x] == 'O'){
                            time--;
                        }          
                        x += Direction[k][1];
                        y += Direction[k][0];
                    }
                    if(time == 0 ){
                        printf("White\n");
                        return 0;
                    }
                }
            }else if( board[i][j] == 'X'){
                for( int k = 0; k < 8; k++ ){
                    int x = j + Direction[k][1], y = i + Direction[k][0], time = 4;
                    while( abs(x - j) <= 4 && abs(y - i) <= 4){
                        if( INBORAD(y,x) && board[y][x] == 'X'){
                            time--;
                        }          
                        x += Direction[k][1];
                        y += Direction[k][0];
                    }
                    if(time == 0 ){
                        printf("Black\n");
                        return 0;
                    }
                }
            }
        }
    }
    printf("No winner\n");
}