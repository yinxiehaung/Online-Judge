#include <stdio.h>
#include <stdlib.h>

int compare( const void *arg1, const void *arg2 ){
    return *(int *)arg1 - *(int *)arg2;
}
//the code is not wirte by me but I forget the refers.
int main(){
    int size; 
    while (scanf("%d", &size) != EOF){
        int arr[size];

        for (int i = 0; i < size; i++){ 
            scanf("%d", &arr[i]);
        }

        qsort((void *)arr, size, sizeof(int), compare);

        // find the minimum median in the sequence
        int minMedian = 0;
        int maxMedian = 0;
        if (size % 2 == 0){ // if n is even, the median of num is num[n/2] and num[(n/2)-1]
            minMedian = arr[(size/2)-1];
            maxMedian = arr[size/2];
        } else { // if n is odd, the median of num is num[n/2]
            minMedian = arr[size/2];
            maxMedian = arr[size/2];
        }

        // find the amount of number equal to the median in the sequence
        int count = 0;
        for (int i = 0; i < size; i++){
            if (arr[i] == minMedian || arr[i] == maxMedian){
                count++;
            }
        }

        // find the amount of possible different integer can be the median of sequence
        int possibleMedian = 0;
        if (size % 2 == 0){
            possibleMedian = maxMedian - minMedian + 1; // the amount between two medians
        } else {
            possibleMedian = 1;
        }
        
        printf("%d %d %d\n",minMedian, count, possibleMedian);
    }
    return 0;
}
