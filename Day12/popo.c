#include <stdio.h>


void funca(int **b)
{
    **b=1000;
    printf("%d\n", **b);
}

int main()
{
    int a = 10;
    int *p=&a;
    int **ptp=&p;
    printf("%d\n", a);
    funca(ptp);
    printf("%d\n", a);
    return 0;
}