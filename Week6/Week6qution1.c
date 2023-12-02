#include <stdio.h>
#include <stdlib.h>

int is_prime( int n ){
    if( n == 1 ){
        return 0;
    }else{
        for( int i = 2; i * i <= n; i += 2){
            if( n % i == 0 ){
                return 0;
            }
        }
    }
    return 1;
}


int compare( const void *arg1, const void *arg2 ){
    int num1 = *(int *)arg1, num2 = *(int *)arg2;
    if( is_prime(num1) && !(is_prime(num2)) ){
        return -1;   //num1 num2
    }else if( !(is_prime(num1)) && is_prime(num2) ){
        return 1;   // num2 num1
    }else if( is_prime(num1) && is_prime(num2) ){
        return num2 - num1;
    }else{
        return num1 - num2;
    }
}
int main(){
    int size = 0;
    scanf("%d", &size);
    int num[size];
    for( int i = 0; i < size; i++ ){
        scanf("%d", &num[i]);
    }
    qsort((void *)num, size, sizeof(int), compare);
    for( int i = 0; i < size; i++ ){
        printf("%d ", num[i]);
    }
    return 0;
}