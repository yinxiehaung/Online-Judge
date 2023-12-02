#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int main(){
    char str[10000], str2[10000];
    int max_i = 0, max_j = 0;
   
    scanf("%s", str);
    int max_len = 0;
    for( int i = 0; str[i] != 0; i++ ){
        int j = i, len = 0;
        bool ascii[127] = {false};
        for( ; str[j] != 0; j++ ){
            if( ascii[str[j]] == false ){
                len++;
                ascii[str[j]] = true;
            }else{     
                break;
            }
        }
        if( len > max_len ){
            max_i = i;
            max_j = j;
            max_len = len;
        }
    }
    strncpy( str2, str + max_i, max_len );
    str2[max_j] = 0;
    printf("%s\n", str2 );
    return 0;
}