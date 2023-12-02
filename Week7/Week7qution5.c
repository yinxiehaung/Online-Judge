#include <stdio.h>
#include <limits.h>

#define MAX(x,y) (x) > (y)?(x):(y)
#define MIN(x,y) (x) < (y)?(x):(y)


int main(){
    int Li, Hi, Ri, ans[10001] = {0};
    int max_Ri = INT_MIN, min_Li = INT_MAX;
    while( scanf("%d %d %d", &Li, &Hi, &Ri) != EOF ){
        min_Li = MIN(min_Li, Li);
        max_Ri = MAX(max_Ri, Ri);
        for( int i = Li ; i < Ri; i++ ){
            if( Hi > ans[i] ){
                ans[i] = Hi;
            }
        }
    }
    int tmp = 0;
    for( int i = min_Li; i <= max_Ri; i++ ){
        if( tmp != ans[i]){
            printf("%d %d ", i, ans[i]);
            tmp = ans[i];
        }
    }
    return 0;
}