#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main() {
  init();
  char *str = "str";
  double sum = 0;
  int count = 0;
  while( *str ){
    if( isdigit(*str) ){
        count++;
    }else{
        for(; count > 0; count-- ){
            sum += ((str[-count] - '0') *(pow(10, count-1)));
        }
    }
    str++;
  }
  for(; count > 0; count-- ){
    sum += ((str[-count] - '0') * (pow(10, count - 1)));
  }
  printf("%d",(int)sum);
  return 0;
}