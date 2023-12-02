#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, index = 0;
    int nums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; 
    char *roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL","X","IX", "V", "IV","I"}; 
    scanf("%d", &num);
    while( index < 13 ){
        while( num >= nums[index]){
            printf("%s", roman[index]);
            num -= nums[index];
        }
        index++;
    }
    return 0;
}