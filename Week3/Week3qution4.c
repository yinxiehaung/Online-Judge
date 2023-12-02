#include <stdio.h>

int main(){
    int num1, num2, num3, num4;
    
    scanf("%1d%1d%1d%1d",&num1, &num2, &num3, &num4);

    if(num1 == 4 || num2 == 4 || num3 == 4 || num4 == 4){
        printf("Yes");
    }else{
        printf("No");
    }

    return 0;
}