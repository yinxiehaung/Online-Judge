#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX(x,y) (x) > (y) ? (x):(y)
#define SQUARE(x,y) ({pow((double)abs(x - y),2);})
#define DISTANCE(x,y)({sqrt(SQUARE(x[0],y[0]) + SQUARE(x[1],y[1]));})


int compare ( const void *pa, const void *pb ) {
    const int *a = *(const int **)pa;
    const int *b = *(const int **)pb;
    return a[0] - b[0];
}


int main(){
    int time = 0;
    scanf("%d",&time);
    for( int i = 0; i < time; i++ ){
        int size = 0;
        scanf("%d", &size);
        int **arr = (int **)malloc(size * sizeof(int*));
        for( int i = 0; i < size; i++ ){
            arr[i] = malloc(2 * sizeof(int));
            scanf("%d %d", &arr[i][0], &arr[i][1]);
        }
        qsort(arr, size, sizeof(arr[0]), compare);
        double ans = 0;
        int i = size - 2, k = 0;
    
        while( i >= 0){
            k = MAX(k, arr[i + 1][1]);
            if( arr[i][1] > k ){
                double distance = DISTANCE(arr[i], arr[i + 1]);
                ans += distance * (arr[i][1] - k)/(arr[i][1] - arr[i + 1][1]);
                /*取幾分之幾的距離
                    arr[i][1]
                        \*
                         \*_____ k
                          \
                           \
                           arr[i + 1][1]
                    distance(*) = distance * 1/2 = (arr[i][1] - k)/(arr[i][1] - arr[i + 1][1])
                */
            }
            i--;
        }
        printf("%.2lf\n", ans);
        free(arr);
    }
    return 0;
}