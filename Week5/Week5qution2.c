#include <stdio.h>
////////  Problem ///////////
////     UVA-11321      /////
/////////////////////////////
int main(){
    int time = 0;
    scanf("%d", &time);
    while( time > 0 ){
        int size;
        scanf("%d", &size);
        int num[size];
        int test = 0;
        for( int i = 0; i < size; i++ ){
            scanf("%d", &num[i]);
        }
        for( int i = 1; i < size; i++ ){
            int current = num[i];
            int j = i - 1;
            while( j >= 0 && num[j] > current ){
                num[j + 1] = num[j];
                j--;
                test++;
            }
            num[j + 1] = current;  
        }
        printf("Optimal train swapping takes %d swaps.\n", test);
        time--;
    }
    return 0;
}
//  1 2 3 5 3  c = 1
//       i 
//
