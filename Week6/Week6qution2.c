#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, bin[32] = {}, j = 0;
    scanf("%d", &num);
    while( num > 0 ){
        bin[j] = num % 2;
        num /= 2;
        j++;
    }
    j--;
    for( int i = j; i >= 0; i-- ){
        printf("%d", bin[i]);
    }
    return 0;
}