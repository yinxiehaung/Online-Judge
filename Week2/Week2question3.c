#include <stdio.h>

int main(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if( a > b){
        int tmp = b;
        b = a;
        a = tmp;
    }
    if(c > d){
        int tmp = d;
        d = c;
        c = tmp;
    }

    if(a <= c && c < b || a <= d && d < b || c <= a && a < d || c <= b && b < d){
        printf("overlay");
        return 0;       
    }
    printf("no overlay");
    return 0;
}
//4 5 1 3