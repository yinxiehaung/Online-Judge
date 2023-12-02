#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// 類似的題目:https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
/*int strn( char *str, char c ){
    int i = 0, count_of_c = 0;
    while( *(str + i) ){
        if( *(str + i) == c ){
            count_of_c++;
        }
        i++;
    }
    return count_of_c;
}*/

int isReapting( char *str ){
    bool ascii[128] = {false};
    for( int i = 0; i < strlen(str); i++ ){
        if( ascii[str[i]] ){
            return true;
        }
        ascii[str[i]] = true;
    }
    return false;
}

int main(){
    char str[10000], str2[10000];
    int max_i = 0, max_j = 0;
    scanf("%s", str);
    
    for( int i = 0; i < strlen(str); i++ ){
        for( int j = 1; j + i <= strlen(str); j++ ){
            strncpy( str2, str + i, j);
            str2[j] = 0;
            if( !isReapting(str2) && j > max_j ){
                max_j = j;
                max_i = i;
            }
        }
    }
    strncpy(str2, str+max_i, max_j);
    printf("%s", str2);
    return 0;
}
