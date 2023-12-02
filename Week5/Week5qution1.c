#include <stdio.h>
#include <math.h>
int _mod = 0;
int size = 0;
////////  Problem ///////////
////     UVA-11321      /////
/////////////////////////////
/*
    Below is a example, We have store odd numbers array:odd[] and
    even numbers array:even[].
    even[5] = { 2, 6, 4, 8, 10};
    odd[5] = {7, 5, 3, 9};
    Step 1: Sort in descending order of odd array and even array in ascending order.
        even[5] = {10, 8, 6, 4, 2};
        odd[5] = {3, 5, 7, 9};
    Step 2: Sort in descending order on the mod operation.
        let MOD = 3;
        even[5] = {0,10,4,8,2};
        odd[5] = {3,9,7,5};
    Step 3:
        Since the range of mod numbers is -mod+1 to mod-1, use a for loop to print the answer.
    So, We have completed the problem.
*/
int main(){
    scanf("%d %d", &size, &_mod);
    while( size != 0 && _mod != 0){
        int number, odd[size], even[size], count_odd = 0, count_even = 0;
        for( int i = 0; i < size; i++ ){
            scanf("%d", &number);
            if( number % 2 ){
                odd[count_odd] = number;
                count_odd++;
            }else{
                even[count_even] = number;
                count_even++;
            }
        }

        for( int i = 1; i < count_odd; i++ ){
            int current = odd[i];
            int j = i - 1;
            while( j >= 0 && odd[j] < current ){
                odd[j + 1] = odd[j];
                j--;
            }
            odd[j + 1] = current;  
        }

        for( int i = 1; i < count_odd; i++ ){
            int current = odd[i];
            int j = i - 1;
            while( j >= 0 && (odd[j] % _mod) > (current % _mod) ){
                odd[j + 1] = odd[j];
                j--;
            }
            odd[j + 1] = current;  
        }

        for( int i = 1; i < count_even; i++ ){
            int current = even[i];
            int j = i - 1;
            while( j >= 0 && even[j] > current ){
                even[j + 1] = even[j];
                j--;
            }
            even[j + 1] = current;  
        }
        
        for( int i = 1; i < count_even; i++ ){
            int current = even[i];
            int j = i - 1;
            while( j >= 0 && (even[j] % _mod) > (current % _mod) ){
                even[j + 1] = even[j];
                j--;
            }
            even[j + 1] = current;  
        }
        printf("%d %d\n", size, _mod);
        for( int i = 0 - _mod + 1; i < _mod ; i++){
            for( int j = 0; j < count_odd; j++ ){
                if( odd[j] % _mod == i ){
                    printf("%d\n", odd[j]);
                }
            }
            for( int k = 0; k < count_even; k++ ){
                if( even[k] % _mod == i){
                    printf("%d\n", even[k]);
                }
            }
        }
        scanf("%d %d", &size, &_mod);
    }
    printf("0 0\n");
    return 0;
}
