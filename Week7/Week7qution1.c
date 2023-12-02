#include <stdio.h>

int main(){
    int i, j;
    while(scanf("%d %d", &i, &j) != EOF){
        int max = 0;
        printf("%d %d", i, j);
        if( i > j ){
            i ^= j;
            j ^= i;
            i ^= j;
        }
        for(int k = 0; k <= j-i; k++ ){
            int time_cycle = 1;
            int num = i + k;
            while( num != 1 ){
                if( num & 1 ){
                    num = 3 * num + 1;
                }else{
                    num = num >> 1;
                }
                time_cycle++;
            }        
            if( time_cycle > max ){
                max = time_cycle;
            } 
        }
        printf(" %d\n", max);
    }
    return 0;
}