#include <stdio.h>

int main(){
    int m, n;
    scanf("%d %d",m, n);
    int courses[m][3], scores[n][2];
    for( int i = 0; i < m; i++ ){
        scanf("%d %d %d", courses[i][0], courses[i][1], courses[i][2]);
    }
    printf("%d ", m);
    for( int i = 0; i < n; i++ ){
        scanf("%d %d", scores[i][0], scores[i][1]);
    }
    
    return 0;
}