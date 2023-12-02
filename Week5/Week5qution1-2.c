#include <stdlib.h>
#include <stdio.h>
int mod = 0;
////////  Problem ///////////
////     UVA-11321      /////
/////////////////////////////
int compare( const void *arg1, const void *arg2 ){
    int a = *(int *)arg1,b = *(int *)arg2;
    if( a % mod != b % mod ){
        return ( a % mod ) - ( b % mod ); 
    }else if( abs(a % 2) != abs(b % 2)){
        return abs(a % 2) ? -1:1;
    }else if( abs( a % 2) ){
        return a > b ? -1:1;
    }else{
        return a > b ? 1:-1;
    }
}

int main(){
    int time = 0, size;
    scanf("%d %d", &size, &mod);
    while( size != 0 && mod != 0){
        int numArr[size];
        for( int i = 0; i < size; i++ ){
            scanf("%d", &numArr[i]);
        }
        qsort( (void *)numArr, size, sizeof(int), compare );
        printf("%d %d\n", size, mod);
        for( int i = 0; i < size; i++){
            printf("%d\n", numArr[i]);
        }
        scanf("%d %d", &size, &mod);
    }
    printf("0 0\n");
    return 0;
}
