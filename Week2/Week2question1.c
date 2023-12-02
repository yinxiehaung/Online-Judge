#include <stdio.h>
#include <math.h>

int main(){
    float a;
    scanf("%f", &a);
    float b = a * 1000;
    int tmp = (int)b;
    if( tmp % 10 < 5){
        printf("%1.2f\n", ((float)(tmp - (tmp%10)))/1000);
    } 
    else{
        printf("%1.2f\n", ((float)(tmp + 10 - (tmp%10)))/ 1000);
    }
    printf("%.2f\n",(float)(tmp - (tmp %10))/1000);
    return 0;
}