#include <stdio.h>
#include <stdlib.h>

int compare( const void *arg1, const void *arg2 ){
    return (*(int *)arg2 - *(int *)arg1); 
    //當 a == b return 0;
    //   a > b return >0;
    //   a < b return <0;
}

int main(){

    int size_of_arr = 0; //設定max與min為輸入資料的最大最小值
    scanf("%d", &size_of_arr);
    int *arr = malloc( sizeof( int ) * (size_of_arr + 1) ); // int arr[size_of_arr];

    for( int i = 0; i < size_of_arr; i++ ){
        scanf("%d", &arr[i]);
    } 

    qsort((void *)arr, size_of_arr, sizeof(int), compare); //排列 由小到大
    float average = 0;
    int count = 0;
    for( int i = 3; i < size_of_arr - 3; i++ ){
        average += arr[i]; //求總和
        count++; //計算總數
    }

    average /= count;
    printf("%.2f",average); 

    free(arr);
    return 0;
}