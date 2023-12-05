#include <stdio.h>

int main() {
    int hight, width;
    scanf("%d %d", &hight, &width);
    int arr[hight][width], top = 0, left = 0, right = width - 1, bottom = hight - 1;
    for( int i = 0; i < hight; i++ ){
        for( int j = 0; j < width; j++ ){
            scanf("%d", &arr[i][j]);
        }
    }
    while( left <= right && top <= bottom ){
        for( int i = left; i <= right; i++ ){
            printf("%d ", arr[top][i]);
        }
        top++;
        for( int i = top; i <= bottom; i++ ){
            printf("%d ", arr[i][right]);
        }
        right--;

        if( top <= bottom ){
            for( int i = right; i >= left; i-- ){
                printf("%d ", arr[bottom][i]);
            }
        }
        bottom--;
        if( left <= right ){
            for( int i = bottom; i >= top; i-- ){
                printf("%d ", arr[i][left]);
            }
        }
        left++;
    }
    return 0;
}