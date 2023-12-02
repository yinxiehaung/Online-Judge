#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int num;
    scanf("%d", &num);
    for(int i = (int)log2(abs(num)); i >= 0; i-- ){
        printf("%d", (num >>  i) & 1);
    }
    return 0;
}