#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int size_of_arr = 0;
    double mu = 0, average_de = 0;
    scanf("%d", &size_of_arr); 
    int *arr = malloc(sizeof(int) * (size_of_arr + 1));
    if( arr == NULL ){
        return 0;
    }//生成陣列
    for( int i = 0; i < size_of_arr; i++ ){
        scanf("%d", &arr[i]);
        mu += arr[i];
    }//總和

    mu /= size_of_arr;
    for( int i = 0; i< size_of_arr; i++ ){
        average_de += pow((arr[i] - mu),2);
    }
    average_de = pow((average_de / size_of_arr),0.5);
    //計算答案
    printf("%.2lf", average_de);
    free(arr);
    return 0;
}