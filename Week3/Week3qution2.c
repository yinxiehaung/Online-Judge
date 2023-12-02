#include <stdio.h>

int main(){
    int num1, num2, num3, num4, max = 0;

    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    if( num1 > max ){ 
        max = num1;
    }
    if( num2 > max ){
        max = num2;
    }
    if( num3 > max ){
        max = num3;
    }
    if( num4 > max ){
        max = num4;
    }

    printf("%d", max);
    return 0;
}