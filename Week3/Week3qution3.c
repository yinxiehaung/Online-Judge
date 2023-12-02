#include <stdio.h>
#include <math.h>

int main(){

    int distance;
    float profit;
    scanf("%d", &distance);
    
    if( distance > 200 ){
        profit = (distance - 200) * 1.2 * 0.75 + 200 * 1.2;
    }else{
        profit = distance * 1.2;
    }


    printf("%d", (int)roundf(profit));
    return 0;
}