#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*#define MAX(x,y) ({typeof(x) _x = x;\
		   typeof(y) _y = y;\
		   _x >= _y?_x:_y;})
*/
int MAX( int a, int b ){
    return a > b? a:b;
}

int MIN( int a, int b){
    return a > b? b:a;
}
typedef struct {
    char integer[1000];
    char decimal[1000];
} DeciVar;


int main(){
    DeciVar var1, var2, sum;
    memset(sum.integer, '\0', 1000);
    memset(sum.decimal, '\0', 1000);
    memset(var1.integer, '\0', 1000);
    memset(var2.integer, '\0', 1000);
    memset(var1.decimal, '\0', 1000);
    memset(var2.decimal, '\0', 1000);
    char temp[2000];
    scanf("%s", temp);
    bool havedec = false;
    int i = 0, j = 0;
    for( ;i <= strlen(temp); i++ ){
        if( temp[i] == '.' ){
            havedec = true;
            break;
        }
    }
    i = havedec ? i:i-1;
    for(;j <= i; j++ ){
        var1.integer[j] = temp[j];
    }
    var1.integer[j - 1] = '\0';
    for(j = 1; j < strlen(temp) - i && havedec; j++ ){
        var1.decimal[j - 1] = temp[i + j];
    }
    var1.decimal[j - 1] = '\0';
    scanf("%s", temp);
    i = 0;j = 0;havedec = false;
    for( ;i <= strlen(temp); i++ ){
        if( temp[i] == '.' ){
            havedec = true;
            break;
        }
    }
    i = havedec?i:i-1;
    for(;j <= i; j++ ){
        var2.integer[j] = temp[j];
    }
    var2.integer[j - 1] = '\0';
    for(j = 1; j < strlen(temp) - i && havedec; j++ ){
        var2.decimal[j - 1] = temp[i + j];
    }
    var2.decimal[j - 1] = '\0';
    int c = 0, len = MAX(strlen(var1.decimal), strlen(var2.decimal));
    bool print_dec = false;
    for(i = 0; i < len; i++ ){
        int x = var1.decimal[len - i - 1] != 0?var1.decimal[len - i - 1] - '0':0;
        int y = var2.decimal[len - i - 1] != 0?var2.decimal[len - i - 1] - '0':0;
        sum.decimal[i] = ((x + y + c)%10) + '0';
        c = (x + y + c)/10; 
    }
    sum.decimal[i] = '\0';
    len = MAX(strlen(var1.integer), strlen(var2.integer));
    for(i = 0; i < len; i++ ){
        int x = var1.integer[strlen(var1.integer) - i - 1] != 0?var1.integer[strlen(var1.integer) - i - 1] - '0':0;
        int y = var2.integer[strlen(var2.integer) - i - 1] != 0?var2.integer[strlen(var2.integer) - i - 1] - '0':0;
        sum.integer[i] = ((x + y + c)%10) + '0';
        c = ( x + y + c )/10;
    }
    if(c){
        sum.integer[i] = '1';
        i++;
    }
    sum.integer[i] = '\0';
    for(i = strlen(sum.integer); i >= 0; i-- ){
        printf("%c", sum.integer[i]);
    }
    for(i = 0; i < strlen(sum.decimal); i++ ){
        if(sum.decimal[i] >'0' ){
            print_dec = true;            
            break;
        }
    }
    if(print_dec){
        printf(".");
        for(int j = strlen(sum.decimal); j >= i; j-- ){
            printf("%c", sum.decimal[j]);
        }
    }
    return 0;
}