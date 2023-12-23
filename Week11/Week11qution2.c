#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

char *convertToDifferentBase(int dec, int base, char *result) {
    char *baseSymble = "0123456789ABCDEFGGIJKLMNOPQRSTUVWXYZ";
    int digits = (int)(log(dec) / log(base)) + 1;
    result = (char *)malloc((digits + 1) * sizeof(char));
    int i = 0;
    while (dec) {
        result[i++] = baseSymble[dec % base];
        dec /= base;
    }


    result[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        char temp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = temp;
    }

    return result;
}

int main() {
    int dec = 16;
    int base = 2;
    char *result = convertToDifferentBase(dec, base, result);
    printf("%s\n", result);
    free(result);
    return 0;
}
