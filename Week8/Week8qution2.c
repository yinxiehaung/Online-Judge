#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INMAZE(x,y,hight,width) (x) < (width) && (y) < (hight) && (x) >= 0 && (y) >= 0

bool is_trafficable( int **maze, int hight, int width, int x, int y ){
    if( x == hight - 1 && y == width -1 && maze[y][x] == 0){
        return true;
    }
    if( INMAZE(x,y,hight,width) && maze[y][x] == 0 ){
        maze[y][x] = 1;
        return is_trafficable( maze, hight, width, x + 1, y ) || is_trafficable( maze, hight, width, x - 1, y) ||\
        is_trafficable( maze, hight, width, x, y + 1 ) || is_trafficable( maze, hight, width, x, y - 1);
    }
    return false;
}

int main(){
    int size;
    scanf("%d", &size);
    int **maze = (int **)malloc(sizeof(int*) * size);

    for( int i = 0; i < size; i++ ){
        maze[i] = (int *)malloc( sizeof(int) * size);
        for( int j = 0; j < size; j++ ){
            scanf("%d", &maze[i][j]);
        } 
    }
    if( is_trafficable( maze, size, size, 0, 0 ) ){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}