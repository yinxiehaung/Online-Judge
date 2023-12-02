#include <stdio.h>
#include <stdlib.h>

int main(){
    int size_of_arr;
    scanf("%d", &size_of_arr); //輸入陣列大小
    int *arr = malloc( sizeof(int) * (size_of_arr + 1)), count = 0;
    if( arr == NULL ){
        printf("arr is not alloc");
        return 0;
    }
    float average = 0; //平均數有可能是小數
    for( int i = 0; i < size_of_arr; i++ ){
        scanf("%d", &arr[i] );
        average += arr[i];
    }//求總和

    average /= size_of_arr;
    for( int i = 0; i < size_of_arr; i++ ){
        if( arr[i] < average ){
            count++;
        }
    }//求人數
    printf("%d", count);
    free(arr);
    return 0;
}