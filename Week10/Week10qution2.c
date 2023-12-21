#include <stdio.h>
#include <stdlib.h>

#define m(x1,x2,y1,y2) (x1 - x2)/(y1 - y2)

typedef struct {
  float x, y;
} Point;

typedef struct {
  Point point;
  float slope;
} Line;


int main(){
    Line l;
    Point p;
    scanf("%f, %f, %f", &l.point.x, &l.point.y, &l.slope);
    scanf("%f, %f", &p.x, &p.y);
    if((m(p.x,l.point.x,p.y,l.point.y)) == l.slope ){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}