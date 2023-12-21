#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*#define MAX(x,y) ({typeof(x) _x = x;\
		   typeof(y) _y = y;\
		   _x >= _y?_x:_y;})
*/
int MAX( int a , int b ){
    return a > b? a:b;
}
typedef struct {
    char integer[1000];
    char decimal[1000];
} DeciVar;


int main(){
    DeciVar var1, var2, sum;
    memset(var1.integer,0,1000);
    memset(var1.decimal,0,1000);
    memset(var2.integer,0,1000);
    memset(var2.decimal,0,1000);
    scanf("%999[^.]%*c%999s%*c",var1.integer, var1.decimal);
    scanf("%999[^.]%*c%999s%*C",var2.integer, var2.decimal); 
    int c = 0, len = MAX(strlen(var1.decimal), strlen(var2.decimal)), i;
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
