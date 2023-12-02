#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main(){
    char str[10000];
    while(fgets(str, sizeof(str), stdin) != NULL){
        int con = 1;
        
        for( int i = 0; i < strlen(str); i++ ){ 
            if( islower(str[i]) && con ){
                str[i] = toupper(str[i]);
                con = 0;
            }else if( isupper(str[i]) || isdigit(str[i]) ){
                con = 0;
            }
            if( str[i] == '.' ){
                con = 1;
            }
        }
        printf("%s", str);
    }
    return 0;
}