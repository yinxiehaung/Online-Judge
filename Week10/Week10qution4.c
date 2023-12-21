#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int neightbros(char **current, int row, int col, int x, int y){
    int Dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1},{1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    int count = 0;
    for( int i = 0; i < 8 && count < 4; i++ ){
        int tmp_x = x + Dir[i][1];
        int tmp_y = y + Dir[i][0];
        if( tmp_x >= 0 && tmp_y >= 0 && tmp_x < col && tmp_y < row && (current[tmp_y][tmp_x] == '1')){
            count++;
        }
    }
    return count;
}


int main(){
    int time = 0, Line = 0;
    char **current = malloc(Line * sizeof(char*)), str[100];
    scanf("%d", &time);
    while( scanf("%s", str) != EOF ){
        char ** temp = (char **)realloc(current ,(++Line) * sizeof(char *));
        if( !temp ){
            for( int i = 0; i < Line; i++ ){
                free(current[i]);
            }
            free(current);
            return 1;
        }
        current = temp;
        current[Line - 1] = (char *)malloc(strlen(str) + 1);
        strcpy(current[Line - 1],str);
    }
    char **next = malloc( Line * sizeof(char *));
    for( int i = 0; i < Line; i++ ){
        next[i] = malloc( strlen(str) + 1);
    }
    while( time ){
        for( int i = 0; i < Line; i++ ){
            for( int  j = 0; j < strlen(str); j++ ){
                switch(neightbros(current, Line, strlen(str), j, i)){
                    case 0:case 1:case 4:
                        next[i][j] = '0';
                        break;
                    case 2:
                        next[i][j] = current[i][j];
                        break;
                    case 3:
                        next[i][j] = '1';
                        break;
                }
            }
        }
        for( int i = 0; i < Line; i++ ){
            strcpy(current[i], next[i]);
            memset(next[i], '0', strlen(str));
        }
        time--;
    }

    for (int i = 0; i < Line; i++) {
        printf("%s\n", current[i]);
        free(current[i]);  // 釋放每個字串的記憶體
        free(next[i]);
    }
    free(current);
    free(next);
    return 0;
}