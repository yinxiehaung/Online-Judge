#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define True 1==1


int main(){ 
    char arr[1000][1000];
    int con[1000], count = 0;
    while(True){ //無窮迴圈
        int even = 0, odd = 0, size_of_num = 0;
        char num[1000]; //字串陣列存取輸入資料
        scanf("%s", &num );
        if( num[0] == '0' ){
            break;
        }
        size_of_num = strlen(num); //取得長度
        int i = 0;
        
        while(i < size_of_num){
            if( (i+1) % 2 != 0 ){
                odd += (int)num[i]-48;//轉化為數字
            }else{
                even += (int)num[i] - 48;
            }
            i++;
        }
    
        
        if( odd - even == 0 || (odd - even) % 11 == 0 ){
            strcpy( arr[count], num); //複製字串
            con[count] = 1; //標記是否為11的倍數
            count++;
        }else{
            strcpy( arr[count], num);
            con[count] = 0;
            count++;
        }
    }
    for( int i = 0; i< count; i++ ){
        if( con[i] ){
            printf("%s is a multiple of 11.\n", arr[i]);
        }else{
            printf("%s is not a multiple of 11.\n", arr[i]);
        }
    }
    return 0;
}