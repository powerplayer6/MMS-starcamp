#include <stdio.h>
#define PI 3.14
#define SUM(x,y) (x+y)
#define MULT(x,y) (x*y)
#define FORI(start, end, step) for(int i=start; i<=end; i+=step)

int main()
{
    double r = 10;
    double S = PI * r * r;
    printf("%d\n", SUM(1,3));
    printf("%d\n", MULT(5,3));
    FORI(1, 100, 2){
        printf("%d", i);
    }
    return 0;
}