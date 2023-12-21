#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char studentID[20], programming, programmingLab, calculus;
}Student;

int compare( const void *arg1, const void *arg2 ){
    int sum1 = (*(Student *)arg1).programming + (*(Student *)arg1).programmingLab + (*(Student *)arg1).calculus;
    int sum2 = (*(Student *)arg2).programming + (*(Student *)arg2).programmingLab + (*(Student *)arg2).calculus;
    return sum1 - sum2;
}


int main(){
    int size;
    scanf("%d", &size);
    Student *Students = (Student *)malloc( sizeof(Student) * size);
    for( int i = 0; i < size; i++ ){
        scanf("%s", Students[i].studentID);
        scanf("%hhd", &Students[i].programming);
        scanf("%hhd", &Students[i].programmingLab);
        scanf("%hhd", &Students[i].calculus);
    }
    qsort((void *)Students, size, sizeof(Student), compare);
    for( int i = size-1; i > size - 4; i-- ){
        printf("%s\n", Students[i].studentID );
    }
    return 0;
}