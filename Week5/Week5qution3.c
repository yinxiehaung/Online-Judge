#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char str[1000];

int strn( const char *str1, const char c ){
    int count = 0, i = 0;
    while( str[i] ){
        if( str[i] == c){
            count++;
        }
        i++;
    }
    return count;
}

int compare( const void *arg1, const void *arg2 ){
    int arg1_count = strn( str, *(char *)arg1 );
    int arg2_count = strn( str, *(char *)arg2 ); 
    if( arg1_count != arg2_count ){
        return arg1_count - arg2_count;
    }else{
        return *(char *)arg2 - *(char *)arg1;
    }
}


int main(){
    int ln = 0;
    while( gets(str) ){
        qsort((void *)str,  strlen(str), sizeof(char), compare);
        int tmp = 0;
        if( ln ){
            printf("\n");
        }
        for( int i = 0; i < strlen(str); i++ ){
            if( tmp != str[i] && str[i] >= 32 && str[i] < 128){
                printf("%d %d\n", str[i], strn(str,str[i]));
                tmp = str[i];
            }
        }
        str[0] = '\0';
        ln = 1;
    }
    return 0;
}